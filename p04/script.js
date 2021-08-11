const baseAmount=document.getElementById("base-amount");
const baseCurrency=document.getElementById("base-currency");
const targetAmount=document.getElementById("target-amount");
const targetCurrency=document.getElementById("target-currency");
const flip=document.getElementById("flip");
const exchangeRate=document.getElementById("xrate");

function calculate()
{
    const baseCode= baseCurrency.value;
    const targetCode= targetCurrency.value;
    fetch(`https://v6.exchangerate-api.com/v6/0f27c629f4f75b784db94462/latest/${baseCode}`)
        .then(res => res.json())
        .then(data =>{
            const rate = data.conversion_rates[targetCode];
            console.log(rate);
            exchangeRate.innerText = `1 ${baseCode} = ${rate} ${targetCode}`;
            targetAmount.value = (baseAmount.value * rate).toFixed(2);
        })

};

baseCurrency.addEventListener('change',calculate);
targetCurrency.addEventListener('change',calculate);
baseAmount.addEventListener('input',calculate);
targetAmount.addEventListener('input',calculate);
flip.addEventListener('click', e => {
    const temp=baseCurrency.value;
    baseCurrency.value=targetCurrency.value;
    targetCurrency.value=temp;
    calculate();
})
calculate();
