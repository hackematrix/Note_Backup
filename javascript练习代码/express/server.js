import express from 'express';

const app=express();
const port=3000;

app.get('/',(req,res)=>{
    res.send("Hello world");
});

app.listen(port,()=>{
    // ip address:127.0.0.1
    console.log(`Example app listening on port${port}`);
});
