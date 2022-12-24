//closure
function fun(){
    let y=10;
    return function(x){
        return x+y;
    }
}
let a=fun()
console.log(a(50))