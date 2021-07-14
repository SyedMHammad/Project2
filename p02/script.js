
const container=document.querySelector('.container');
const seats=document.querySelectorAll('.seat');
const count=document.getElementById('count');
const total=document.getElementById('total');
const movie=document.getElementById('movie');
const button=document.getElementById('button');
updateUI();
let finalcount=0;
let finalprice=0;
button.addEventListener('click',e => {
    localStorage.clear();
    seats.forEach((seat,index) => {
        if (seat.classList.contains('selected') && index!==0 && index!==1 &&index!==2){
            seat.classList.remove('selected');

            updatecount();
        }
    })
})
function updateUI(){
    const selectedSeats=JSON.parse(localStorage.getItem('selectedSeats'));
    if(selectedSeats !==null && selectedSeats.length>0){
        seats.forEach((seat,index) => {
            if ( selectedSeats.indexOf(index)> -1){
                seat.classList.add('selected');
            }
        })
        const price=JSON.parse(localStorage.getItem('moviePrice'));
        total.innerText=price;
        count.innerText=selectedSeats.length;
        const selectedmovie=JSON.parse(localStorage.getItem('movieIndex'));
        if(selectedmovie!==null){
            movie.selectedIndex=selectedmovie;
        }
    }
}
let ticket= +movie.value;
function updatecount()
{
    const selectedseats=document.querySelectorAll('.row .seat.selected');
    const seatIndex=[...selectedseats].map(seat=>[...seats].indexOf(seat));
    finalcount=selectedseats.length;
    finalprice=selectedseats.length*ticket;
    count.innerText=finalcount;
    total.innerText=finalprice;
    savedata(movie.selectedIndex,finalprice);
    localStorage.setItem('selectedSeats',JSON.stringify(seatIndex));
    
}
function savedata(movieIndex,moviePrice)
{
    localStorage.setItem('movieIndex',movieIndex);
    localStorage.setItem('moviePrice',moviePrice);
}
container.addEventListener('click', e => {
    if(e.target.classList.contains('seat') && !e.target.classList.contains('occupied'))
    {
        e.target.classList.toggle('selected');
        updatecount();
    }
})
movie.addEventListener('change', e=> {
    ticket=+e.target.value;
    updatecount();
})