const container=document.querySelector('.container');
const seats=document.querySelectorAll('.seat');
const count=document.getElementById('count');
const total=document.getElementById('total');
const movie=document.getElementById('movie');

let ticket= +movie.value;
function updatecount()
{
    const selectedseats=document.querySelectorAll('.row .seat.selected');
    const seatIndex=[...selectedseats].map(seat=>[...seats].indexOf(seat));
    count.innerText=selectedseats.length;
    total.innerText=selectedseats.length*ticket;
    console.log('array',seatIndex);
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
    savedata(e.target.selectedIndex,e.target.value);
})