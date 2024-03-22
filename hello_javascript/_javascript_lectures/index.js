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

// console.log("Dice Roller Program");

// function rollDice() {
//     const numOfDice = document.getElementById("numOfDice").value;
//     const diceResult = document.getElementById("diceResult");
//     const diceImages = document.getElementById("diceImages");
//     const values = [];
//     const images = [];

//     for (let i = 0; i < numOfDice; i++) {
//         const val = Math.floor(Math.random() * 6) + 1;
//         values.push(val);
//         images.push(`<img src="dice/dice${val}.jpg" alt="dice${val}">`);
//     }
//     diceResult.textContent = `Dice: ${values.join(", ")}`;
//     diceImages.innerHTML = images.join("");
// }

// console.log("Exploring callback function parameter")

// hello(goodbye);

// function hello(callback) {
//     // Example of delaying an execution
//     setTimeout(function () {
//         console.log("Hello!");
//     }, 3000); // Goodbye still goes first even with callback
//     callback(); // maybe I'll dig more into this later
// }

// function goodbye() {
//     console.log("Goodbye!")
// }
// sum(displayPage, 1, 2);

// function sum(callback, x, y) {
//     let z = x + y;
//     return callback(z);
// }

// function displayConsole(result) {
//     console.log(result);
// }

// function displayPage(result) {
//     document.getElementById("myH1").textContent = result;
// }

// console.log("forEach() method exercise that changes array contents")
// let numbers = [1, 5, 3, 2, 4];

// numbers.forEach(double);
// numbers.forEach(display);

// function double(element, index, array) {
//     array[index] = element * 2;
// }

// function display(element) {
//     console.log(element);
// }

// let fruits = ["apple", "mango", "banana"];
// fruits.forEach(displayFruits);
// fruits.forEach(capitalize);

// function displayFruits(element, index, array) {
//     // array[index] = element.toUpperCase();
//     console.log(element, index, array);
// }

// function capitalize(element, index, array) {
//     array[index] = element.charAt(0).toUpperCase()
//     + element.slice(1);
//     console.log(element, index, array);
// }

// console.log(".map() that accepts a callback but returns a new array")
// const numbers = [1, 2, 3, 4];
// const doubledNumbers = numbers.map(cube);
// function cube(element) {
//     return element * 3;
// }
// console.log(doubledNumbers);

// const students = ["Alex", "Kryzza", "Erum"];
// const upperizedStudents = students.map(upperized);

// function upperized(element) {
//     return element.toUpperCase();
// }
// console.log(students, upperizedStudents)
// console.log("filter method creates a new array by filtering out elements");
// const names = ["Alex", "Alexander", "Lex", "Alexthunder", "Xander", "Xan"];
// const shortNames = names.filter(getShortNames);
// const longNames = names.filter(getLongNames);

// console.log(shortNames);
// console.log(longNames);

// function getShortNames(element) {
//     return element.length <= 6;
// }

// function getLongNames(element) {
//     return element.length > 6;
// }
// console.log("but for now, let's test the 'quirkiness' of Javascript:");
// console.log(null > 0) // false

// console.log(null == 0) // false

// console.log(null < 0) // false

// console.log(null >= 0) // true. Like WTF ????????????

// // https://www.quora.com/Why-is-JavaScript-so-hated

// console.log(typeof (NaN)) // "number"

// console.log(typeof (null)) // "object"

// console.log("-----");
// // if let is replaced with var, infinite loop is a possibilty
// for (let i = 0; i < 3; i++) {
//     for (let i = 3; i >= 0; i--) {
//         console.log(i)
//     }
//     console.log("-----");
// }

// console.log(".reduce() the elements of an array to a single value");
// let nums = [1, 2, 3];
// let total = nums.reduce(sumNums);

// function sumNums(accumulator, element) {
//     return accumulator + element;
// }

// console.log(total.toFixed(2)) // toFixed formats decimal points

// let grades = [86, 90, 95];
// let len = grades.length;
// console.log(`Get average of grades: ${grades}`);
// console.log((grades.reduce(
//     function (prev, element) {
//         return prev + element;
//     }) / len ).toFixed(2)
// );

// console.log("function expression vs function declaration:");
// console.log("the former defines functions as values or variables");

