const video=document.getElementById("video");
const play=document.getElementById("play");
const stop=document.getElementById("stop");
const progress=document.getElementById("progress");
const time=document.getElementById("time");

function playpausevideo()
{
    
    if(video.paused)
    {
        play.innerHTML='<i class="fa fa-pause"></i>'
        video.play();
    }
    else
    {
        
        play.innerHTML='<i class="fa fa-play"></i>'
        video.pause();
    }
}
function stopvideo()
{
    video.pause();
    video.currentTime=0;
    play.innerHTML='<i class="fa fa-play"></i>'

}
function updatevideo()
{
    progress.value=(video.currentTime/video.duration)*100;
    let seconds=Math.floor(video.currentTime%60);
    let minutes=Math.floor((video.currentTime/60));
    if(minutes<10)
    {
        if(seconds<10)
        {
            time.innerText='0'+`${minutes}:`+'0'+`${seconds}`;
        }
        else
        {
            time.innerText='0'+`${minutes}:${seconds}`;
        }
    }
    else
    {
        if(seconds<10)
        {
            time.innerText=`${minutes}:`+'0'+`${seconds}`;
        }
        else
        {
            time.innerText=`${minutes}:${seconds}`;
        }
    }
}
function updateprogress()
{
    video.currentTime=(progress.value/100)*video.duration;
}
video.addEventListener('click', playpausevideo);
play.addEventListener('click',playpausevideo);
stop.addEventListener('click',stopvideo);
video.addEventListener('timeupdate',updatevideo);
progress.addEventListener('change',updateprogress);