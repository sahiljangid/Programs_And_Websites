var x = this;

var person = {
    firstName : "Sahil",
    lastName : " Jangid",

    fullName : function()
    {
        return this.firstName + this.lastName;
    }
};


document.write("<h1>"+person.fullName());


function remove(elem)
{
    elem.style.display = "none";
}




