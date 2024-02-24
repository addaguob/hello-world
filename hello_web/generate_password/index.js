const passwordLength = 12;

let letters = "abcdefghijklmnopqrstuvwxyz";
let lUppercase = letters.toUpperCase();
let numbers = "1234567890";
let symbols = "!@3$%^&*()-_+=/";
let password = "No password";

function generatePassword() {
    let withLetters = document.getElementById("withLetters").checked ? true : false;
    let withUppercase = document.getElementById("withUppercase").checked ? true : false;
    let withNumbers = document.getElementById("withNumbers").checked ? true : false;
    let withSymbols = document.getElementById("withSymbols").checked ? true : false;
    let result = document.getElementById("result");

    let allowedChars = [];
    if (withLetters) allowedChars.push(letters);
    if (withUppercase) allowedChars.push(lUppercase);
    if (withNumbers) allowedChars.push(numbers);
    if (withSymbols) allowedChars.push(symbols);
    console.log(allowedChars, typeof allowedChars, allowedChars.length);
    if (!allowedChars.length) {
        remark.textContent = `(Please check at least one box.)`;
    }
    else {
        password = "";
        let temp = "";
        for (let i = 0; i < passwordLength; i++) {
            // Get one group from letters, uppercase, numbers, or symbols
            let group = Math.floor(Math.random() * allowedChars.length);
            let word = allowedChars[group];
            console.log(group, word);
    
            // Get one character from word (choosen group)
            temp = word[Math.floor(Math.random() * word.length)];
            console.log(i, temp);
    
            password += temp;
        }
        result.value = password;
    }
}