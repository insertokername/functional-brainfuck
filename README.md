# functional-brainfuck
basically just a brainfuck interpreter but has functions implemented

* `+` increment the current cell's value
* `-` decrement the current cell's value
* `<` move the cell pointer left
* `>` move the cell pointer right
* `[` start a loop
* `]` end a loop
* `,` read a byte
* `.` print a byte

and the new symbols:

* `q` quits out of the command line/file
* `=` function definition limiter
* `|` function call limiter


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

and yea that's it have fun ig 



