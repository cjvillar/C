/*
In this code, the .intel_syntax noprefix directive is used to switch to Intel syntax, which is used in the inline assembly code provided. 
The code then performs the same system calls as the inline assembly code, using the mov instruction to load the system call number, file handle, 
address of the message string, and length of the message into the appropriate registers.

The syscall instruction is used to make the system call to output the message to the console and then to exit the program. The .att_syntax prefix directive 
is used to switch back to AT&T syntax, which is the default syntax used by the GCC compiler.

The clobbered registers are specified to ensure that the compiler does not use them for other purposes while the inline assembly code is executing.

Note that this code assumes that you are running on a 64-bit x86-based system, and the code may need to be modified if you are using a different system 
architecture or a different system call interface. Also, the string "Hello, World!\n" is declared outside the inline assembly code as a global constant to make 
it easier to reference from the assembly code.

In this code, the lea instruction is used to load the address of the message string into the rdi register using RIP-relative addressing. The mov instruction is then
used to load the system call number, file handle, and message length into the appropriate registers, and the syscall instruction is used to make the system call to 
output the message to the console and exit the program.

*/
#include <stdio.h>

int main() {
    asm (".intel_syntax noprefix;" // switch to Intel syntax
         "lea rdi, [rip + _message];" // load address of message
         "mov rax, 0x2000004;"    // system call for write
         "mov rsi, rdi;"          // use address in RDI as second argument
         "mov rdx, 14;"           // length or number of bytes
         "mov rdi, 1;"            // file handle 1 is stdout
         "syscall;"               // call kernel to do the write
         "mov rax, 0x2000001;"    // system call for exit
         "xor rdi, rdi;"          // exit code 0
         "syscall;"               // call kernel to exit
         ".att_syntax prefix;"    // switch back to AT&T syntax
         :
         :
         : "rax", "rdi", "rsi", "rdx" // clobbered registers
    );

    return 0;
}

const char message[] = "Hello, World!\n";
