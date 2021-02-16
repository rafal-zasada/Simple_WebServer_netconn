
//let myData1;
let voltage1_ReadValue = 111;
let voltage2_ReadValue = 222;
let voltage3_ReadValue = 333;
let myRequest1 = new XMLHttpRequest();

myRequest1.open('GET', 'http://192.168.0.36/data1');

myRequest1.onload = function() {
    let serverData1 = JSON.parse(myRequest1.responseText);
    let serverData2 = myRequest1.responseText;

    // log JSON
    console.log(serverData1); 

    voltage1_ReadValue = serverData1.voltage1;
    voltage2_ReadValue = serverData1.voltage2;
    voltage3_ReadValue = serverData1.voltage3;

    let voltage1DOM = document.getElementById('voltage1');
    voltage1DOM.innerText = "Voltage read from STM32 = " + voltage1_ReadValue;

    let voltage2DOM = document.getElementById('voltage2');
    voltage2DOM.innerText = "Voltage read from STM32 = " + voltage2_ReadValue;

    let voltage3DOM = document.getElementById('voltage3');
    voltage3DOM.innerText = "Voltage read from STM32 = " + voltage3_ReadValue;
}
myRequest1.send();


