Extended SIC architecture assembler
============================================
Links:
-----------------------------------
Wikipedia: https://en.wikipedia.org/wiki/Simplified_Instructional_Computer
Documentation: https://www.unf.edu/~cwinton/html/cop3601/supplements/test.html


Function:
===========================================================
Control Section

Addressing Mode (Flag bit)

Direct Addressing Mode

Indirect Addressing Mode

Simple Addressing Mode

Immediate Addressing Mode

Relative Addressing Mode

Program Counter (PC Register)

Base (Base Register)

Extended Instruction (4bit Instruction)

How it works :
=======================================================
Assign addresses to all statements in source code

Save values (addresses) assigned to labels for use in pass two

Process directives

Translate instructions

Convert labels to addresses

Generate values defined by BYTE and WORD

Process the directives not done in pass one

Write object code



sample output:
=================================
![image](https://user-images.githubusercontent.com/29634012/218253835-1f718d6e-bae7-4f6d-860c-612952be0937.png)

![image](https://user-images.githubusercontent.com/29634012/218253845-7b54927c-1834-4eac-869a-5970948b61bc.png)

![image](https://user-images.githubusercontent.com/29634012/218253868-60b5261e-4dc9-471b-b63c-c4bb118364b1.png)

To Do:
---------------------
[1]Continue implementation of linker and loader

[2]Add GUI
