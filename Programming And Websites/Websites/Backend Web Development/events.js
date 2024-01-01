function getName() {
    var uName = document.getElementsByName('u_name')[0].value;
    document.getElementsByTagName("h3")[0].innerHTML = uName;
    // document.write(uName);
}