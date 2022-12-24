const express =require('express');
const { sendFile } = require('express/lib/response');
const app = express();
app.set('view engine', 'ejs');
app.listen(3000);

app.use((req, res,next) => {
    console.log('new request made');
    console.log('host', req.hostname);
    console.log('path', req.path);
    console.log('method', req.method);
    next();
})

app.get('/',(req, res) => {
    const blogs =[
        {title: 'Blog 1', snippet: 'John'},
        {title: 'Blog 2', snippet: 'John m'},
        {title: 'Blog 3', snippet: 'John k'},
    ];
    res.render('index',{title: 'Home',blogs});

});
app.get('/about',(req, res) => {
        res.render("about",{title: 'AboutUs'});


});

app.get('/blogs/create',(req, res) => {
    res.render('create',{title: 'Create Blogs'});

})

app.use((req, res) => {
    res.status(404).render("404");

})