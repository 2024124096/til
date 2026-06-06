function start() {
    let integer1 = [2,4,6,8];
    let integer2 = [2, , ,8];

    outputArray( "Array Integers1 contains", integer1, document.getElementById( "output1" ));
    outputArray( "Array Integers2 contains", integer2, document.getElementById( "output2" ));
} // end function start

// output the heading followed by a 2-column table containing indices and elements of "theArray"
function outputArray( heading, theArray, output ) {
    let content = "<h2>" + heading + "</h2><table>" +
        "<thead><th>Index</th><th>Value</th></thead><tbody>";
    
    // output the index and value of each array element
    let length = theArray.length;

    for (let i=0; i<length; i++) {
        content += "<tr><td>" + i + "</td><td>" + theArray[i] + "</td></tr>";
    } // endfor

    content += "</tbody></table>";
    output.innerHTML = content; // place the table in the output element
} // end function outputArray

window.addEventListener("load", start, false);