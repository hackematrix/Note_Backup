import {readFile,writeFile,appendFile} from 'node:fs/promises';

const data=await readFile("./data.json","utf-8");
// 异步

// await writeFile("./data.json","alex-john","utf-8");

await appendFile("./data.json","\nalex-john","utf-8");

console.log(data);
