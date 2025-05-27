let canvas=document.querySelector('canvas');

let context=canvas.getContext('2d');

context.beginPath();
context.moveTo(50,50);
context.lineTo(100,50);
context.lineTo(100,100);
context.fillStyle="red";
context.fill();
