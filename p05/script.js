const adduser=document.getElementById("add-user");
const double=document.getElementById("double");
const milli=document.getElementById("millionaires");
const sort=document.getElementById("sort");
const all=document.getElementById("all");
const main=document.getElementById("main");
let array=[];

async function Randomuser()
{
    let res = await fetch("https://randomuser.me/api/");
    let data= await res.json();
    let user= data.results[0];
    const newuser={
        name: `${user.name.title} ${user.name.first} ${user.name.last}`,
        wealth: Math.floor((Math.random())*1000000)
    };
    addnewuser(newuser);

};

function addnewuser(newuser)
{
    array.push(newuser);
    updateDOM();
};

function updateDOM(userdata=array)
{
    main.innerHTML='<h2><strong>USER </strong>WEALTH</h2>';
    userdata.forEach(user =>
        {
            const divElement=document.createElement('div');
            divElement.classList.add('user');
            divElement.innerHTML=`<strong>${user.name} </strong>$ ${(user.wealth).toFixed(2).replace(/\d(?=(\d{3})+\.)/g, '$&,')}`;
            main.appendChild(divElement);


        }
    )
 
}

adduser.addEventListener('click',Randomuser);

function doublewealth()
{
    array = array.map(user=>{
            return{ ...user,wealth: user.wealth*2};
        })
    updateDOM();    
}

double.addEventListener('click',doublewealth);

function mil()
{
    array=array.filter(user => user.wealth>1000000);
    updateDOM();
}

milli.addEventListener('click',mil);

function sorting()
{
    array.sort(function(a,b){return b.wealth-a.wealth});
    updateDOM();
}

sort.addEventListener('click',sorting);
function netwealth()
{
    const net=array.reduce((acc,user)=>
        (acc +=user.wealth),0
    );
    const divnet=document.createElement('div');
    divnet.innerHTML=`<h3><strong>Net Wealth: </strong>$ ${(net).toFixed(2).replace(/\d(?=(\d{3})+\.)/g, '$&,')}</h3>`;
    main.appendChild(divnet);


}
all.addEventListener('click',netwealth);