var myQuestions = [
  {
    question: "What is 10/2?",
    answers: {
      a: "3",
      b: "5",
      c: "115",
    },
    correctAnswer: "b",
  },
  {
    question: "What is 30/3?",
    answers: {
      a: "3",
      b: "5",
      c: "10",
    },
    correctAnswer: "c",
  },
];

var quizContainer = document.getElementById("quiz");
var resultsContainer = document.getElementById("results");
var submitButton = document.getElementById("submit");
var step1= document.getElementById("step1");
generateQuiz(myQuestions, quizContainer, resultsContainer, submitButton);

function generateQuiz(
  questions,
  quizContainer,
  resultsContainer,
  submitButton
) {
  function showQuestions(questions, quizContainer) {
    // we'll need a place to store the output and the answer choices
    var output = [];
    var answers;

    // for each question...
    for (var i = 0; i < questions.length; i++) {
      // first reset the list of answers
      answers = [];

      // for each available answer...
      for (letter in questions[i].answers) {
        // ...add an html radio button
        answers.push(
          '<label class="white-text" >' +
            '<input  type="radio" name="question' +
            i +
            '" value="' +
            letter +
            '">' +
            letter +
            ": " +
            questions[i].answers[letter] +
            "</label><br>"
        );
      }

      // add this question and its answers to the output
      output.push(
        '<br><div class="white-text" class="question" style="font-size : 40px">' +
          (i + 1) +
          ". " +
          questions[i].question +
          "</div><br>" +
          '<div class="answers" style="font-size : 30px">' +
          answers.join("") +
          "</div><br>"
      );
    }

    // finally combine our output list into one string of html and put it on the page
    quizContainer.innerHTML = output.join("");
  }

  function showResults(questions, quizContainer, resultsContainer) {
    // gather answer containers from our quiz
    var answerContainers = quizContainer.querySelectorAll(".answers");

    // keep track of user's answers
    var userAnswer = "";
    var numCorrect = 0;

    // for each question...
    for (var i = 0; i < questions.length; i++) {
      // find selected answer
      userAnswer = (
        answerContainers[i].querySelector(
          "input[name=question" + i + "]:checked"
        ) || {}
      ).value;

      // if answer is correct
      if (userAnswer === questions[i].correctAnswer) {
        // add to the number of correct answers
        numCorrect++;

        // color the answers green
      }
    }

    // show number of correct answers out of total
    resultsContainer.innerHTML = numCorrect + " out of " + questions.length;
    if (numCorrect == questions.length) {
      // changec();
      step1.className="circle2"
      
    }
  }

  // show questions right away
  showQuestions(questions, quizContainer);

  // on submit, show results
  submitButton.onclick = function () {
    showResults(questions, quizContainer, resultsContainer);
  };
}
function hide() {
  document.getElementById("rButton").style.display = "none";
}
// function changec() {
//   if (numCorrect == questions.length) {
//     // changec();
//     var element = document.getElementById("step1");
//     element.classList.remove("circle")
//     element.classList.add("circle2");
//   }
//   // var element = document.getElementById("step1");
//   // element.className = "circle2";
  
// }