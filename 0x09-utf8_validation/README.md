# UTF-8 Validation

Exercise to practice for interviews

## Context

### 0. UTF-8 Validation

Write a method that determines if a given data set represents a valid UTF-8 encoding.

* Prototype: `def validUTF8(data)`
* Return: `True` if data is a valid UTF-8 encoding, else return `False`
* A character in UTF-8 can be 1 to 4 bytes long
* The data set can contain multiple characters
* The data will be represented by a list of integers
* Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer

```
$ cat 0-main.c
#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

data = [229, 65, 127, 256]
print(validUTF8(data))

$ ./0-main.py
True
True
False
$
```
