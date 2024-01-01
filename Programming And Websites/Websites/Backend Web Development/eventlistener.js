var i = 0;
document.getElementById('counter').innerHTML = i;
document.getElementById('btn').addEventListener("click", function() {
    document.getElementById('counter').innerHTML = ++i;
})

document.getElementById('btn').addEventListener("mouseenter", function colorred() {
    document.getElementById('counter').style.color = "red";
})

document.getElementById('btn').addEventListener("mouseleave", function colorblack() {
    document.getElementById('counter').style.color = "black";
})