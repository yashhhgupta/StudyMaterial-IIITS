const fs= require('fs');

//read files
// fs.readFile('./blog1.txt',(err,data)=>{
//     if(err){
//         console.log(err);
//     }
//     console.log(data.toString());
// });

// console.log('last line');

// write files
// fs.writeFile('./blog1.txt','this is my first blog',(err)=>{
//     if(err){
//         console.log(err);
//     }
//     console.log('file written');
// });

//directory
// if (!fs.existsSync('./assets')) {
    

// fs.mkdir('./assets',(err)=>{
//     if(err){
//         console.log(err);
//     }
//     console.log('directory created');
// })
// }
// else{
//     fs.rmdir('./assets',(err)=>{
//         if(err){
//             console.log(err);
//         }
//         console.log('directory deleted');
//     })
// }

//deleting files
// if(!fs.existsSync('./blog1.txt')){
//     fs.unlink('./deleteme.txt'),(err)=>{
//         if(err){
//             console.log(err);
//         }
//         console.log('File deleted');
//     }
// }