#ifndef FLUNKERBOY_DISPLAY_H
#define FLUNKERBOY_DISPLAY_H

const char flunkerboy_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang=\"en\">
<head>
  <meta charset=\"UTF-8\">
  <title>FlunkerBoy Display</title>
  <style>
    body { background: #222; color: #0f0; font-family: monospace; text-align: center; margin: 0; }
    svg { width: 90vw; max-width: 600px; margin-top: 20px; }
    #value { font-size: 2em; margin-top: 10px; color: #0f0; }
  </style>
</head>
<body>
  <h1 style=\"color: orange;\">FlunkerBoy</h1>
  <svg viewBox=\"0 0 500 180\">
    <rect x=\"10\" y=\"10\" width=\"480\" height=\"100\" rx=\"10\" ry=\"10\" fill=\"#111\" stroke=\"#555\" stroke-width=\"2\"/>
    <g id=\"digits\"></g>
    <circle id=\"dot\" cx=\"480\" cy=\"100\" r=\"5\" fill=\"#333\" />
    <rect x=\"10\" y=\"130\" width=\"480\" height=\"20\" fill=\"#000\" stroke=\"#555\" stroke-width=\"2\"/>
    <rect id=\"bar\" x=\"10\" y=\"130\" width=\"0\" height=\"20\" fill=\"#0f0\" />
    <text id=\"range\" x=\"460\" y=\"95\" font-size=\"14\" fill=\"#ccc\" text-anchor=\"end\">V</text>
  </svg>
  <div id=\"value\"></div>
  <script>
    function updateDisplay(data) {
      const digits = document.getElementById('digits');
      digits.innerHTML = '';
      const chars = data.value.trim().substring(0, 5).padStart(5, ' ');
      for (let i = 0; i < 5; i++) {
        const x = 30 + i * 90;
        digits.innerHTML += `<text x=\"${x}\" y=\"80\" font-size=\"60\" fill=\"#0f0\">${chars[i]}</text>`;
      }
      const dot = document.getElementById('dot');
      dot.setAttribute('fill', '#0f0');
      dot.setAttribute('cx', 30 + (data.dot - 1) * 90 + 70);
      dot.setAttribute('cy', 100);
      document.getElementById('bar').setAttribute('width', 480 * parseFloat(data.value) / 100);
      const rangeLabels = ['V','mV','A','mA','Ω','mΩ','kΩ','MΩ'];
      document.getElementById('range').textContent = rangeLabels[data.range];
      document.getElementById('value').textContent = data.value;
    }
    async function fetchData() {
      try {
        const res = await fetch('/data');
        const json = await res.json();
        updateDisplay(json);
      } catch (e) {
        console.error(e);
      }
    }
    setInterval(fetchData, 2000);
    fetchData();
  </script>
</body>
</html>
)rawliteral";

#endif