# VirtualClock
The project is a clock program that displays the current time in either 12-hour or 24-hour clock format and allows the user to adjust the time by adding seconds, minutes, or hours, changing the clock format, and setting the time zone. The program aims to solve the problem of keeping track of time accurately and conveniently.

One aspect that is done particularly well in the code is the use of object-oriented programming principles. The Clock class encapsulates the properties and methods related to a clock, making the code more modular and maintainable. The switch statement in the main function is also well-organized and easy to read, making it clear what actions the user can take.

There are several areas where the code could be enhanced to make it more efficient and secure. One area is input validation, as the program does not currently check for invalid user inputs, which could lead to errors or crashes. Another area is error handling, as the program does not have any provisions for handling unexpected errors that may occur during runtime. Adding these features would make the program more robust and user-friendly.

One of the most challenging pieces of code to write was the displayClock function, as it involves converting the time to the correct clock format and displaying it along with the time zone information. To overcome this challenge, the code uses conditional operators and string concatenation to format the output correctly. The use of the localtime function from the <ctime> library also helped to simplify the code.

The skills from this project that will be transferable to other projects or coursework include object-oriented programming, input/output operations, and handling user input. These skills are foundational to many programming tasks and will be useful in a variety of contexts.

To make the program maintainable, readable, and adaptable, the code follows best practices such as using descriptive variable names, modularizing the code with functions and classes, and commenting the code where necessary. The program is also designed to be easily customizable, with options to change the clock format and time zone, making it adaptable to different user needs.
