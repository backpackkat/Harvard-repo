---
files: [credit.py]
window: [terminal]
---

# Problem Set 6: Revisiting Week 1's Credit (Python)

-- Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.
```
$ python credit.py
Number: 378282246310005
AMEX

```
## Specs
In credit.py, write a program that prompts the user for a credit card number and then reports (via print) whether it is a valid American Express, MasterCard, or Visa card number, exactly was done in Problem Set 1, except that the program this time should be written in Python.
So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less.
For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card).

## Understanding
Program should behave per the example below.
```
$ python credit.py
Number: 378282246310005
AMEX
```

## Testing:
- Run your program as python credit.py, and wait for a prompt for input. Type in 378282246310005 and press enter. Your program should output AMEX.
- Run your program as python credit.py, and wait for a prompt for input. Type in 371449635398431 and press enter. Your program should output AMEX.
- Run your program as python credit.py, and wait for a prompt for input. Type in 5555555555554444 and press enter. Your program should output MASTERCARD.
- Run your program as python credit.py, and wait for a prompt for input. Type in 5105105105105100 and press enter. Your program should output MASTERCARD.
- Run your program as python credit.py, and wait for a prompt for input. Type in 4111111111111111 and press enter. Your program should output VISA.
- Run your program as python credit.py, and wait for a prompt for input. Type in 4012888888881881 and press enter. Your program should output VISA.
- Run your program as python credit.py, and wait for a prompt for input. Type in 1234567890 and press enter. Your program should output INVALID.
