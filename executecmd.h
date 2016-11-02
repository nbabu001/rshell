#ifndef executecmd_h
#define executecmd_h
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string>
#include <vector> 
#include <iostream>

#include "Inputstorage.h"

bool executecmd(Inputstorage &val){

     pid_t pid = fork();
     int status;
     pid_t done = wait(&status);
     bool complete = true;
     char * argpoint [2048];
     int i = 0;
     for(i = 0; i < val.get_args()->size(); i++){
          argpoint[i] = (char*)val.get_args()->at(i).c_str();
     }
     argpoint[i+1] = '\0';

     if (pid < 0) {     /* fork a child process           */
          perror("ERROR: forking child process failed");
          complete = false;
          exit(-1);
     }
     else if (pid == 0) {          /* for the child process:         */
          if ((execvp(val.get_cmd(), argpoint)) < 0) {     /* execute the command  */
               perror("ERROR: exec failed");
               complete = false;
               exit(1);
          }
     }
     else {
         if(done == -1){
             perror("Waiting process failed");
             complete = false;
         }/* for the parent:      */       /* wait for completion  */
     }
}
#endif