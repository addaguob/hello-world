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

let students = 20;
let extraStudents = students % 2;
console.log(extraStudents);

extraStudents += 2;
console.log(extraStudents);

students += 1;
console.log(students);