# Calculator-RPN
Using Stack and DblyLL to create RPN Calculator

This is a project from my Data Structures class that I worked on. It is a calculator that uses Reverse Polish Notation
in a stack to do mathematical operations. In my Calculus class I used this project to create an integrator calculator
where you can type in a math expression as a string, add the points you want to find the area under and the number of iterations
you want the loop to go through. 

The biggest thing about this calculator is the ability to turn a math string into a math function. This gives the ability to
make composite functions of f(g(x)) do to the f(double) function.

This is do to the use of the RPN converter found in IToP.h . Wherever there is an 'x' in the math string, the x will be replaced by whatever double is place inside the f(double) function. I believe this opens up for an easier method of implimenting Calculus concepts into computer code that is easier to follow and write up. I will be exploring this to see if it is true. Please do not use this to cheat on homework but I do invite people to download the code and.mess around with it to see what they can come up with.

Cheers!
