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
    selectedmeal.innerHTML='';
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
function renderMeal(mealsfetched)
{

    resultheading.innerHTML='';
    searchresult.innerHTML='';
    const ingredients=[];
    for( let i=1;i<=20;i++)
    {
        if(mealsfetched[`strIngredient${i}`])
        {
            ingredients.push(`${mealsfetched[`strIngredient${i}`]} - ${mealsfetched[`strMeasure${i}`]}`);
        }
        else
        {
            break;
        }
    }
    console.log(mealsfetched);
    selectedmeal.innerHTML=`
    <div>
    <h1>${mealsfetched.strMeal}</h1>
    <img class="newimage" src="${mealsfetched.strMealThumb}" alt="${mealsfetched.strMeal}" />
    </div>
    <div class="mealdetails">
    <h2>Ingredients</h2>
    <ul>
    ${ingredients.map(ingredient=>`<li>${ingredient}</li>`).join('')}
    </ul>
    <h2>Method</h2>
    <p>${mealsfetched.strInstructions}</p>
    <h4>Visit the following link for the video:<a href=${mealsfetched.strYoutube}> ${mealsfetched.strYoutube}</a></h4>
    </div>
    
    `
}
function getdetails(mealID)
{
    fetch(`https://www.themealdb.com/api/json/v1/1/lookup.php?i=${mealID}`)
    .then(res => res.json())
    .then(data=>{
        const mealsfetched=data.meals[0];
        renderMeal(mealsfetched);
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