// const greet = function () {
//     console.log("Hello")
// }

// setTimeout(greet, 3000);

// setTimeout(function () {
//     console.log("Hi")
// }, 3000);

// const numbers = [1, 2, 3, 4];
// console.log("Numbers: " + numbers);

// const squares = numbers.map(function(element) {
//     return Math.pow(element, 2);
// });
// console.log("Squares: " + squares);

// const cubes = numbers.map(function (element) {
//     return Math.pow(element, 3);
// });
// console.log("Cubes: " + cubes)

// const evenNums = numbers.filter(function (element) {
//     return element % 2 === 0;
// });
// console.log("Even numbers: " + evenNums);

// console.log("Total of numbers: " +
//     numbers.reduce(function (prevElement, nextElement) {
//         return prevElement + nextElement;
//     }),
//     typeof numbers.reduce(function (prevElement, nextElement) {
//         return prevElement + nextElement;
//     }));

// console.log("Arrow functions");
// const greet = (myName) => console.log("Hey there! I'm " + myName + "!");
// greet("Alex");

// setTimeout(hello, 3000);

// function hello() {
//     console.log("Hello there!");
// }
// setTimeout(() => console.log("Hello after 3secs."), 3000);
// const numbers = [1, 2, 3, 4];
// console.log("Numbers: " + numbers);
// const doubleNum = numbers.map((element) => Math.pow(element, 2));
// console.log("Doubled: " + doubleNum);
// console.log("Below 3: " + numbers.filter((value) => value > 2));

// numbers.forEach((value, index, array) => array[index] = value + 2)
// console.log("Plus 1: " + numbers);

// console.log("object = a collection of related properties and/or methods.");
// console.log("It can represent real wrold objects (people, products, places");
// console.log("object = {key:value, function()}")

// const person1 = {
//     firstName: "Alex",
//     lastName: "Thunder",
//     age: 35,
//     isEmployed: false,
//     motto: function (fname = "Alex") {
//         console.log(`Go ${this.firstName} and ${fname}! Go! Go!`);
//     }
// }

// const person2 = {
//     firstName: "Kryzza",
//     lastName: "Tan Man",
//     age: 27,
//     isEmployed: true,
//     motto: function (fname = "Kezha") {
//         console.log(`Go ${this.firstName} and ${fname}! Go! Go!`);
//     }
// }

// person1.motto("Kryzza");
// person2.motto("Alex");

// const nn = 2;
// console.log(nn);

// console.log("Object constructor method");

// function Car(make, model, year, color) {
//     this.make = make;
//     this.model = model;
//     this.year = year;
//     this.color = color;
//     this.drive = function () {
//         console.log(`You're driving the ${this.model} ${this.year}`)
//     }
// }

// const car1 = new Car("Ford", "Mustang", 2024, "grey");
// car1.drive();

// console.log("Class was introduced in ES6 (Summer 2015)")
// class Car {
//     constructor(make, model, year, color) {
//         this.make = make;
//         this.model = model;
//         this.year = year;
//         this.color = color;
//         this.honk = function() { console.log("Honk honk!")}
//     }

//     drive() {
//         console.log(`You are driving the ${this.model} ${this.year}`);
//     }
// }

// const salakyan = new Car("Ford", "Mustang", 2024, "grey");
// salakyan.drive();
// salakyan.honk();

// class MathUtil {
//     static PI = 3.14159;

//     static getDiameter(radius) {
//         return radius * 2;
//     }

//     static getCircumference(radius) {
//         return 2 * this.PI * radius;
//     }

//     static getArea(radius) {
//         return this.PI * radius * radius;
//     }
// }

// console.log(MathUtil.PI);
// console.log(MathUtil.getDiameter(10));
// console.log(MathUtil.getCircumference(10));
// console.log(MathUtil.getArea(10));

// class User {
//     static userCount = 0;

//     constructor(username) {
//         this.username = username;
//         User.userCount++;
//     }

//     static getUserCount() {
//         console.log(`There are ${User.userCount} ${User.userCount > 1 ? "users" : "user"}.`)
//     }

//     sayHello() {
//         console.log(`Hello, my username is ${this.username}.`);
//     }
// }

// const user1 = new User("alexthunder");
// const user2 = new User("kelizha");

