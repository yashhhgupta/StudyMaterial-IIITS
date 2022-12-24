    function validateSignup()
    {
        let mailid = document.getElementById("email").value;
        let atSymbol = mailid.indexOf("@");

        if (atSymbol < 1)
            return alert("Invalid email address");

        let dot = mailid.indexOf(".");
        if (dot <= atSymbol + 2)
            return alert("Invalid email address");

        if (dot === mailid.length - 1)
            return alert("Invalid email address");

        let password = document.getElementById("password1").value;
        let confirm = document.getElementById("password2").value;

        if (password.length < 8)
            return alert("Password must be atleast 8 characters long");
        if (!password.match(/\d/))
            return alert("Password must contain atleast one number");
        if (!password.match(/[a-zA-Z]/))
            return alert("Password must contain atleast one letter");
        if (password != confirm)
            return alert("Passwords don't not match!");

        return true;
    }

    function open(b){
        const option = b.value;
        if(option == "basketball"){
            
        }
        if(option == "chess"){

        }
        if(option == "sudoku"){
            
        }
    }