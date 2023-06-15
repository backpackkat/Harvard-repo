<script>
            // TODO: Add code to check answers to questions


            document.addEventListener('click',function(){

let correct_button = document.querySelector("#correct");
let incorrect_buttons = document.querySelectorAll(".incorrect");
let message = document.querySelectorAll("#message");
let message = document.querySelector("message2");



correct_button.addEventListener('DOMContentLoaded',function(){
    correct_button.style.backgroundColor = "green";
    message.innerHTML = "Correct";
})

for (let i = 0; i < incorrect_buttons.length; i++ )
{
    incorrect_buttons[i].addEventListener('click', function() {
        incorrect_buttons[i].style.backgroundColor = "red";
        message.innerHTML = "Incorrect";
        })
}


document.querySelector("#section2").addEventListener('click',function(){

    let input = document.querySelector("input");
    let message = document.querySelector("#message2");
     if (input.value == "UAE")
     {
        input.style.color = "green";
        message.innerHTML = "Correct";
     }

     else
     {
        input.style.color = "red";
        message.innerHTML = "Incorrect";

     }

});
});

</script>

<script>
document.addEventListener('DOMContentLoaded', function() {
    let button = document.querySelector('.correct'); button.addEventListener('click', function() {
        button.style.backgroundColour = green;
});
});





document.addEventListener('DOMContentLoaded', function() {
    let button = document.querySelectorALL('.correct'); button.addEventListener('click', function() {
        button.style.backgroundColour = red;
});
});
</script>

<script>
document.addEventListener('DOMContentLoaded', => {
    //if answer is correct:
    const correct = document.querySelector('.correct');
    correct.addEventListener('click', => {
    document.querySelector('button').innerText = 'Correct!';
    });
    //if answer incorrect:
    const incorrect = document.querySelectorAll('.incorrect');
    incorrect.addEventListener('click', => {
    document.querySelector('button').innerText = 'Incorrect!';
    });
});
</script>

<script>
document.addEventListener('DOMContentLoaded' function() {
    document.querySelector('form').addEventListener('submit', function(event) {
        let name = document.querySelector('#name').value;
        alert('hello, ' + name);
        event.preventDefault();
    });
});

