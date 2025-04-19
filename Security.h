// security-setup.js

// 1. Enable HTTPS for secure communication
const enforceHTTPS = (req, res, next) => {
  if (req.secure || req.headers['x-forwarded-proto'] === 'https') {
    return next();
  }
  res.redirect(`https://${req.headers.host}${req.url}`);
};

// 2. Set Secure Headers using Helmet (Node.js + Express recommended)
const helmet = require('helmet');
app.use(helmet({
  contentSecurityPolicy: {
    directives: {
      defaultSrc: ["'self'"],
      scriptSrc: ["'self'", "trusted-cdn.com"],
      styleSrc: ["'self'", "fonts.googleapis.com"],
      imgSrc: ["'self'", "data:"],
    }
  },
  referrerPolicy: { policy: "no-referrer" },
}));

// 3. XSS Protection Middleware
app.use((req, res, next) => {
  res.setHeader("X-XSS-Protection", "1; mode=block");
  next();
});

// 4. CSRF Protection Token
const csrf = require('csurf');
const csrfProtection = csrf({ cookie: true });
app.use(csrfProtection);

// 5. Authentication Middleware
const authenticate = (req, res, next) => {
  if (req.session && req.session.user) {
    return next();
  } else {
    res.status(403).json({ message: "Unauthorized Access" });
  }
};

// 6. Secure Robots.txt
app.get('/robots.txt', (req, res) => {
  res.type('text/plain');
  res.send("User-agent: *\nDisallow: /admin\n");
});

// 7. CORS Configuration
const cors = require('cors');
app.use(cors({
  origin: 'https://yourdomain.com',
  credentials: true
}));

// 8. Encrypt Session Cookies
app.use(session({
  secret: 'yourStrongSecretKey2025@!',
  resave: false,
  saveUninitialized: true,
  cookie: { secure: true, httpOnly: true }
}));

// 9. Two-Factor Authentication Setup (TOTP)
const speakeasy = require('speakeasy');
const QRCode = require('qrcode');

// Function to generate TOTP for 2FA
function generate2FA(user) {
  const secret = speakeasy.generateSecret({ name: `InnChanger AI (${user.email})` });
  QRCode.toDataURL(secret.otpauth_url, (err, dataURL) => {
    user.qrCode = dataURL;
    user.secret = secret.base32;
  });
}

// 10. CSP Meta Tag for HTML head
/*
<meta http-equiv="Content-Security-Policy" content="default-src 'self'; script-src 'self' https://trusted-cdn.com; style-src 'self' https://fonts.googleapis.com;">
*/

module.exports = {
  enforceHTTPS,
  helmet,
  authenticate,
  csrfProtection,
  generate2FA
};￼Enter<a href="https://yourdomain.com/security-setup.js" download="security-setup.js">
  <button style="padding: 10px 20px; border-radius: 8px; background-color: green; color: white;">
    Download Security Setup
  </button>
</a>// security-setup.js

// 1. Enable HTTPS for secure communication const enforceHTTPS = (req, res, next) => { if (req.secure || req.headers['x-forwarded-proto'] === 'https') { return next(); } res.redirect(https://${req.headers.host}${req.url}); };

// 2. Set Secure Headers using Helmet (Node.js + Express recommended) const helmet = require('helmet'); app.use(helmet({ contentSecurityPolicy: { directives: { defaultSrc: ["'self"], scriptSrc: ["'self"", "trusted-cdn.com"], styleSrc: ["'self"", "fonts.googleapis.com"], imgSrc: ["'self"", "data:"], } }, referrerPolicy: { policy: "no-referrer" }, }));

// 3. XSS Protection Middleware app.use((req, res, next) => { res.setHeader("X-XSS-Protection", "1; mode=block"); next(); });

// 4. CSRF Protection Token const csrf = require('csurf'); const csrfProtection = csrf({ cookie: true }); app.use(csrfProtection);

// 5. Authentication Middleware const authenticate = (req, res, next) => { if (req.session && req.session.user) { return next(); } else { res.status(403).json({ message: "Unauthorized Access" }); } };

// 6. Secure Robots.txt app.get('/robots.txt', (req, res) => { res.type('text/plain'); res.send("User-agent: *\nDisallow: /admin\n"); });

// 7. CORS Configuration const cors = require('cors'); app.use(cors({ origin: 'https://yourdomain.com', credentials: true }));

// 8. Encrypt Session Cookies const session = require('express-session'); app.use(session({ secret: 'yourStrongSecretKey2025@!', resave: false, saveUninitialized: true, cookie: { secure: true, httpOnly: true } }));

// 9. Two-Factor Authentication Setup (TOTP) const speakeasy = require('speakeasy'); const QRCode = require('qrcode');

// Function to generate TOTP for 2FA function generate2FA(user) { const secret = speakeasy.generateSecret({ name: InnChanger AI (${user.email}) }); QRCode.toDataURL(secret.otpauth_url, (err, dataURL) => { user.qrCode = dataURL; user.secret = secret.base32; }); }

// 10. CSP Meta Tag for HTML head /* <meta http-equiv="Content-Security-Policy" content="default-src 'self'; script-src 'self' https://trusted-cdn.com; style-src 'self' https://fonts.googleapis.com;"> */

module.exports = { enforceHTTPS, helmet, authenticate, csrfProtection, generate2FA };

