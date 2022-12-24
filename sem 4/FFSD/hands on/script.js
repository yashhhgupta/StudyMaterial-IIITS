function sortnumbers(){
    const numString = document.getElementById('num').value 
    const order = document.getElementById('order').value
    const nums = numString.split(',').map((x)=>parseInt(x))
    document.getElementById('result').innerHTML = mergesort(nums, order==='desc');
}

function mergesort(input, desc = true, compareFn = desc ? (x, y) => x > y : (x, y) => x < y) {
    if (input.length > 1) {
        return merger(
            mergesort(input.slice(0, input.length / 2), desc),
            mergesort(input.slice(input.length / 2), desc),
            compareFn
        )
    } else {
        return input
    }
}

function merge(part1, part2, compareFn) {
    let res = [], i = 0, j = 0;
    while (part1[i] !== undefined
        && part2[j] !== undefined) {
        if (compareFn(part1[i], part2[j])) {
            res.push(part1[i++])
        } else {
            res.push(part2[j++])
        }
    }
    res.push(...part1.slice(i), ...part2.slice(j))
    return res
}

function merger(part1, part2, compareFn) {
    if(part1[0] == undefined){
        return part2
    }else if(part2[0] == undefined){
        return part1
    }
    else if(compareFn(part1[0],part2[0])){
        return [part1[0], ...merger(part1.slice(1),part2, compareFn)]
    }else{
        return [part2[0], ...merger(part1,part2.slice(1), compareFn)]
    }
}
// console.log([],[])//[]
// console.log(merger([],[], (x, y) => x > y))
// console.log([],[27, 15, 6])//[27, 15, 6]
// console.log(merger([],[27, 15, 6], (x, y) => x > y))
// console.log([45, 26, 3],[])//[45, 26, 3]
// console.log(merger([45, 26, 3],[], (x, y) => x > y))
// console.log([45, 26, 3],[27, 15, 6])//[45,27,26,15,6,3]
// console.log(merger([45, 26, 3],[27, 15, 6], (x, y) => x > y))

// const inArray = [16, 27, 67, 11, 7, 9]
// console.log(mergesort(inArray, false))

