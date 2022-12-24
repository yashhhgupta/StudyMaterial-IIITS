//word frequency counter
function wordFrequencyCounter() {
    let str = document.getElementById('stext').value;
    let str1 = str.split(" ");
    str1 = str1.map((s) => s.toLowerCase());
    let obj = {};
    for (let i = 0; i < str1.length; i++) {
        if (obj[str1[i]]) {
            obj[str1[i]]++;
        } else {
            obj[str1[i]] = 1;
        }
    }
    console.log(obj);
    let str2 = "";
    for (let key in obj) {
        str2 += key + ": " + obj[key] + "<br>";
    }
    document.getElementById('result').innerHTML = str2;
}
