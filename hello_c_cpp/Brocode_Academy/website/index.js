// console.log("I like pizza!");
// console.log("It's really good!");

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

// let firstname = "Alex"; // strings
// let age; // number
// let isstudent = true; // booleans

// age = 32 + 2;
// console.log("Hello", firstname);
// console.log("You are", age, "years old");
// console.log(isstudent);

// document.getElementById("p1").innerHTML = "Hello " + firstname;
// document.getElementById("p2").innerHTML = "You are " + age + " years old.";
// document.getElementById("p3").innerHTML = "Enrolled: " + isstudent;

// Arithmetic operators
// + - * / %
// ** is exponent operator

// let students = 20;
// let extraStudents = students % 2;
// console.log(extraStudents);

// extraStudents += 2;
// console.log(extraStudents);

// students += 1;
// console.log(students);

// // Operator precedence
// console.log("Operator precedence=========");
// console.log("1. Parenthesis ()");
// console.log("2. Exponents");
// console.log("3. Multiplication & Dvision");
// console.log("4. Addition & Subtraction");

// let result = 1 + 2 * (3 + 4);
// console.log(result);
// result++;
// console.log(result);

// How to accept user input
// console.log("Easy way user input with a window prompt")
// let username = window.prompt("What's your name?")
// console.log(username)
// console.log("Difficult way user input with HTML textbox")
// let username;
// document.getElementById("mySubmit").onclick = function() {
//     username = document.getElementById("myText").value;
//     console.log(username)
//     document.getElementById("myH1").textContent = `Hello ${username}`;
// }

// Type conversion
// let age = window.prompt("How old are you?");
// age = Number(age)
// age =19
// age += 1;
// console.log(age, typeof age);

// let x = "";
// let y = "";
// let z = "";

// x = Number(x);
// y = String(y);
// z = Boolean(z);

// console.log(x, typeof x);
// console.log(y, typeof y);
// console.log(z, typeof z);
// document.getElementById("p1").textContent = `x: ${x} is ${typeof x}`;
// document.getElementById("p2").textContent = `y: ${y} is ${typeof y}`;
// document.getElementById("p3").textContent = `z: ${z} is ${typeof z}`;

// const PI = 3.14159;
// let radius;
// let circumference;

// radius = window.prompt("Enter the radius of a circle:");
// document.getElementById("mySubmit").onclick = function() {
//     radius = Number(document.getElementById("myText").value);
//     circumference = 2 * PI * radius;
//     document.getElementById("myH3").textContent = `The circumference is ${circumference}cm`;
// }

// Counter app
const countLabel = document.getElementById("countLabel");
const resetBtn = document.getElementById("resetBtn");
const decreaseBtn = document.getElementById("decreaseBtn");
const increaseBtn = document.getElementById("increaseBtn");

let n = 0;

resetBtn.onclick = function() {
    n = 0;
    countLabel.textContent = n;
}

decreaseBtn.onclick = function() {
    n = n - 1;
    countLabel.textContent = n;
}

increaseBtn.onclick = function() {
    n = n + 1;
    countLabel.textContent = n;
}

//Math

console.log(Math.PI)
console.log(Math.E)

let x = 45;
let y = 10;
let z = 1;

// z = Math.round(x)
// z = Math.floor(x)
// z = Math.ceil(x)
// z = Math.trunc(x)
// z = Math.pow(x, y)
// z = Math.log(x)
// z = Math.sin(x)
// z = Math.cos(x)
// z = Math.tan(x)
// z = Math.abs(x)
// z = Math.sign(x)
// z = Math.max(x, y, z, 100, 4)
// z = Math.min(x, y, z, 100, 4)


// Random number generator
// const min = 50;
// const max = 100;
// let randomNum = Math.floor(Math.random() * (max - min)) + min;
// console.log(randomNum)

// Roll button
const rollButton = document.getElementById("rollButton");
const rollResult1 = document.getElementById("rollResult1");
const rollResult2 = document.getElementById("rollResult2");
const rollResult3 = document.getElementById("rollResult3");
const min = 1;
const max = 6;
let rolled = 0;
rollButton.onclick = function () {
    rolled = Math.floor(Math.random() * max) + min;
    rollResult1.textContent = rolled;
    rolled = Math.floor(Math.random() * max) + min;
    rollResult2.textContent = rolled;
    rolled = Math.floor(Math.random() * max) + min;
    rollResult3.textContent = rolled;
}

let x01 = 18;

if (x01 >= 18) {
    console.log("Pass");
}
else {
    console.log("Fail");
}