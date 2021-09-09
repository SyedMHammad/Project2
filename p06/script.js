const popclose=document.getElementById('pop-close');
const close=document.getElementById('close');
const navi=document.getElementById('navi');
const pop=document.getElementById('pop');
const modal=document.getElementById('modal');
const nav=document.getElementById('navs');
const sub=document.getElementById('submit');
const form=document.getElementById('form');
const span=document.getElementById('span');
const pops=document.getElementById('pops');

navi.addEventListener('click',()=>{
    document.body.classList.toggle('show-nav');
})
pop.addEventListener('click',() => modal.classList.add('show-modal'));
popclose.addEventListener('click',()=>modal.classList.remove('show-modal'));

sub.addEventListener('click',()=>{
    span.innerHTML="<p>Thankyou for your valuable feedback!</p>";
    pops.classList.add('increase');
})

window.addEventListener('click',e=>{
    e.target===modal ? modal.classList.remove('show-modal') : false;
})