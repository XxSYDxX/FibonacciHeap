# FibonacciHeap
 The C++ implementation of the Fibonacci Heap Data Structure

The following operations have been implemented:
1) Make Node
2) Insert Node
3) Extract Min or Delete Min

![alt text](https://raw.githubusercontent.com/XxSYDxX/FibonacciHeap/main/screenshots/Display%20%26%20Extract%20Min.jpg)

4) Decrease Key

![alt text](https://raw.githubusercontent.com/XxSYDxX/FibonacciHeap/main/screenshots/Decrease%20Key.jpg)

5) Delete Note

![alt text](https://raw.githubusercontent.com/XxSYDxX/FibonacciHeap/main/screenshots/Delete%20Node.jpg)

6) Display


This is my implementation of the Fibonacci Heap Data Structure.
I made it in a day, so it must have a lot of undetected bugs. ***Please let me know if you find any***.
This implementation might not be the most efficient, but everything is consisent with the theory.
This implementation has made use of doubly circular linked lists. One of weirdest things I did here, was to manually count the length of the rank array used in extract min. I had also noticed that the length is not the rank of the tree before deletion of min, which it is according to most textbooks. If there are multiple nodes with the maximum rank, they can combine and increase the rank of the tree which will be more than the length of the rank array, and not fit inside it (throw index out of bounds in python implementations). So I increased the length by the number of nodes sharing the maximum rank. I'm not sure if that is staying consistent with the actual concept. So help me out.
Let me know if you find any inconsistency as well.
