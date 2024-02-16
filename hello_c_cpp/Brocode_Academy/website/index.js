console.log("I like pizza!");
console.log("It's really good!");

// window.alert("I really love pizza!");

// This is a comment

/*
This is
a multiline
comment
*/

// A variable is a container or storing data
// Two steps (declaration and assignment)
// Declaration (var, let, const)
// Assignmet (= assignment operator)

let firstname = "Alex"; // strings
let age; // number
let isstudent = true; // booleans

age = 32 + 2;
console.log("Hello", firstname);
console.log("You are", age, "years old");
console.log(isstudent);

document.getElementById("p1").innerHTML = "Hello " + firstname;
document.getElementById("p2").innerHTML = "You are " + age + " years old.";
document.getElementById("p3").innerHTML = "Enrolled: " + isstudent;

// Arithmetic operators
// + - * / %
// ** is exponent operator

let students = 20;
let extraStudents = students % 2;
console.log(extraStudents);

extraStudents += 2;
console.log(extraStudents);

students += 1;
console.log(students);

// Operator precedence
console.log("Operator precedence=========");
console.log("1. Parenthesis ()");
console.log("2. Exponents");
console.log("3. ultiplication & Dvision");
console.log("4. Addition & Subtraction");

let result = 1 + 2 * (3 + 4);
console.log(result);
result++;
console.log(result);

// How to accept user input
// console.log("Easy way user input with a window prompt")
// let username = window.prompt("What's your name?")
// console.log(username)
console.log("Difficult way user input with HTML textbox")
let username;
document.getElementById("mySubmit").onclick = function () {
    username = document.getElementById("myText").value;
    console.log(username)
}