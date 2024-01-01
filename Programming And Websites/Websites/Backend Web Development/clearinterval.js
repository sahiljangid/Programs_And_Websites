
var my = setInterval(count, 1000);
var c = 0;


function count() {
    document.getElementById('h1').innerText = c;
    c++;
}

function stop() {
    clearInterval(my);
}

