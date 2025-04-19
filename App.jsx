InnChanger/
│
├── public/                 # Assets (images, robots.txt, favicon)
│
├── src/
│   ├── components/         # Reusable components (Navbar, Footer, AI tools...)
│   ├── pages/              # Home, Dashboard, AI Tools, Download...
│   ├── features/           # FaceSwap, VoiceAI, 3D, FilmMaker, VFX
│   ├── auth/               # Login, Signup, 2FA
│   ├── layout/             # General layout components (MainLayout, AdminLayout)
│   ├── styles/             # Tailwind CSS or SCSS setup
│   └── utils/              # Security, session, helpers
│
├── .env                   # API keys, tokens
├── package.json           # Project dependencies
└── README.md              # Documentation￼Enter
import { BrowserRouter as Router, Routes, Route } from "react-router-dom"; import { Hero, Features, Footer, Navbar } from "./components"; import Dashboard from "./pages/Dashboard"; import Login from "./auth/Login"; import Signup from "./auth/Signup"; import FilmAI from "./features/FilmAI"; import VoiceAI from "./features/VoiceAI"; import FaceSwap from "./features/FaceSwap"; import Download from "./pages/Download";

export default function App() { return ( <Router> <div className="bg-black text-white min-h-screen"> <Navbar /> <Routes> <Route path="/" element={<> <Hero /> <Features /> </>} /> <Route path="/dashboard" element={<Dashboard />} /> <Route path="/ai/film" element={<FilmAI />} /> <Route path="/ai/voice" element={<VoiceAI />} /> <Route path="/ai/faceswap" element={<FaceSwap />} /> <Route path="/download" element={<Download />} /> <Route path="/login" element={<Login />} /> <Route path="/signup" element={<Signup />} /> </Routes> <Footer /> </div> </Router> ); }

