#ifndef __EXECUTECMD_H__
#define __EXECUTECMD_H__
#include <string>
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>
#include "Inputstorage.h"

bool executecmd(Inputstorage &val){
     bool complete = true;
     char * argpoint [2048];
     pid_t pid = fork();
     //gets the command from the class passed in by reference and gets put into array
     argpoint[0] = val.ret_cmd();
     unsigned x;
     //turns the vector of arguements into a c string to be put into array for execvp
     for(x= 0; x < val.get_args()->size(); x++){
          argpoint[x+1] = (char*)val.get_args()->at(x).c_str();
     }
     // adds null character at end 
     argpoint[x+1] = '\0';
     // starts to execute command
     
    int ex;

     //if pid < 0 then forking error
     if (pid < 0) { 
          perror("ERROR: forking child process failed");
          complete = false;
          return complete;
          exit(-1);
     }
     // if pid == 0 then execute and check for execution failed case
     else if (pid == 0) {         
          if ((execvp(argpoint[0], argpoint)) < 0) {     
               perror("ERROR: exec failed");
               complete = false;
               //return complete;
               exit(1);
          }
     }
     // if pid > 0 in parent and wait for child to finish process
     else {
         {
         if(waitpid(pid, &ex, 0) == -1){
             perror("Waiting process failed");
             complete = false;
             return complete;
             }
             return ex == 0;
         }
     }
     return complete;
}
#endif