// user1.sayHello();
// user2.sayHello();
// // user2.getUserCount(); // Error, it can't access static
// User.getUserCount();

// console.log("Demonstrate class inheritance")
// class Animal {
//     alive = true;

//     eat() {
//         console.log(`This ${this.name} is eating.`);
//     }

//     sleep() {
//         console.log(`This ${this.name} is sleeping.`);
//     }
// }

// class Fish extends Animal {
//     name = "Fish";
//     swim() {
//         console.log(`This ${this.name} is swimming!`);
//     }
// }

// class Rabbit extends Animal {
//     name = "Rabbit";

//     run() {
//         console.log(`This ${this.name} is running!`);
//     }
// }

// const rabbit = new Rabbit();
// const fish = new Fish();

// console.log(rabbit.alive);
// rabbit.alive = false;
// console.log(rabbit.alive);

// fish.sleep();
// rabbit.run();

// console.log("Demonstrate super class which is parent class")

// class Animal {

//     constructor(name, age) {
//         this.name = name;
//         this.age = age;
//     }

//     eat() {
//         console.log(`This ${this.name} is eating.`);
//     }

//     move(speed) {
//         console.log(`This ${this.name} moves at a speed of ${speed}mph.`)
//     }

//     sleep() {
//         console.log(`This ${this.name} is sleeping.`);
//     }
// }

// class Fish extends Animal {
//     constructor(name, age, swimSpeed) {
//         super(name, age);
//         this.swimSpeed = swimSpeed;
//     }
//     swim() {
//         console.log(`This ${this.name} is swimming!`);
//         super.move(this.swimSpeed);
//     }
// }

// class Hawk extends Animal {
//     constructor(name, age, flySpeed) {
//         super(name, age);
//         this.flySpeed = flySpeed;
//     }
//     fly() {
//         console.log(`This ${this.name} is flying!`);
//         super.move(this.flySpeed);
//     }
// }

// class Rabbit extends Animal {
//     constructor(name, age, runSpeed) {
//         super(name, age);
//         this.runSpeed = runSpeed;
//     }

//     run() {
//         console.log(`This ${this.name} is running!`);
//         super.move(this.runSpeed);
//     }
// }

// const fish = new Fish("fish", 1, 25);
// const hawk = new Hawk("hawk", 2, 12);
// const rabbit = new Rabbit("rabbit", 3, 50);

// console.log(fish.name);
// console.log(fish.age);
// console.log(fish.swimSpeed);
// fish.swim();
// console.log(hawk.name);
// console.log(hawk.age);
// console.log(hawk.flySpeed);
// hawk.fly();
// console.log(rabbit.name);
// console.log(rabbit.age);
// console.log(rabbit.runSpeed);
// rabbit.run();

// class Daguob {
//     constructor(name, age) {
//         this.name = name;
//         this.age = age;
//     }

//     selfIntro(hobby) {
//         console.log(`I am ${this.name} and I like to ${hobby}!`);
//     }
// }

// class Alex extends Daguob {
//     constructor(name, age, hobby) {
//         super(name, age);
//         this.hobby = hobby;
//     }

//     sayHello() {
//         console.log("Hello!");
//         super.selfIntro(this.hobby);
//     }
// }

// const alex = new Alex("Alex", 35, "study Software Engineering");
// console.log(alex.name, alex.age, alex.hobby);
// alex.sayHello();

// console.log("Setter and getter in class\n----------");

// class Rectangle {
//     constructor(width, height) {
//         this.width = width;
//         this.height = height;
//     }

//     set width(newWidth) {
//         if (newWidth > 0) {
//             this._width = newWidth;
//         }
//         else {
//             console.error("Width must be a positive number.");
//         }
//     }

//     set height(newHeight) {
//         if (newHeight > 0) {
//             this._height = newHeight;
//         }
//         else {
//             console.error("Height must be a postive number.")
//         }
//     }

//     get width() {
//         return `${this._width.toFixed(2)}cm`;
//     }

//     get height() {
//         return `${this._height.toFixed(2)}cm`;
//     }

//     get area() {
//         return `${(this._width * this._height).toFixed(2)}cm^2`;
//     }
// }

// const rect = new Rectangle(3, 4);
// console.log(rect.width);
// console.log(rect.height);
// console.log(rect.area);


