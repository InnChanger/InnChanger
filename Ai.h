npm init -y
npm install express multer axiosconst express = require('express');
const multer = require('multer');
const axios = require('axios');
const path = require('path');

const app = express();
const port = 5000;

// Setup multer to handle photo uploads
const upload = multer({ dest: 'uploads/' });

// Endpoint to handle AI video generation
app.post('/generate-video', upload.single('photo'), async (req, res) => {
  try {
    const { prompt } = req.body;
    const photoPath = req.file.path;

    if (!prompt || !req.file) {
      return res.status(400).send("Photo and prompt are required!");
    }

    // Simulate AI video generation (connect to your AI API here)
    // Example of calling an external API
    const aiResponse = await axios.post('https://api.example.com/generate', {
      photo: photoPath,
      prompt: prompt
    });

    const videoUrl = aiResponse.data.videoUrl;  // Assuming the AI API gives the video URL.

    res.json({ videoUrl });
  } catch (error) {
    res.status(500).send("Error generating video: " + error.message);
  }
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});<section id="ai-generator">
  <h2>Create Your Video with AI</h2>
  <form id="ai-form">
    <label for="photo-upload">Upload Your Photo:</label>
    <input type="file" id="photo-upload" accept="image/*" required />
    
    <label for="ai-prompt">Enter a Prompt (e.g., "Sci-fi scene with a robot and spaceship"):</label>
    <textarea id="ai-prompt" placeholder="Describe your video" required></textarea>
    
    <button type="submit" id="generate-btn">Generate Video</button>
  </form>
  
  <div id="loading" style="display: none;">
    <p>Processing your video...</p>
  </div>
  
  <div id="result" style="display: none;">
    <h3>Your Generated Video</h3>
    <video id="generated-video" controls></video>
  </div>
</section>

<script>
  document.getElementById('ai-form').addEventListener('submit', function(event) {
    event.preventDefault(); // Prevent default form submission
    
    const photo = document.getElementById('photo-upload').files[0];
    const prompt = document.getElementById('ai-prompt').value;
    
    if (!photo || !prompt) {
      alert("Please upload a photo and provide a prompt.");
      return;
    }

    // Create FormData object to send file and prompt
    const formData = new FormData();
    formData.append('photo', photo);
    formData.append('prompt', prompt);
    
    // Show loading message
    document.getElementById('loading').style.display = 'block';
    document.getElementById('generate-btn').disabled = true;
    
    // Send the data to the server
    fetch('/generate-video', {
      method: 'POST',
      body: formData
    })
    .then(response => response.json())
    .then(data => {
      // Hide loading message
      document.getElementById('loading').style.display = 'none';
      document.getElementById('generate-btn').disabled = false;

      // Display video URL
      if (data.videoUrl) {
        document.getElementById('result').style.display = 'block';
        document.getElementById('generated-video').src = data.videoUrl;
      } else {
        alert("Failed to generate video.");
      }
    })
    .catch(error => {
      console.error('Error:', error);
      document.getElementById('loading').style.display = 'none';
      alert("Error generating video.");
    });
  });
</script>
