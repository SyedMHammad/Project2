const word=document.getElementById("correct-container");
const inword=document.getElementById("incorrect-letters");
const notif=document.getElementById("notification");
const over=document.getElementById("gameover-container");
const overmsg=document.getElementById("gameover-msg");
const playagain=document.getElementById("playagain");
const close=document.getElementById("close");
const hangmanprts=document.querySelectorAll('.man');
const words=[
    'abacus','dilligent','random','kite'
];
const correctletter=[];
const incorrectletters=[];
let randomword=words[Math.floor(Math.random()*words.length)];
console.log(randomword);
function renderword()
{
    word.innerHTML=`
    ${randomword.split('').map(letter => `
    <span class="letter">
    ${correctletter.includes(letter)? letter:''}
    </span>`).join('')}
    `;
}
renderword();