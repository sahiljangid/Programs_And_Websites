var my;

function start() {
    my = setTimeout(function()
    {
        document.write("<h1>Sahil Jangid</h1>")
    },
    5000
    );
}


function stop() {
    clearTimeout(my);
}