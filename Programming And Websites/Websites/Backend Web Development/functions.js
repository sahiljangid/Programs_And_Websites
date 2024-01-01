function greet()
{
    // document.write("Sahil Jangid")
    var name = document.getElementById('name').value;
    // alert(name)

    var string = "Hello " + name;

    document.getElementsByClassName('greet')[0].innerHTML = string;

}