// console.log("Another example on class setter/getter:")
// class Person {
//     constructor(firstName, lastName, age) {
//         this.firstName = firstName;
//         this.lastName = lastName;
//         this.age = age;
//     }

//     set firstName(newFirstName) {
//         if (typeof newFirstName === "string" && newFirstName.length > 0) {
//             this._firstName = newFirstName;
//         }
//         else {
//             console.error("Firstname must be a non-empty string.");
//         }
//     }

//     set lastName(newLastName) {
//         if (typeof newLastName === "string" && newLastName.length > 0) {
//             this._lastName = newLastName;
//         }
//         else {
//             console.error("Lastname must be a non-empty string.");
//         }
//     }

//     set age(newAge) {
//         if (typeof newAge === "number" && newAge > 0) {
//             this._age = newAge;
//         }
//         else {
//             console.error("Age must be a postive number.")
//         }
//     }

//     get firstName() {
//         return this._firstName;
//     }
//     get lastName() {
//         return this._lastName;
//     }
//     get fullName() {
//         return this._firstName + " " + this._lastName;
//     }

//     get age() {
//         return this._age;
//     }
// }

// const person1 = new Person("Alex", "Thunder", 35);

// console.log(person1.firstName);
// console.log(person1.lastName);
// console.log(person1.age);
// console.error(`I'm ${person1.fullName}. This is BroCode!`);

// console.log("Destructuring of arrays and objects:\n----------")

// let a = 1;
// let b = 2;
// [a, b] = [b, a];
// console.log("Example 1: Swap two variables values.\n", a, b);

// let nums = [1, 2, 3, 4];
// [nums[0], nums[3]] = [nums[3], nums[0]]
// console.log("Example 2:Swap two array values.\n", nums);

// console.log("Example 3: Assign array elements to variables.\n");
// let [firstNum, secondNum, ...extraNums] = nums;
// console.log(firstNum);
// console.log(secondNum);
// console.log(extraNums);

// console.log("Example 4: Extract values from objects.")
// const person1 = {
//     firstName: "Kezha",
//     lastName: "Mahal",
//     age: 27,
//     job: "Optometrist",
// }
// const person2 = {
//     firstName: "Alex",
//     lastName: "Thunder",
//     age: 35,
// }

// const { firstName, lastName, age, job = "Unemployed" } = person2;
// console.log(firstName);
// console.log(lastName);
// console.log(age);
// console.log(job);

// console.log(`Example 5: Destructuring function parameters`)

// function displayPerson({firstName, lastName, age, job="Self-employed"}) {
//     console.log(`name: ${firstName} ${lastName}`);
//     console.log(`age: ${age}`);
//     console.log(`job: ${job}`);
// }

// displayPerson(person1);
// displayPerson(person2);
// console.log("Demo nested objects")
// const person = {
//     firstName: "Kezha",
//     lastName: "Mahal",
//     age: 27,
//     job: "Optometrist",
//     hobbies: ["singing", "gaming", "reading"],
//     address: {
//         street: "35 Diamond",
//         city: "Quezon City",
//         country: "Philippines"
//     }
// }

// // console.log(person.address.city);

// for (const prop in person.hobbies) {
//     console.log(person.hobbies[prop]);
// }

// class Person {
//     constructor(name, age, ...address) {
//         this.name = name;
//         this.age = age;
//         this.address = new Address(...address);
//     }
// }

// class Address {
//     constructor(street, brgy, city) {
//         this.street = street;
//         this.brgy = brgy;
//         this.city = city;
//     }
// }

// const alex = new Person("Alexander", 35, "Diamond", "Culiat", "Quezon City");

// console.log(alex.name);
// console.log(alex.age);
// console.log(alex.address);

// console.log("---------\nArray of objects\n---------");
// const fruits = [
//     {name: "apple", color: "red", calories: 95},
//     {name: "ponkan  ", color: "orange", calories: 45},
//     {name: "banana", color: "yellow", calories: 105},
//     {name: "coconut", color: "white", calories: 159},
// ]

// fruits.push({ name: "lychee", color: "white", calories: 110 });
// for (const fruit in fruits) {
//     console.log(fruits[fruit]);
// }

// or

// fruits.forEach(fruit => console.log(fruit.name));

