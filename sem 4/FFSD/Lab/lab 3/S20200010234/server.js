const express = require("express");
const app = express();
const sqlite3 = require("sqlite3");
const bodyparser = require("body-parser");
app.use(bodyparser.urlencoded({ extended: true }));

let path = require("path");

// app.use()

app.use(express.static(__dirname + "/public"));
const db_name = path.join(__dirname, "data", "home.db");

const db = new sqlite3.Database(db_name, (err) => {
  if (err) {
    return console.log(err.message);
  }
  console.log("Database Connected");
});

const table =
  "CREATE TABLE IF NOT EXISTS S20200010234(S20200010234pname VARCHAR(100),S20200010234rollno int,S20200010234sem int,S20200010234pdetails varchar(300),S20200010234tused varchar(40));";
db.run(table, (err) => {
  if (err) {
    return console.log(err.message);
  }
  console.log("Table Created");
});

app.get("/", (req, res) => {
  res.sendFile(path.resolve("./public/home.html"));
});

app.get("/Add-Project-Details", (req, res) => {
  res.sendFile(path.resolve("./public/form.html"));
});
app.post("/Add-Project-Details", (req, res) => {
  // const username=req.body.username;
  // const password=req.body.password;
  console.log(req.body);

  db.run(
    "INSERT INTO S20200010234(S20200010234pname,S20200010234rollno,S20200010234sem,S20200010234pdetails,S20200010234tused) VALUES(?,?,?,?,?)",
    [
      req.body.pname,
      req.body.rollno,
      req.body.sem,
      req.body.pdetails,
      req.body.tused,
    ],
    (err) => {
      if (err) {
        return console.log(err.message);
      }

      console.log("Data Entered");
    }
  );
  res.redirect("/Project-Details");
});

app.get("/Project-Details", (req, res) => {
  db.all("SELECT * FROM S20200010234", (err, row) => {
    if (err) {
      console.log("Error in login" + err);
    } else {
      res.json(row);
    }
  });
});

app.get("/ContactUs", (req, res) => {
  res.sendFile(path.resolve("./public/contact.html"));
});

app.listen(3000, "localhost", () => {
  console.log("Server is running");
});
