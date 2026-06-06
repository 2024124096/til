// Suming the elements of an array with for and for ... in/of
function start() {
    let theArray = [1,2,3,4,5,6,7,8,9,10];
    let results, total1 = 0, total2 = 0, total3 = 0;

    // iterates through the elements of array in order and adds each element's value
    let length = theArray.length;

    for (let i=0; i<theArray.length; ++i) { total1 += theArray[i]; }
    results = "<p>Total using indices: " + total1 + "</p>";

    // iterates through the elements of the array using for...in statement
    for (let key in theArray) { total2 += theArray[key]; }
    results += "<p>Total using for...in: " + total2 + "</p>";

    for (let value of theArray) { total3 += value; }
    results += "<p>Total using for...of: " + total3 + "</p>";

    document.getElementById( "output" ).innerHTML = results;
} // end function start


window.addEventListener("load", start, false);

