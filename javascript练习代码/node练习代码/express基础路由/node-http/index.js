import {createServer} from 'node:http';
import {readFile} from 'node:fs/promises';

const server=createServer(async (req,res)=>{
    const {url}=req;

    const idolDataText=await readFile('./data.json','utf-8');
    const idolData=JSON.parse(idolDataText);

    const idolName=url.split('/').at(-1);

    if(!idolName){
        res.writeHead(400,{'Content-Type':'text/plain'});
        res.end('400 Bad request');
        return;
    }

    const resultIdol=idolData.find((idol)=>idol.name.toLowerCase()===idolName.toLowerCase());

    if(!resultIdol){
        res.writeHead(404,{'Content-Type':'text/plain'});
        res.end('404 Not Found');
        return;
    }

    res.writeHead(200,{'Content-Type':'application/json'});
    res.end(JSON.stringify(resultIdol))
});

server.listen(3000,()=>{
    console.log('Listening on 3000');
});
