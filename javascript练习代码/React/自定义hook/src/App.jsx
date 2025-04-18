import { useState,useEffect } from "react";
import Time from './Time.jsx';
import Advice from "./Advice.jsx";


function App(){
  return(
    <>
    <h1>Advice</h1>
    <Time/>
    <Advice/>
    </>
  );
}

export default App;  