// const fruitNames = fruits.map(fruit => fruit.name);
// const fruitCalories = fruits.map(fruit => fruit.calories);
// console.log(fruitNames);
// console.log(fruitCalories);

// const yellowFruits = fruits.filter(fruit => fruit.color === "white");
// const lowCalFruits = fruits.filter(fruit => fruit.calories < 100);
// console.log(yellowFruits);
// console.log(lowCalFruits);

// const maxCalFruit = fruits.reduce(
//     (max, fruit) => fruit.calories > max.calories ? fruit : max
// );

// const minCalFruit = fruits.reduce((min, fruit) => fruit.calories < min.calories ? fruit : min);

// console.log("Fruit with highest calories: " + maxCalFruit.name)
// console.log("Fruit with lowest calories: " + minCalFruit.name)

// console.log("sort() method to sort array element.");
// console.log(br);

// let pLanguages = ["C++", "Java", "ASM", "C" ];
// pLanguages.forEach(element => console.log(element));
// pLanguages.sort((a, b) => a - b);
// pLanguages.forEach(element => console.log(element));

// const people = [
//     {name: "Spongebob", age: 30, gpa: 3.0},
//     {name: "Patrick", age: 37, gpa: 1.5},
//     {name: "Squidward", age: 51, gpa: 2.5},
//     {name: "Sandy", age: 27, gpa: 4.0},
// ]
// displayArray(people);
// people.sort((a, b) => a.age - b.age);
// displayArray(people);
// people.sort((a, b) => a.gpa - b.gpa);
// displayArray(people);

// function displayArray(array) {
//     for (let val of array) {
//         console.log(val);
//     }
//     console.log(br);
// }

// console.log("sort() according to names (strings)")
// people.sort((a, b) => a.name.localeCompare(b.name));
// displayArray(people);

// const strA = "ac";
// const strB = "ab";

// console.log(strA.localeCompare(strB))
// console.log(strB.localeCompare(strA))


// console.log(`Fisher-Yates algorithm`);

// const cards = ['A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K'];
// console.log(cards);
// shuffle = (cards) => {
//     for (let i = cards.length - 1; i >= 0; i--) {
//         const random = Math.floor(Math.random() * (i + 1));
//         [cards[i], cards[random]] = [cards[random], cards[i]];
//     }
// };

// shuffle(cards);
// console.log(cards);
    
// console.log(br, "date object exploration");
// // Date (year, month, day, hour, minute, second, ms)

// let date = new Date(0);
// console.log(date);
// date = new Date("2024-06-11T12:01:00Z"); // customized
// console.log(date);
// date = new Date();
// console.log(date); // Default is current date

// console.log("Year:", date.getFullYear());
// console.log("Month:", date.getMonth());
// console.log("Day:", date.getDate());
// console.log("Hours:", date.getHours());
// console.log("Minutes:", date.getMinutes());
// console.log("Secs:", date.getSeconds());
// console.log("Day of the week:", date.getDay());

// date.setFullYear(2024);
// console.log(date);

// const alex_bday = new Date("1988-06-11");
// console.log(alex_bday);
// const kryzza_bday = new Date("1996-08-10");
// console.log(kryzza_bday);
// if (alex_bday < kryzza_bday) { console.log("Older") }

// let mNum = 3;
// mNum = mNum.toString().padStart(3, 0);
// console.log(mNum);
// console.log(this);

// console.log("Closure is a function defined inside another function.");
// console.log("The inner function has access to the variables and scope of the outer function.");

// function myOuter() {
//     let msg = "Hello";

//     function myInner() {
//         console.log(msg);
//     }

//     myInner();
// }
// msg = "Hey there!";
// myOuter();

// function createCounter() {
//     let counter = 0;

//     function increment() {
//         counter++;
//         console.log(`Counter is increased to ${counter}.`);
//     }

//     function getCounter() {
//         return counter;
//     }

//     function resetCounter() {
//         counter = 0;
//     }

//     return {increment, getCounter, resetCounter};
// }

// console.log(br);
// const nCounter = createCounter();
// nCounter.increment();
// nCounter.increment();
// console.log("Current count is " + nCounter.getCounter());
// nCounter.resetCounter();
// console.log("Current count is " + nCounter.getCounter());

