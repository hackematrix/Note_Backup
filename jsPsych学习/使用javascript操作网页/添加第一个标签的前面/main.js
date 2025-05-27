let elem=document.createElement('p');
elem.innerHTML='Hi'
elem.style.color="blue"

document.querySelector('p').before(elem)
