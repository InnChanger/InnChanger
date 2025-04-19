import React from 'react';

function Navbar() {
  return (
    <nav className="bg-black p-4">
      <div className="flex justify-between items-center">
        <a href="/" className="text-white text-2xl font-bold">InnChanger</a>
        <ul className="flex space-x-6">
          <li><a href="/" className="text-white">Home</a></li>
          <li><a href="/dashboard" className="text-white">Dashboard</a></li>
          <li><a href="/login" className="text-white">Login</a></li>
          <li><a href="/signup" className="text-white">Sign Up</a></li>
        </ul>
      </div>
    </nav>
  );
}

export default Navbar;
import React from 'react';

function Hero() {
  return (
    <div className="hero bg-blue-600 text-white p-12 text-center">
      <h1 className="text-4xl font-bold mb-4">Create the Future of Film with AI</h1>
      <p className="text-xl mb-6">Transform your filmmaking with advanced AI tools for all your needs.</p>
      <a href="/signup" className="bg-yellow-500 text-black py-2 px-6 rounded-full text-lg">Get Started</a>
    </div>
  );
}

export default Hero;
import React from 'react';

function Features() {
  return (
    <section className="features bg-gray-800 text-white py-12">
      <div className="container mx-auto text-center">
        <h2 className="text-3xl font-bold mb-8">Features</h2>
        <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
          <div className="feature bg-blue-600 p-8 rounded-lg">
            <h3 className="text-2xl font-semibold mb-4">AI Film Creation</h3>
            <p>Transform your ideas into films with AI-generated scripts, scenes, and special effects.</p>
          </div>
          <div className="feature bg-green-600 p-8 rounded-lg">
            <h3 className="text-2xl font-semibold mb-4">Voice AI</h3>
            <p>Generate voices for characters, narrations, and more with AI voice synthesis.</p>
          </div>
          <div className="feature bg-purple-600 p-8 rounded-lg">
            <h3 className="text-2xl font-semibold mb-4">Face Swap Technology</h3>
            <p>Swap faces in real-time with AI technology for realistic results in any film scene.</p>
          </div>
        </div>
      </div>
    </section>
  );
}

export default Features;
git add .
git commit -m "Add Navbar, Hero, and Features components"
git push origin main
