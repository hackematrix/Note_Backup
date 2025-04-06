import {readFile,writeFile} from 'node:fs/promises';

// 读文件 1.read file
const keychain=await readFile('./demo/keychain.txt','utf-8',);
const data=await readFile('./demo/data.txt','utf-8');

//2.Decrypt data

//move right side
// const rightMoveDecryptedData=data.split("").map((currentChar)=>{
//     const decryptCharCode=currentChar.charCodeAt(0)+keychain;
//     return String.fromCharCode(decryptCharCode);
// }).join("");


// console.log(rightMoveDecryptedData)

//move left side
const leftMoveDecryptedData=data.split("").map((currentChar)=>{
    const decryptCharCode=currentChar.charCodeAt(0)-keychain;
    return String.fromCharCode(decryptCharCode);
}).join("");
console.log(leftMoveDecryptedData);


//3.write file
await writeFile('./demo/DecryptData.txt',leftMoveDecryptedData,'utf-8');
