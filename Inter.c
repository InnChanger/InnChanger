import { useState } from "react"; import { ClipboardCopy, Check, Video, Users, Bot, Settings } from "lucide-react";

export default function AIFilmHome() { const [copied, setCopied] = useState(false);

const handleCopy = async () => { try { await navigator.clipboard.writeText("https://innchanger.com/ai-film-studio"); setCopied(true); setTimeout(() => setCopied(false), 2000); } catch (err) { console.error("Copy failed", err); } };

return ( <main className="min-h-screen bg-gradient-to-br from-gray-950 to-black text-white p-6 md:p-12 font-sans"> <header className="text-center space-y-4"> <h1 className="text-4xl md:text-6xl font-bold">InnChanger AI Film Studio</h1> <p className="text-gray-400 md:text-lg"> Create pro-level films with AI: scripts, VFX, 3D characters, voiceovers, and more. </p> <button
onClick={handleCopy}
className="mt-4 flex items-center gap-2 bg-indigo-600 hover:bg-indigo-700 px-4 py-2 rounded-full text-sm md:text-base shadow-lg active:scale-95 transition"
> {copied ? <Check size={18} /> : <ClipboardCopy size={18} />} {copied ? "Copied!" : "Copy Studio Link"} </button> </header>

<section className="grid md:grid-cols-3 gap-6 mt-12">
    {[
      "AI Script Writing",
      "Voice FX & Sound Design",
      "Character & Alien Generator",
      "Fight Scene Choreography",
      "3D Environments & FX",
      "Auto-edit & Film Sync",
      "Upload Actor Image",
      "AI Voice Casting",
      "Scene Control & Director Mode"
    ].map((feature, index) => (
      <div
        key={index}
        className="bg-gray-900 rounded-2xl p-6 shadow-md hover:shadow-xl transition"
      >
        <h3 className="text-xl font-semibold mb-2">{feature}</h3>
        <p className="text-gray-400 text-sm">
          {feature === "AI Script Writing"
            ? "Write your full film scripts in seconds using prompt-based generation."
            : feature === "Voice FX & Sound Design"
            ? "Generate professional voiceovers and custom sounds with emotion-based AI."
            : feature === "Character & Alien Generator"
            ? "Create realistic or fantasy characters including aliens, robots, etc."
            : feature === "Fight Scene Choreography"
            ? "AI crafts cinematic battle scenes with action precision."
            : feature === "3D Environments & FX"
            ? "Build immersive worlds and cinematic effects in one click."
            : feature === "Auto-edit & Film Sync"
            ? "Auto-cut, color grade, sync audio & finalize film effortlessly."
            : feature === "Upload Actor Image"
            ? "Use your image to be cast as the main actor in your own film."
            : feature === "AI Voice Casting"
            ? "Choose or generate perfect voices for every character instantly."
            : "Take full control over your AI production with director tools."
          }
        </p>
      </div>
    ))}
  </section>

  <footer className="text-center mt-16 text-sm text-gray-600">
    &copy; 2025 InnChanger AI Platform. All rights reserved.
  </footer>
</main>

); }

￼Enter
