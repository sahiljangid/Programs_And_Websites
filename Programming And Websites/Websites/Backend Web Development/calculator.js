function cal()
{
    var opr1 = document.getElementById('first').value;
    var opr2 = document.getElementById('second').value;
    var op = document.getElementById('op').value;
    // alert(opr1)
    // alert(opr2)
    // alert(op)

    if (op == '+') {
        var res = parseInt(opr1)  + parseInt(opr2);
    }

    if (op == '-') {
        var res = parseInt(opr1)  - parseInt(opr2);
    }

    if (op == '*') {
        var res = parseInt(opr1)  * parseInt(opr2);
    }

    if (op == '/') {
        var res = parseInt(opr1)  / parseInt(opr2);
    }
    document.getElementById('res').value = res;
    // alert(res)
}