
var animalContainer = document.getElementById("animal-info");
var btn1 = document.getElementById("btn1");
var pageCounter = 1;

btn1.addEventListener("click", function() {  // this is an anonymous fuction - not a good practice

    var ourRequest1 = new XMLHttpRequest();
    ourRequest1.open('GET', 'https://learnwebcode.github.io/json-example/animals-1.json')
    ourRequest1.onload = function() {
     //   console.log(ourRequest1.responseText);
     // var ourData1 = ourRequest1.responseText;  // just fot text type data
     var ourData1 = JSON.parse(ourRequest1.responseText);
    //console.log(ourData1[0]);
    renderHTML1(ourData1);
    };
        ourRequest1.send();
        pageCounter++;
        if(pageCounter > 3) {
            btn1.classList.add("hide-me");
        }
});

function renderHTML1(data) {
    var htmlString1 = "Rafal1";

    for(i = 0; i < data.length ; i++) {

        htmlString1 += "<p>" + data[i].name + "is a " + data[i].species + ".</p>";
        console.log(i);
    }


animalContainer.insertAdjacentHTML('beforeend', htmlString1);
}

/*

// Returns a Promise that resolves after "ms" Milliseconds
const timer = ms => new Promise(res => setTimeout(res, ms))

async function load () { // We need to wrap the loop into an async function for this to work
  for (var i = 0; i < 3; i++) {
    console.log(i);
    await timer(1000); // then the created Promise can be awaited
  }
}

*/