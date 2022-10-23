import Hobs from './Components/Pages/Hobs'
import './App.css';
import React from "react";
import {
  BrowserRouter as Router,
  Routes,
  Route,
} from "react-router-dom";



const App = () => {
  return (
      <Router>
        <Routes>
          <Route path="/hobs" element={<Hobs/>} />
          </Routes>   
      </Router>
  );
};

export default App;
