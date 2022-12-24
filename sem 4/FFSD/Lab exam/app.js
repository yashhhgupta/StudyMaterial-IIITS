const express = require('express');
const bodyparser = require('body-parser');
const path = require('path');

const users = [];

const app = express();

app.set('view engine', 'ejs');
app.set('views', 'views');
app.use(bodyparser.urlencoded({extended: false}));
app.use(express.static(path.join(__dirname, 'public')));

app.post('/addEntry', (req, res, next) => {
    console.log(req.body);
    let date = new Date();
    let time = date.toLocaleString().slice(11, -1) + 'm';
    if(req.body.name.length < 3){
        res.json('Name should be atleast of length 3');
    }
    
    
    else{
        users.push({
            timestamp: time,
            ...req.body
        });
        res.redirect('/');
    }
})

app.get('/display', (req, res, next) => {
    res.render('display', {users: users.reverse(), title: 'result'})
})

app.use('/', (req, res, next) => {
    res.render('form', {});
})

app.listen(3000);