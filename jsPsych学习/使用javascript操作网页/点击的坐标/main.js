function callback(event){
    console.log([event.clientX,event.clientY])
};

document.addEventListener('click',callback,{once:true});
