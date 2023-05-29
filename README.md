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

function syntax:

    ={function name}={function body}=    deffinition
    |{function name}|                    function call

for example:

    =func=+[.+]=
    |func|

output:

    123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}   ~�������������������������������������������������������������������������������������������������������������������   �������������

(first few characters are excluded cuz they dont show up on github (trust me they are there))

Instalation for linux:
I made a Makefile with a command called "install" and anotherone "install-deb".
"install-deb" moves the compiled file into local bin folders (aka u can type BF like any other command (for example python) and it will open the interpretor) and "install" just installs it localy to the folder in which you are located so you have to run the file like "./BF"

i recommend:

    make install-deb

roadmap:
maybe i'll add multi file support

a:**well it just means that the program will be reading input directly from the code, so for example if you enable in line reading while executing this code: ",A." the program will output "A" since it reads directly after the "," symbol. If you let's say disable in line reading and while executing the same code (",A.") FBF will ask you to input a character since the "A" after "," will be ignored and after you input your character lets say "h" FBF will output "h"**
