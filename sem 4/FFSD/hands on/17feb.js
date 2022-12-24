// let x={
//     name: 'yash',
//     course: 'ffsd',
//     greet: function(msg){
//         console.log('says hello ${msg}')
//         console.log(`${this.course} says hello`)
//     }
// }
// x.greet()



// //passed by creator
// function greaterThan(x,y) {
//     return {
//         result: x>y,
//         then: function(thenFn){
//             result && thenFn()
//             return this
//         },
//         else: function (elseFn) {
//             result || elseFn()
//             return this
//         }
//     }
// }

// //me writing code
// greaterThan(3,4)
// .then(()=>console.log('hi'))
// .else(()=>console.log('hello'))