// setTimeout() = a function in JavaScript to schedule the execution of a function
//  after an amount of time in milliseconds


// function startButton() {
//     console.log(`Starting...`);
//     startT = setTimeout(
//         () => console.log(`3 seconds passed.`),
//         3000
//     );
// }
// function clearButton() {
//     clearTimeout(startT);
//     console.log(`Clear.`);
// }

// Clock app

// const myClock = document.getElementById("myClock");
// myClock.textContent = `Clock`;

// updateClock();
// setInterval(updateClock, 1000);

// function updateClock() {
//     const timeNow = new Date();
//     let hours = timeNow.getHours();
//     const meridiem = (hours >= 12) ? "PM" : "AM";
//     // console.log(hours % 12);
//     hours = hours % 12 || 12;
//     hours = hours.toString().padStart(2, 0);
//     const minutes = timeNow.getMinutes().toString().padStart(2, 0);
//     const seconds = timeNow.getSeconds().toString().padStart(2, 0);
//     myClock.textContent = `${hours}:${minutes}:${seconds}${meridiem}`;
// }

// // Stopwatch app
// const myStopwatch = document.getElementById("myStopwatch");

// let timer = null;
// let startTime = 0;
// let elapsedTime = 0;
// let isRunning = false;

// function startButton() {
//     if (!isRunning) {
//         startTime = Date.now() - elapsedTime;
//         timer = setInterval(updateStopwatch, 10);
//         isRunning = true;
//     }
// }

// function stopButton() {
//     if (isRunning) {
//         clearInterval(timer);
//         elapsedTime = Date.now() - startTime;
//         isRunning = false;
//     }
// }

// function resetButton() {
//     clearInterval(timer);
//     startTime = 0;
//     elapsedTime = 0;
//     isRunning = false;
//     myStopwatch.textContent = `00:00:00:00`;
// }

// function updateStopwatch() {
//     const currentTime = Date.now();
//     elapsedTime = currentTime - startTime;
//     let swHours = Math.floor(elapsedTime / (1000 * 60 * 60)).toString().padStart(2, 0);
//     let swMinutes = Math.floor(elapsedTime / (1000 * 60) % 60).toString().padStart(2, 0);
//     let swSeconds = Math.floor(elapsedTime / 1000 % 60).toString().padStart(2, 0);
//     let swMSeconds = Math.floor(elapsedTime % 1000 / 10).toString().padStart(2, 0);

//     myStopwatch.textContent = `${swHours}:${swMinutes}:${swSeconds}:${swMSeconds}`;
// }
// Import modules lesson
// import {PI, getCircumference, getArea, getVolume, getSurfaceVolume} from "./mathUtil.js";
// console.log(PI);
// console.log(getCircumference(10));
// console.log(getArea(10));
// console.log(getVolume(10));
// console.log(getSurfaceVolume(10));
// Modules only work with the HTTP(s) protocol.
// A web - page opened via the file:// protocol cannot use import / export.

// Synchronous codes executes line by line consecutively in a sequential manner
// Asynchronous codes allows multiple operations to be performed concurrently

// function f1(callback) {
//     setTimeout(() => {
//         setTimeout(() => {
//             console.log("Task 1");
//         }, 3000);
//         callback();
//     }, 2000);
    
// }

// function f2() {
//     console.log("Task 2");
//     console.log("Task 3");
//     console.log("Task 4");
// }

// f1(f2);

// Error is a object that is created to represent a problem that occurs

// try {} = encloses code that might potentially cause an error
// catch {} = catch and handle any thrown errors from try {}
// finally { } = always executes

// try {
//     console.lag("Problematic line");
//     // Network errors
//     // Promise rejection
//     // Security errors
// }


// catch (error) {
//     console.log(error);
// }

// finally {
//     console.log("Done.")
//     // Close files
//     // Close connections
//     // Release resources
// }

// let [x, y] = [4, 2];

// try {
//     x = 5;
//     y = 0;
//     if (y == 0) {
//         throw new Error("Zero division error");
//     }
//     console.log(x);
//     console.log(y);
// }

// catch (error) {
//     console.log(error)
// }

// finally {
//     console.log("Process complete.")
// }

// It's better to use console.error than console.log to make errors obvious

// DOM = Document Object Model
// console.log(document);

