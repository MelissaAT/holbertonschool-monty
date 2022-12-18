![Blue Tosca Geometric Technology Linkedln Banner](https://user-images.githubusercontent.com/96942307/208310709-c909a7d1-13cb-4c79-b2c6-b4ec3873eadd.png)


## Description
The goal of this project is to create an interpreter for Monty ByteCodes files. 

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of space before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

### Compilation
The code was compiled using `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

### Task

🦋 Mandatory Task 🦋

| Task    | Description                          |
|---------|--------------------------------------|
| Task 0  | Implement the push and pall opcodes. |
| Task 1  | Implement the pint opcode.           |
| Task 2  | Implement the pop opcode.            |
| Task 3  | Implement the swap opcode.           |
| Task 4  | Implement the add opcode.            |
| Task 5  | Implement the nop opcode.            |

🐼 Advance Task 🐼

| Task   | Description               |
|--------|---------------------------|
| Task 6 | Implement the sub opcode. |
| Task 7 | Implement the div opcode. |
| Task 8 | Implement the mul opcode. |

## Developers

Lizbeth Garcia & Melissa Arroyo
