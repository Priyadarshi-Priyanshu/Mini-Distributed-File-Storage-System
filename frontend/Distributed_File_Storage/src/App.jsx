import React, { useState } from "react";
import axios from "axios";

function App() {
  const [input, setInput] = useState("");
  const [response, setResponse] = useState("");

  const fetchGreeting = async () => {
    try {
      const res = await axios.get(`http://localhost:18080/${input}`);
      console.log(res);
      setResponse(res.data.message);  // ✅ Extract the actual message string
    } catch (err) {
      console.error("Error fetching data:", err);
      setResponse("Error occurred while fetching data");
    }
  };

  return (
    <div>
      <h1>MiniDFS UI</h1>
      <input value={input} onChange={(e) => setInput(e.target.value)} />
      <button onClick={fetchGreeting}>Get Greeting</button>
      <div>{response}</div> {/* ✅ Display plain text */}
    </div>
  );
}

export default App;
