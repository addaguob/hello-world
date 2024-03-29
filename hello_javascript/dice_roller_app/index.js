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
// const countLabel = document.getElementById("countLabel");
// const resetBtn = document.getElementById("resetBtn");
// const decreaseBtn = document.getElementById("decreaseBtn");
// const increaseBtn = document.getElementById("increaseBtn");

// let n = 0;

// resetBtn.onclick = function() {
//     n = 0;
//     countLabel.textContent = n;
// }

// decreaseBtn.onclick = function() {
//     n = n - 1;
//     countLabel.textContent = n;
// }

// increaseBtn.onclick = function() {
//     n = n + 1;
//     countLabel.textContent = n;
// }

// //Math

// console.log(Math.PI)
// console.log(Math.E)

// let x = 45;
// let y = 10;
// let z = 1;

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
// const rollButton = document.getElementById("rollButton");
// const rollResult1 = document.getElementById("rollResult1");
// const rollResult2 = document.getElementById("rollResult2");
// const rollResult3 = document.getElementById("rollResult3");
// const min = 1;
// const max = 6;
// let rolled = 0;
// rollButton.onclick = function () {
//     rolled = Math.floor(Math.random() * max) + min;
//     rollResult1.textContent = rolled;
//     rolled = Math.floor(Math.random() * max) + min;
//     rollResult2.textContent = rolled;
//     rolled = Math.floor(Math.random() * max) + min;
//     rollResult3.textContent = rolled;
// }

// let age = 0;
// let remarks = ''
// let hasLicense = false;

// document.getElementById("ageSubmit").onclick = function() {
//     age = document.getElementById("ageInput").value;
//     age = Number(age);
    
//     remarks = document.getElementById("ageRemarks");

//     if (age > 99) {
//         remarks.textContent = "Your are to old for this!";
//     }
//     else if (age >= 16) {
//         remarks.textContent = "You are old enough to drive";
    
//         if (hasLicense) {
//             remarks.textContent = "You have your license!";
//         }
//         else {
//             remarks.textContent = "You do not have your license yet";
//         }
//     }
//     else if (age <= 0) {
//         remarks.textContent = "Your age can't be below zero";
//     }
//     else {
//         remarks.textContent = `Your age (${age}) must be at least 16 to have a license`;
//     }
// }

// const myCheckbox = document.getElementById("myCheckbox");
// const visaBtn = document.getElementById("visaBtn");
// const mastercardBtn = document.getElementById("mastercardBtn");
// const paypalBtn = document.getElementById("paypalBtn");
// const mySubmit = document.getElementById("mySubmit");
// const submitResult = document.getElementById("submitResult");
// const paymentResult = document.getElementById("paymentResult");

// mySubmit.onclick = function () {
//     if (myCheckbox.checked) {
//         submitResult.textContent = `You are subscribed!`;
//     }
//     else {
//         submitResult.textContent = `You are not subscribed!`;
//     }

//     if (visaBtn.checked) {
//         paymentResult.textContent = `You are paying with Visa`;
//     }
//     else if (mastercardBtn.checked) {
//         paymentResult.textContent = `You are paying with MasterCard`;
//     }
//     else if (paypalBtn.checked) {
//         paymentResult.textContent = `You are paying with PayPal`;
//     }
//     else {
//         paymentResult.textContent = `You must select a payment type`;
//     }
// }

// let age = 21;

// let message = age >= 18 ? "You're an adult" : "You're a minor";
// console.log(message);

// let purchaseAmount = 99;
// let discount = purchaseAmount >= 100 ? 10 : 0;
// console.log(`Discount: ${purchaseAmount * discount / 100}`);
// console.log(`Your total is $${purchaseAmount - purchaseAmount * (discount / 100)}`)

// let day = 2;

// switch (day) {
//     case 1:
//         console.log("It is Monday");
//         break;
//     case 2:
//         console.log("It is Tuesday");
//         break;
//     case 3:
//         console.log("It is Wednesday");
//         break;
//     case 4:
//         console.log("It is Thursday");
//         break;
//     case 5:
//         console.log("It is Friday");
//         break;
//     case 6:
//         console.log("It is Saturday");
//         break;
//     case 7:
//         console.log("It is Sunday");
//         break;
//     default:
//         console.log(`${day} is not a day`);

// }

// let userName = "  Alexander  ";
// console.log(userName.charAt(3));
// console.log(userName.indexOf("e"));
// console.log(userName.lastIndexOf("e"));
// console.log(userName.length)
// console.log(userName.trim())
// console.log(userName.toUpperCase())
// console.log(userName.toLowerCase())
// console.log(userName.repeat(2))
// console.log(userName.startsWith(" "))

// let phoneNumber = "123-456-7890";
// // phoneNumber = phoneNumber.replaceAll("-", "/");
// phoneNumber = phoneNumber.padStart(15, "0");
// console.log(phoneNumber);

// // string slicing
// const fullName = "Bro Code";
// let firstName = fullName.slice(0, fullName.indexOf(" "));
// // // let lastName = fullName.slice(4, fullName.length);
// let lastName = fullName.slice(fullName.indexOf(" ") + 1);
// console.log(firstName);
// console.log(lastName);

// const email = "alex88@gmail.com"
// userName = email.slice(0, email.indexOf("@"));
// console.log("username:", userName);

// userName = window.prompt("Enter your username: ").trim();
// userName = userName.charAt(0).toUpperCase() + userName.slice(1).toLowerCase();
// console.log(userName);

// console.log("Logical operators: &&, ||, and !");
// const temp = 200;
// if (temp > 0 && temp <= 30) {
//     console.log("The weather is good!");
// }
// else {
//     console.log("The weather is bad.");
// }

