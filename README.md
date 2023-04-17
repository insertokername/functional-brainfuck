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

and a new symbol:

* `q` quits out of the command line/file



function defintion syntax:

    |{function name}|{function body}|

for example:

    |func|    