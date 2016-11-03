### rshell
    The rshell we created acts as a basic shell terminal and executes basic shell commands and terminates when an exit is called.
    
#### Program Features
  - Basic bash commands work such as echo, ls, mkdir, pwd, etc..
  - &&, ||, ;, connectors are added to help the user connect statements and verify their proper execution
  - && will only happen if both statements run properly, || will only happen if one of them is true, ; execute the next command no matter what
  - If exit is entered then the program will terminate
  - # the pound key is implemented so that the user can add comments in the terminal
  - The terminal also gets in the userlogin info and the host information and displays it
  
#### Bugs
  - Our arguement array size has been set to only 2048 so if the arguements exceed that size we will have a problem because we don't allocate more memory to it
  - Our program is executing an extra command when the arguements are and'd and then or'd with two more arguements
  - Our program doesn't stop running when exit is called need to quit program by crtl-c
  - Since our get host array only of size 2048 it will through an error if the user hosts name is much larger than it
  
  
#### Installation  
    $ git clone https://github.com/nbabu001/rshell.git
    $ cd rshell
    $ git checkout hw2
    $ make
    $ bin/rshell

    


