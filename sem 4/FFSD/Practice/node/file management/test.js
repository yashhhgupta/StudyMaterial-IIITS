// const name='mari';
// console.log(name);

// const greet =(name)=>{
//     console.log(`hello,${name}`);
// }
// greet('yash');

//Global Object
// console.log(global);
setTimeout(() => {
    console.log('in the timeout');
    clearInterval(bcbc);
}, 3000);
const bcbc = setInterval(() => {
    console.log('in the interval');
}, 1000);