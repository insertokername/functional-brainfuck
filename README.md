# functional-brainfuck

basically just a brainfuck interpreter but has functions implemented

- `+` increment the current cell's value
- `-` decrement the current cell's value
- `<` move the cell pointer left
- `>` move the cell pointer right
- `[` start a loop
- `]` end a loop
- `,` read a char
- `.` print a char

and the new symbols:

- `q` quits out of the command line/file
- `=` function definition limiter
- `|` function call limiter
- `#` include limiter

function syntax:

    ={function name}={function body}=    deffinition
    |{function name}|                    function call

include syntax:
    
    #{file-name#{in_line_input *go to faq section to understand what that means)}#

for example we we'll make a file called `include_me.bfb` with the following contents:
    
    =func=+[.+]=

and we run in console:
    
    #include_me.bfb#0#
    |func|

output:

    123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}   ~�������������������������������������������������������������������������������������������������������������������   �������������

---
**important:**

**BFB will automatically try to run a function named "main" [THIS ONLY HAPPENS WHEN RUNNING A FILE] if its not found it will throw an error**

**BFB will run in_line on console and will not run with in_line on file read mode**

---

(first few characters are excluded cuz they dont show up on github (trust me they are there))

Instalation for linux:
I made a Makefile with a command called "all" and anotherone "install-linux".
"install-linux" moves the compiled file into local bin folders (aka u can type BF like any other command (for example python) and it will open the interpretor) and "all" just installs it localy to the folder in which you are located so you have to run the file like "./BF" while being in the project folder in a command line

i recommend (for linux):

    make install-linux

will be making a windows tool in the future...

## faq
q:**what does "in_line_reading" or "in_line" mean?**

a:**well it just means that the program will be reading input directly from the code, so for example if you enable in line reading while executing this code: ",A." the program will output "A" since it reads directly after the "," symbol. If you let's say disable in line reading and while executing the same code (",A.") FBF will ask you to input a character since the "A" after "," will be ignored and after you input your character lets say "h" FBF will output "h"**
