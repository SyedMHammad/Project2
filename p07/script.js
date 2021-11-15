const word=document.getElementById("correct-container");
const inword=document.getElementById("incorrect-letters");
const notif=document.getElementById("notification");
const over=document.getElementById("gameover-container");
const overmsg=document.getElementById("gameover-msg");
const playagain=document.getElementById("playagain");
const close=document.getElementById("close");
const hangmanparts=document.querySelectorAll('.man');
const wrongkey=document.getElementById("notificationw");
const gg=document.getElementById("gameover");
const words=[];
const correctletter=[];
const incorrectletters=[];
let randomword;
async function generateword()
{
    let res=await fetch("https://random-word-api.herokuapp.com/word?number=1000");
    let data=await res.json();
    data.forEach(element => {
        words.push(element);
    });
    randomword=words[Math.floor(Math.random()*words.length)];
    renderword();

}
// console.log(randomword);
function renderword()
{
    word.innerHTML=`
    ${randomword.split('').map( letter => `
    <span class="letter">
    ${correctletter.includes(letter)?letter:''}
    </span>`).join('')}
    `;
    const neword=word.innerText.replace(/\n/g,'');
    const nword=word.innerText.replace(/ /g,'');
    console.log(nword);
    if(nword==randomword)
    {
        over.style.display='flex';
        overmsg.innerText="Congrats! You have saved the man."
    }
}
function renderincorrect()
{
    inword.innerHTML=`
    <p>Incorrect Letters</p>
    ${incorrectletters.map(letter=>`<span>${letter}</span>`)}`;
    hangmanparts.forEach( (part,index)=>
    {
        const num=incorrectletters.length;
        console.log(index);
        if(index<num)
        {
            part.style.display='block';
        }
        else
        {
            part.style.display='none';
            
        }
    })
    if(incorrectletters.length===hangmanparts.length)
    {
        over.style.display='flex';
        overmsg.innerText=`You have failed! 
        Correct word is "${randomword}"`;
        gg.style.height= '200px';
    }

}
close.addEventListener('click',e =>{
    over.style.display='none';
})
playagain.addEventListener('click',e =>{
    over.style.display='none';
    location.reload();
})
window.addEventListener('keydown',e=>{
    if(e.keyCode>=65 && e.keyCode<=90)
    {
        if(randomword.includes(e.key))
        {
            if(correctletter.includes(e.key))
            {
                notif.classList.add('show');
                setTimeout(() => { notif.classList.remove('show') }, 1500);
            }
            else
            {
                correctletter.push(e.key);
            }
            

        }
        else
        {
            if(incorrectletters.includes(e.key))
            {
                notif.classList.add('show');
                setTimeout(() => { notif.classList.remove('show') }, 1500);
            }
            else
            {
                incorrectletters.push(e.key);
                renderincorrect();
            }
            
        }
    }
    else
    {
        wrongkey.classList.add('show');
        setTimeout(() => { wrongkey.classList.remove('show') }, 1500);

    }
    renderword();
    
})
generateword();
renderword();
