import {readFile as readFileSync} from 'node:fs';

readFileSync('./data.json','utf-8',(error,data)=>{
    if(error){
        console.log(error.message);
    }

    console.log(data)
});
