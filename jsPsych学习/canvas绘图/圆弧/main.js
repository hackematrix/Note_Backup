const canvas=document.querySelector('canvas');
const context=canvas.getContext('2d');

context.arc(100,100,50,0,Math.PI/2,true)
context.stroke();
