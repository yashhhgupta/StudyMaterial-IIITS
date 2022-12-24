const express = require('express');
const path = require('path');
const app = express();
const router = express.Router();
const morgan = require('morgan');
const mongoose = require('mongoose');
const user = require('./models/user');

let auth = false
let sessionuser
let admindata = {}
let loginstate = false

const uri = 'mongodb+srv://admin:admin123@howtobasic.xhoei.mongodb.net/HowToBasic?retryWrites=true&w=majority'

mongoose.connect(uri, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(result => app.listen(3000))
  .catch(err => console.log(err));

let index = 0;

let credentials ={
    "username": "admin",
    "password": "admin12345"
}

const bodyparser = require('body-parser');


app.use(bodyparser.urlencoded({extended: true}));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.set('view engine', 'ejs');

app.use('/static', express.static(path.join(__dirname, 'static')))
app.use('/assests', express.static(path.join(__dirname, 'assests')))
app.use('/js', express.static(path.join(__dirname, 'js')))

app.use('/route', router);

app.get('/', (req, res) => {
    if(sessionuser){
        res.render('homepage',{user:sessionuser,state:loginstate});
    }
    else
    res.render('homepage',{state:loginstate});
});

app.get('/bbCourses', (req, res) => {
    if(sessionuser){
        res.render('bbCourses',{user:sessionuser});
    }
    else
    res.render('bbCourses');
});
app.get('/bquiz', (req, res) => {
    res.render('bquiz',{user:sessionuser});
});
app.get('/cquiz', (req, res) => {
    res.render('cquiz',{user:sessionuser});
});
app.get('/gquiz', (req, res) => {
    res.render('gquiz',{user:sessionuser});
});
app.get('/squiz', (req, res) => {
    res.render('squiz',{user:sessionuser});
});

app.get('/chessCourses',(req, res)=>{
    if(sessionuser){
        res.render('chessCourses',{user:sessionuser});
    }
    else
    res.render('chessCourses');
});

app.get('/contact',(req,res)=>{
    if(sessionuser){
        res.render('contactus',{user:sessionuser,state:loginstate});
    }
    else
    res.render("contactus",{state:loginstate});
});

app.get('/guitarCourses',(req,res)=>{
    if(sessionuser){
        res.render('guitarCourses',{user:sessionuser});
    }
    else
    res.render('guitarCourses');
});

app.get('/login',(req,res)=>{
    res.render('login');
});

app.get('/signup',(req,res)=>{
    res.render('signup');
});

app.get('/profile',(req,res)=>{
    if(sessionuser){
        res.render('profile',{user:sessionuser});
    }
    else
    res.redirect('/login');
    
});

app.get('/my_courses',(req,res)=>{
    if(sessionuser){
        res.render('my_courses',{user:sessionuser,state:loginstate});
    }
    else
    res.redirect('/login');
});

app.get('/sudokuCourses',(req,res)=>{
    if(sessionuser){
        res.render('sudokuCourses',{user:sessionuser});
    }
    else
    res.render('sudokuCourses');
});

app.get('/examiner_dashboard',(req,res)=>{
    if(auth==true)
    res.render('examiner_dashboard',{data:admindata});
    else
    res.redirect('*');
});
app.get('/sudokuExaminer',(req,res)=>{
    if(auth==true)
    res.render('sudokuExaminer',{data:admindata});
    else
    res.redirect('*');
});
app.get('/guitarExaminer',(req,res)=>{
    if(auth==true)
    res.render('guitarExaminer',{data:admindata});
    else
    res.redirect('*');
});
app.get('/chessExaminer',(req, res)=>{
    if(auth==true)
    res.render('chessExaminer',{data:admindata});
    else
    res.redirect('*');
});
app.get('/bbExaminer', (req, res) => {
    if(auth==true)
    res.render('bbExaminer',{data:admindata});
    else
    res.redirect('*');
});

app.get('/about',(req,res)=>{
    if(sessionuser){
        res.render('about',{user:sessionuser,state:loginstate});
    }
    res.render('about',{state:loginstate});
});

app.get('/logout',(req,res)=>{
    sessionuser = undefined
    loginstate = false
    res.redirect('/');
});

app.get('*',(req,res)=>{
    res.render('Error404');
});



router.post('/login', (req, res)=>{

    let username = req.body.name;
    let password = req.body.password;

    if(username === credentials.username && password === credentials.password){
        user.find({},(err,data)=>{
            if(err){
                console.log(err);
            }
            else{
                admindata = data
                auth=true
                res.redirect('/examiner_dashboard');
            }
        })

    }
    else{
        user.findOne({username: username, password: password}, function(err,data){
            if(err){
                console.log(err);
            }
            else{
                if(!data){
                    res.redirect('/login');
                }
                else{
                    sessionuser = data;
                    loginstate = true;
                    res.redirect('/profile');
                }
            }
        });
    }
});

router.post('/signup',(req, res)=>{
    const User = new user({
        username: req.body.user,
        password: req.body.password1,
        email: req.body.email
    })

    User.save()
    .then(
        sessionuser = User,
        res.redirect('/profile')
    )
    .catch(err => {console.log(err)})
})

module.exports = router;