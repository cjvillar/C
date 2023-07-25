
<img src="c_plain_logo.png" alt="C logo" width="200" height="200">

#  Explore lessons in C  
Sources: 
- The C Programming Language - Brian K
- CS50x
- Practical C Programming (3rd edition) - Steve O
- https://towardsdatascience.com/an-introduction-to-debugging-in-c-and-lldb-part-i-e3c51991f83a
- https://lldb.llvm.org/use/tutorial.html


### compile using:
```C
gcc <program.c>
``
or
```C
gcc -o <out_file_name> <in_file_name.c>
```
For verbose mode:
```C
gcc -o -v <out_file_name> <in_file_name.c>
```
To compile but not link:
```C
gcc -c <in_file_name.c>
```
Create a .o output file that needs to be linked  


### Debug info
```
Use cc -g <program.c> <out>

lldb out

run or some other command
```