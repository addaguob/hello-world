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

// Operator precedence
console.log("Operator precedence=========");
console.log("1. Parenthesis ()");
console.log("2. Exponents");
console.log("3. Multiplication & Dvision");
console.log("4. Addition & Subtraction");

// let result = 1 + 2 * (3 + 4);
// console.log(result);
// result++;
// console.log(result);

// How to accept user input
// console.log("Easy way user input with a window prompt")
// let username = window.prompt("What's your name?")
// console.log(username)
// console.log("Difficult way user input with HTML textbox")
let username;
document.getElementById("mySubmit").onclick = function () {
    username = document.getElementById("myText").value;
    console.log(username)
    document.getElementById("myH1").textContent = `Hello ${username}`;
}

// Type conversion
// let age = window.prompt("How old are you?");
// age = Number(age)
age =19
age += 1;
console.log(age, typeof age);

let x = "";
let y = "";
let z = "";

x = Number(x);
y = String(y);
z = Boolean(z);

console.log(x, typeof x);
console.log(y, typeof y);
console.log(z, typeof z);
document.getElementById("p1").textContent = `x: ${x} is ${typeof x}`;
document.getElementById("p2").textContent = `y: ${y} is ${typeof y}`;
document.getElementById("p3").textContent = `z: ${z} is ${typeof z}`;

const PI = 3.14159;
let radius;
let circumference;

// radius = window.prompt("Enter the radius of a circle:");
document.getElementById("mySubmit").onclick = function () {
    radius = Number(document.getElementById("myText").value);
    circumference = 2 * PI * radius;
    document.getElementById("myH1").textContent = `The circumference is ${circumference}`;
}
