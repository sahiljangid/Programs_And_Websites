function math(params) {
    var pi = Math.PI;
    
    
    var pow = Math.pow(2,5);
    
    var sqrt = Math.sqrt(64);
    
    var abs = Math.abs(-50);
    
    var round = Math.round(2.3);

    var ceil = Math.ceil(2.3);

    var floor = Math.floor(2.3);

    var min = Math.min(23,5345,534,634,45,87);

    var max = Math.max(23,5345,534,634,45,87);


    var ran = Math.floor(Math.random()*999999);


    document.getElementsByTagName('h1')[0].innerHTML = pi;

    document.getElementsByTagName('h1')[1].innerHTML = pow;
    
    document.getElementsByTagName('h1')[2].innerHTML = sqrt;

    document.getElementsByTagName('h1')[3].innerHTML = abs;

    document.getElementsByTagName('h1')[4].innerHTML = round;

    document.getElementsByTagName('h1')[5].innerHTML = ceil;

    document.getElementsByTagName('h1')[6].innerHTML = floor;
    
    document.getElementsByTagName('h1')[7].innerHTML = min;

    document.getElementsByTagName('h1')[8].innerHTML = max;

    document.getElementsByTagName('h1')[9].innerHTML = ran;



}