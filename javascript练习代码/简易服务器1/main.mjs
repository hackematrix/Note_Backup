import {createServer} from 'node:http';
import {readFile} from 'node:fs/promises';
import { read } from 'node:fs';

const server=createServer(async (request,response)=>{
  //text
  // response.writeHead(200,{'content-type':'text/plain'});
  // response.end('Hello World!\n');

  //html
  // response.writeHead(200,{'content-type':'text/html'});
  // const htmlFile=await readFile('./index.html','utf-8');
  // response.end(htmlFile);

  //json
  response.writeHead(200,{'content-type':'application/json'});
  const jsonFile=await readFile('./data.json','utf-8');
  response.end(jsonFile);

});

server.listen(3000,'127.0.0.1',()=>{
  console.log('Listening on 127.0.0.1:3000');
});
