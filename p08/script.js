const search=document.getElementById("searchbox");
const sbtn=document.getElementById("search");
const random=document.getElementById("random");
const resultheading=document.getElementById("resultheading");
const searchresult=document.getElementById("searchresult");
const selectedmeal=document.getElementById("selectedmeal");
const notification=document.getElementById("notification");

function searchmeal(e)
{
    e.preventDefault();
    if(search.value.trim())
    {
        const searchres=search.value;

        fetch(`https://www.themealdb.com/api/json/v1/1/search.php?s=${search.value}`)
            .then(res => res.json())
            .then(data=>{
                if(data.meals===null)
                {
                    resultheading.innerHTML=`
                    <h2>No result found for "${searchres}"</h2>`;
                    searchresult.innerHTML=``;
                }
                else
                {
                    resultheading.innerHTML=`
                    <h2>Search Results for "${search.value}"</h2>`;
                   // console.log(data.meals);
                    searchresult.innerHTML = data.meals.map( meal => `
                    <div class="meal">
                        <img src="${meal.strMealThumb}" alt="${meal.strMeal}" />
                        <div class="meal-info" data-mealID="${meal.idMeal}">
                            <h3>${meal.strMeal}</h3>
                        </div>
                    </div>
                `)
                .join('');
                    search.value='';
                }
            });
            
            

    }
    else
    {

        notification.classList.add('show');
        setTimeout(()=>{notification.classList.remove('show')},1000);

    }
}
function getdetails(mealID)
{
    fetch(`https://www.themealdb.com/api/json/v1/1/lookup.php?i=${mealID}`)
    .then(res => res.json())
    .then(data=>{
        console.log(data);
    })
}
search.addEventListener("submit",searchmeal);
sbtn.addEventListener("click",searchmeal);
searchresult.addEventListener('click', e=> {
    const mealinfo=e.path.find(item => {
        if(item.classList)
        {
            return item.classList.contains('meal-info');
        }
        else
        {
            return false;
        }
    })
    if(mealinfo)
    {
        const mealID=mealinfo.getAttribute('data-mealID');
        getdetails(mealID);
    }
})