// Element Selectors = methods used to target and manipulate HTML elements

// document.getElementById()        --Element or Null
// document.getElementsByClassName()  --HTML Collection
// document.getElementsByTagName()  --HTML Collection
// document.querySelector()         --Element or Null
// document.querySelectorAll()      --Nodelist

// function iAMAnObject() {}

// console.log(iAMAnObject.name);
// console.log(Object.keys(iAMAnObject));

// const fruits = document.getElementsByClassName("fruits");
// const colors = ["red", "yellow", "blue"];
// let count = 0;
// Array.from(fruits).forEach(fruit => {
//     fruit.style.backgroundColor = colors[count];
//     count++;
// });

// const h4Elements = document.getElementsByTagName("h4");
// for (let h4Element of h4Elements) {
//     h4Element.style.backgroundColor = "grey";
// }
// const liElements = document.getElementsByTagName("li");
// for (let liElement of liElements) {
//     liElement.style.backgroundColor = "lightgreen";
// }

// // Selects the first instance of the element class or a tag name
// const qElement = document.querySelector(".fruits");
// qElement.style.backgroundColor = "orange"

// document.querySelectorAll() is static and not live
// const foods = document.querySelectorAll("li");
// foods[3].style.backgroundColor = "yellow";
// console.log(foods);

// foods.forEach(food => {
//     food.style.backgroundColor = "yellowgreen";
// })

// DOM Navigation = the process of navigating through the structure of an HTML document using JavaScript.
// .firstElementChild
// .lastElementChild
// .nextElementSibling
// .previousElementSibling
// .parentElement
// .children

// .firstElementChild
// const element = document.getElementById("fruits");
// const firstChild = element.firstElementChild;
// firstChild.style.backgroundColor = "yellow";

// const uElements = document.querySelectorAll("ul");
// uElements.forEach(uElement => {
//     const firstChild = uElement.firstElementChild;
//     firstChild.style.backgroundColor = "yellow";
// })

// .lastElementChild
// const uElements = document.querySelectorAll("ul");
// uElements.forEach(uElement => {
//     const lastChild = uElement.lastElementChild;
//     lastChild.style.backgroundColor = "yellow";
// })
// const element = document.getElementById("carrots");
// const nextSibling = element.nextElementSibling;
// nextSibling.style.backgroundColor = "yellowgreen";

// .nextElementSibling
// const element = document.getElementById("vegetables");
// const nextElementSibling = element.nextElementSibling;
// nextElementSibling.style.backgroundColor = "yellowgreen";

// // .previousElementSibling
// const previousElementSibling = element.previousElementSibling;
// previousElementSibling.style.backgroundColor = "yellow";

// .parentElement
// const element = document.getElementById("carrots");
// const parent = element.parentElement;
// parent.style.backgroundColor = "orange";

// .childElement
// const element = document.getElementById("vegetables");
// const children = element.children;
// const colors = ["red", "blue", "green"];
// let i = 0;
// Array.from(children).forEach(child => {
//     child.style.backgroundColor = colors[i];
//     i++
// });

// Add and change HTML

// Step 1: Create the element
// const newH1 = document.createElement("h1");
const newListItem = document.createElement("li");

// Step 2: Add attributes and properties
// newH1.textContent = "I like pizza!";
// newH1.id = "myH1";
// newH1.style.color = "tomato";
// newH1.style.textAlign = "center";
newListItem.textContent = "coconut";
newListItem.id = "coconut";
newListItem.style.fontWeight = "bold";
newListItem.style.backgroundColor = "lightgreen";

// Step 3: Append element to DOM
// document.body.append(newH1);
// document.body.prepend(newH1);
// document.body.prepend(newListItem);
// document.getElementById("box1").append(newH1);
// document.getElementById("box1").prepend(newH1);
// document.getElementById("fruits").prepend(newListItem);
// const box3 = document.getElementById("box3");
// document.body.insertBefore(newH1, box3);
// const boxes = document.querySelectorAll(".box");
// document.body.insertBefore(newH1, boxes[3])
const orange = document.getElementById("banana");
document.getElementById("fruits").insertBefore(newListItem, orange);

// Remove element
// document.body.removeChild(newH1);
// document.getElementById("box1").removeChild(newH1);
