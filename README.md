Credit Validator
A robust C program that validates credit card numbers using Luhn’s Algorithm and identifies the issuing network based on card prefixes and lengths.

🛠 Features
Checksum Validation: Implements Luhn’s Algorithm to verify the mathematical integrity of the card number.

Issuer Identification: Automatically detects major card networks:

AMEX: 15 digits, starts with 34 or 37.

MASTERCARD: 16 digits, starts with 51, 52, 53, 54, or 55.

VISA: 13 or 16 digits, starts with 4.

Dynamic String Handling: Utilizes a custom struct and snprintf for safe numeric-to-string conversion and prefix checking.

🧠 How it Works
The program follows a three-step validation process:

Multiply & Sum: Multiply every other digit by 2, starting with the number’s second-to-last digit. If the product is greater than 9, the digits of that product are summed (e.g., 12→1+2=3).

Checksum Calculation: Add the sum of the digits that weren't multiplied by 2 to the total from Step 1.

Validation: If the total modulo 10 is congruent to 0 (Total(mod10)=0), the number is mathematically valid. The program then checks the prefix and length to determine the issuer.

🚀 Getting Started
Prerequisites
A C compiler (GCC or Clang)

The cs50 library (standard for this problem set)

Compilation
Use the following command to compile:

Bash

clang -o credit src/credit.c -lcs50
Usage
Run the executable and enter a credit card number when prompted:

Bash

./credit
Input your credit card number => 378282246310005
AMEX
🏗 Implementation Details
The project demonstrates several core C concepts:

Structs: Used requiredResultFormat to return both the string representation and the length of the card number from a single function.

📜 License
This project is open-source and available under the MIT License