</script>
<script>
document.addEventListener('DOMContentLoaded', function() {

    let correct_button = document.querySelector("#correct");
    correct.addEventListener('click', function() {
        correct_button.style.backgroundColor = "green";
        document.querySelector("#message").innerHTML = "Correct!";
    });

    let incorrect_buttons = document.querySelectorAll(".incorrect");
    for (let i = 0; i < incorrect_buttons.length; i++) {
        incorrect_buttons[i].addEventListener('click', function() {
            incorrect_buttons[i].style.backgroundColor = "red";
            document.querySelector("#message").innerHTML = "Incorrect!";
        });
    }

    document.querySelector("#section2").addEventListener('click', function() {
        let input = document.querySelector("input");
        if (input.value == "UAE" OR "United Arab Emirates" + "Dubai" OR "Dubai, UAE") {
            input.style.backgroundColour = "green";
            document.querySelector("#message2").innerHTML = "Correct!";
        }
        else{
            input.style.backgroundColour = "red";
            document.querySelector("#message2").innerHTML = "Incorrect!";
        };
    });

</script>

<script>
document.addEventListener('DOMContentLoaded', function() {
    let correct_button = document.querySelector("#correct");
    let incorrect_button = document.querySelectorAll(".incorrect");

    correct_button.addEventListener('click', function() {
        correct_button.style.backgroundColor = "green";
        document.querySelector("#message").innerHTML = "Correct!";
    });
    for (let i = 0; i < incorrect_buttons.length; i++)
    {
        incorrect_button[i].addEventListener('click', function() {
            console.log('incorrect; try again!');
        })

    }
});
</script>

<!DOCTYPE html>

<html lang="en">
    <head>
        <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@500&display=swap" rel="stylesheet">
        <link href="styles.css" rel="stylesheet">
        <title>BPK's Trivia!</title>
        <script>
            document.addEventListener('DOMContentLoaded', function() {

                let correct_button = document.querySelector("#answerD");
                correct.addEventListener('click', function() {
                    correct_button.style.backgroundColor = "green";
                    document.querySelector("#message").innerHTML = "Correct!";
                });

                let incorrect_buttons = document.querySelectorAll(".incorrect");
                for (let i = 0; i < incorrect_buttons.length; i++) {
                    incorrect_buttons[i].addEventListener('click', function() {
                        incorrect_buttons[i].style.backgroundColor = "red";
                        document.querySelector("#message").innerHTML = "Incorrect!";
                    });
                }

                document.querySelector("#section2").addEventListener('click', function() {
                    let input = document.querySelector("input");
                    if (input.value == "UAE" OR "United Arab Emirates" OR "Dubai" OR "Dubai, UAE") {
                        input.style.backgroundColour = "green";
                        document.querySelector("#message2").innerHTML = "Correct!";
                    }
                    else{
                        input.style.backgroundColour = "red";
                        document.querySelector("#message2").innerHTML = "Incorrect!";
                    });
                });

            </script>


    </head>
    <body>
    <div class="header">
    <h1>Trivia!</h1>
</div>

    <div class="section1">
        <h2> Part 1: Multiple Choice </h2>
        <hr>
        <h3>
            Question 1: Who won the last Kentucky Derby? </h3><br>
            <button class="incorrect_buttons" name="answerA">
                A. Secretariat
            </button><br>
            <button class="incorrect_buttons" name="answerB">
                B. Big Ben
            </button><br>
            <button class="incorrect_buttons" name="answerC">
                C. Cigar
            </button><br>
            <button class="correct_button" name="answerD" autofocus>
                D. Rich Strike
            </button>
    </div>

    <div class="section2">
        <h2>Part 2: Free Response</h2>
        <hr>
        <!-- TODO: Add free response question here -->
        <h3>What is the latest country to send an astronaut into space as of April 2023?</h3><br>
                    <form>
                        <input autocomplete="off" cursor ="blinking" name=" ?">
                <input type="text" value="Fly Me To The Moon!">
                </form>
                <button id="Astro" name="Confirm" autofocus>
                </button>

            </div>
        </div>
    </body>
</html>

<!DOCTYPE html>

<html lang="en">
    <head>
        <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@500&display=swap" rel="stylesheet">
        <link href="styles.css" rel="stylesheet">
        <title>BPK's Trivia!</title>

        <script>
            // TODO: Add code to check answers to questions
            document.addEventListener('DOMContentLoaded', function() {

                // When correct answer clicked, color set to green and display correct answer
                let correct = document.querySelector('.correct');
                correct.addEventListener('click', function(click) {
                    correct.style.backgroundColor = 'green';
                    document.querySelector('#feedback1').innerHTML = 'Correct!';
                    });

                function displayCorrect() {
  document.getElementById("horse").innerHTML = "Justify won the Triple Crown in 2018, which includes the Kentucky Derby, the Preakness, and the Belmont Stakes. No other horse has done it since. The next round begins in May 2023.";
}

                    //display trivia 2 only after selecting correct answer (#paragraph)
                function displayText() {
                var text = document.getElementById("tech").innerHTML = "Correct! Samsung was founded as a grocery trading store in 1938, when cell phones didn't even exist.";
                }
                        // When incorrect answer clicked, color set  to red and display incorrect answer
// quedstion 1
                let incorrects = document.querySelectorAll('.incorrect');
                for(let i = 0; i < incorrects.length; i++)
                {
                    incorrects[i].addEventListener('click', function(event) {
                    incorrects[i].style.backgroundColor = 'red';
                    document.querySelector('#feedback1').innerHTML = 'Incorrect';
                    });
                }
// question 2
                document.querySelector('#check').addEventListener('click', function(){
                   let input = document.querySelector('input');
                   if(input.value == 'Samsung'){
                       input.style.backgroundColor = 'green';
                       document.querySelector('#feedback2').innerHTML = 'Correct!';
                   } else {
                       input.style.backgroundColor = 'red';
                       document.querySelector('#feedback2').innerHTML = 'Incorrect';
                   }
                });
            });

        </script>
        </head>
        <body>
        <div class="header">
            <h1>Trivia!</h1>
        </div>

        <div class="container">
            <div class="section">
                <h2>Part 1: Multiple Choice </h2>
                <hr>
                <h3>Who was the most recent winner of the Triple Crown? </h3>
                <button class = "incorrect">Secretariat</button>
                <button class = "incorrect">Big Ben</button>
                <button class = "incorrect">David Malan</button>
                <button class = "correct" onClick="displayCorrect()">Justify</button>
                <p id="horse"></p>
                <div id="textField" style="display: none;">
                    </div>


                <div id="p" style="display:none;"></div>
                    <p></p>
                    </div>
            </div>

            <div class="section">
                <h2>Part 2: Free Response</h2>
                <hr>
                <h3>What is the name of the biggest tech company in South Korea?</h3>
                <input type ="text"></input>
                <button class="tech" Check Answer onclick=" displayCorrect()">Check Answer</button>

                <div id="textField" display:none;></div>
                    </div>
            </div>
        </div>
        </body>
        </html>