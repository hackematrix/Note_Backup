const canvas=document.querySelector('canvas');
const context=canvas.getContext('2d');

let image=new Image();
image.src="161458933.jpg";

image.onload=function(){
    context.drawImage(image,0,0,200,200);
}
