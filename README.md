# functional-brainfuck

basically just a brainfuck interpreter but has functions implemented (FBF for short)

symbols:

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
- `~` adds a newline and "---" to the log file

function syntax:

    ={function name}={function body}=    definition
    |{function name}|                    function call

include syntax:

    #{file-name}#{in_line_input *go to faq section to understand what that means}#

for example we we'll make a file called `include_me.fbf` with the following contents:

    =func=+[.+]=

and we run in console:

    #include_me.fbf#0#
    |func|

output:

    123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}   ~�������������������������������������������������������������������������������������������������������������������   �������������

(first few characters are excluded cuz they dont show up on github (trust me they are there))

---

**important:**

**FBF will automatically try to run a function named "main" (THIS ONLY HAPPENS WHEN RUNNING A FILE IT WILL NOT HAPPEN WHEN RUNNING FORM CONSOLE) if its not found it will throw an error ANY GLOBAL CODE WILL BE EXECUTED BEFORE MAIN, EVEN CODE THAT IS UNDER MAIN DEFINITION**

**FBF will run with in_line turned on while in console and will run with in_line turned of while in file read mode**

**any function definition of an allready defined function will override the old function definition that includes functions defined whitin an included file**

---

## prerequisites:

linux: git,make,g++

## instalation:

linux(building the project):

    sudo git clone https://github.com/insertokername/functional-brainfuck.git ~/functional-brainfuck

    cd functional-brainfuck

    sudo make install-linux

then you can just open up a terminal and type "FBF -h"

will be making a windows tutorial in the future...

## faq:

q:**what does "in_line_reading" or "in_line" mean?**

a:**well it just means that the program will be reading input directly from the code, so for example if you enable in line reading while executing this code: ",A." the program will output "A" since it reads directly after the "," symbol. If you let's say disable in line reading and while executing the same code (",A.") FBF will ask you to input a character since the "A" after "," will be ignored and after you input your character lets say "h" FBF will output "h"**
