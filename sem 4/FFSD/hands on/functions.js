
// //ways to write a function
// function sum(x,y){
//     return x+y;
// }
// //subu favorite way to write function
// const sum1 = function(x,y){
//     return x+y;
// }
// const sum2 = (x,y)=> x+y;
// let fsd = sum1;
// console.log(fsd(1,2))



// function incByVal(incVal){
//     let fun=function(x){
//         return incVal +x
//     }
//     return fun;
// }
// let incBy2 = incByVal(2)
// let incBy5 = incByVal(5)
// console.log(incBy2(3));


function addPrefic(x){
    return "Dr. " +x
}
function addSuffix(x){
    return x+ " PhD"
}
function wrapPrefSuf(preffn,suffn){
    let fullfn = function(x){
        return suffn(preffn(x))
    }
    return fullfn
}
const full = wrapPrefSuf(addPrefic,addSuffix)
// console.log(addSuffix('yash'))
console.log(full('Yash'))