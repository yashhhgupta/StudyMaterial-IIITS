// let x={
//     faculty:{
//         name: 'subu'
//     }
// }
// console.log(x.faculty.name)
// console.log(x.xyz?.name)


// //function n parameters
// function add(x,y=0,z=0) {
//     return x+y+z
// }
// console.log(add());
// console.log(add(1));
// console.log(add(1, 2));
// console.log(add(1, 2, 3));


//Merge Sort in JS
const inArray = [16,27,67,11,7,9]
function mergesort(input,compareFn) {
    if (input.length >1) {
        return merge(
            mergesort(input.slice(0,input.length/2,compareFn)),
            mergesort(input.slice(input.length/2,compareFn)),
            compareFn
        )
    }
    else{
        return input
    }
}
function merge(part1,part2,compareFn) {
    let result=[],i=0,j=0
    while (part1[i]!==undefined && part2[j]!==undefined) {
        if (compareFn(part1[i],part2[j])) {
            result.push(part1[i++])
        }
        else{
            result.push(part2[j++])
        }
    }
    result.push(...part1.slice(i),...part2.slice(j))
    return result
}
console.log(mergesort(inArray,(x,y) => x>y))