// const isSunny = false;

// if (!isSunny) {
//     console.log("It is sunny.");
// }
// else {
//     console.log("It is not sunny.")
// }

// const PI = 3.14;
// if (PI !== "3.14") {
//     console.log("That is not PI.");
// }
// else {
//     console.log("That is PI.")
// }

// let userName = "";
// while (userName === "" || userName === null) {
//     userName = window.prompt("Enter your name: ");
// }

// console.log(`Hello ${userName}`);

// do {
//     userName = window.prompt("Enter your name: ");
    
// } while (userName === "" || userName === null);

// console.log(`Hello ${userName}`);

// // For-loop
// for (let i = 1; i <= 20; i++) {
//     if (i == 13) continue;
//     console.log(i);
// }

// console.log("Number guessing game: ")
// const minNum = 1;
// const maxNum = 100;
// const answer = Math.floor(Math.random() * (maxNum - minNum + 1));
// let attempts = 0;
// let guess;
// let running = true;

// console.log(answer);

// while (running) {
//     guess = window.prompt(`Guess a number between ${minNum} - ${maxNum}`);
//     guess = Number(guess);
//     console.log(typeof guess, guess);
//     if (isNaN(guess)) {
//         window.alert(`Please enter a valid number`);
//     }
//     else if (guess < minNum || guess > maxNum) {
//         window.alert(`Please enter a number between the specified range`);

//     }
//     else {
//         attempts++;
//         if (guess == answer) {
//             window.alert(`Correct! The answer is ${answer}. Total attempts: ${attempts}`);
//             running = false;
//         }
//         else if (guess > answer) {
//             window.alert(`That's higher than the secret number.`);
//         }
//         else {
//             window.alert(`That's lower than the secret number.`);
//         }
//     }
// }

// console.log("A function is a section of reusable code");
// function happyBirthday(username, age) {
//     console.log("Happy birthday to you!");
//     console.log("Happy birthday to you!");
//     console.log(`Happy birthday dear ${username}!`);
//     console.log("Happy birthday to you!");
//     console.log(`You are ${age} years old!`);
// }

// happyBirthday("Alexander", 35);
// happyBirthday("Kryzzabel", 27);

// function add(x, y) {
//     return x + y;
// }

// function isEven(number) {
//     return number % 2 === 0 ? true : false;
// }

// function isValidEmail(email) {
//     if (email.includes("@")) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }

// console.log(add(2, -3));
// console.log(isEven(5));
// let email = "alex@kryzza.com";
// console.log(`${email} as an email is ${isValidEmail(email)}`);

// Global and local variables
// func1();
// func2();

// function func1() {
//     let x = 1;
//     console.log(x);
// }
// function func2() {
//     let x = 2;
//     console.log(x);
// }

//Temperature conversion program
// const textBox = document.getElementById("textBox");
// const toFarhenheit = document.getElementById("toFarhenheit");
// const toCelsius = document.getElementById("toCelsius");
// const result = document.getElementById("result");
// let temp;

// function convert() {
//     if (toFarhenheit.checked) {
//         temp = Number(textBox.value);
//         temp = temp * 9 / 5 + 32;
//         result.textContent = temp.toFixed(1) + "°F";
//     }
//     else if (toCelsius.checked) {
//         temp = Number(textBox.value);
//         temp = (temp - 32) * 5 / 9;
//         result.textContent = temp.toFixed(1) + "°F";
//     }
//     else {
//         result.textContent = `Select a unit`;
//     }
// }

// console.log("Array = a variable like structure that  can hold more than 1 value");
// let fruits = ["apple", "orange", "banana"];
// // console.log(fruits, typeof fruits);
// // fruits[1] = "coconut";
// fruits.push("coconut");
// fruits.pop("coconut");
// fruits.unshift("mango");
// fruits.unshift("guava");
// fruits.shift();

// // console.log(fruits)
// // console.log(fruits.length);
// // console.log(fruits[fruits.length - 1]);

// // for (let i = 0; i < fruits.length; i++) {
// //     console.log(fruits[i])
// // }
// fruits.sort().reverse();
// for (let fruit of fruits) {
//     console.log(fruit);
// }

// console.log("Spread operator = '...'");
// let numbers = [1, 2, 3, 4, 5];
// console.log(numbers);
// let maxNumber = Math.max(...numbers)
// console.log(maxNumber);

// console.log("Spread operator on strings:");
// let myName = "Alexander";
// console.log(myName.length)
// let letters = [...myName].join("-");
// console.log(letters.length)

// console.log(letters);

// for (byte of letters) {
//     console.log(byte)
// }

// Doesn't support multi-assignments in a line
// let abc = "abc";
// let a, b, c = 1, 2, 0;
// console.log(a,b,c)

// let fruit1 = "mango";
// let fruit2 = "melon";
// let fruit3 = "guava";
// let fruit4 = "lemon";

// function combine(...fruits) {
//     return fruits;
// }

// let prutas = combine(fruit1, fruit2, fruit3, fruit4);
// console.log(prutas);

console.log("Dice Roller Program");

function rollDice() {
    const numOfDice = document.getElementById("numOfDice").value;
    const diceResult = document.getElementById("diceResult");
    const diceImages = document.getElementById("diceImages");
    const values = [];
    const images = [];

    for (let i = 0; i < numOfDice; i++) {
        const val = Math.floor(Math.random() * 6) + 1;
        values.push(val);
        images.push(`<img src="dice/dice${val}.jpg" alt="dice${val}">`);
    }
    diceResult.textContent = `Dice: ${values.join(", ")}`;
    diceImages.innerHTML = images.join("");
}