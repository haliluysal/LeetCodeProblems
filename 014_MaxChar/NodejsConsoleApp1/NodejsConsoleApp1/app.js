'use strict';

console.log('Hello world');

const string = "HELLO THERE";

const chars = {};

for (let char of string) {
    if (!chars[char]) {
        chars[char] = 1;
    } else {
        chars[char]++;
    }
}

console.log(chars);

for (var i = 1; i <= 25; i++) {
    if (i % 3 === 0) {
        console.log("fizz");
        continue;
    }
    if (i % 5 === 0) {
        console.log("buzz");
        continue;
    }
    console.log(i);
    console.log("\n");
}
a = 5;