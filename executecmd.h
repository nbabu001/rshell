#ifndef executecmd_h
#define executecmd_h
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include <iostream>
#include "Inputstorage.h"

bool executecmd(Inputstorage &val){

     pid_t pid == fork();
     int status;
     pid_t done = wait(&status);
     bool complete = true;

     if ((pid < 0) {     /* fork a child process           */
          perror("ERROR: forking child process failed");
          complete = false;
          exit(-1);
     }
     else if (pid == 0) {          /* for the child process:         */
          if (execvp(val.get_cmd(), val.get_args()) < 0) {     /* execute the command  */
               perror("ERROR: exec failed");
               complete = false;
               exit(1);
          }
     }
     else {
         if(done == -1){
             perror("Waiting process failed")
             complete = false;
         }/* for the parent:      */       /* wait for completion  */
     }
}
#endif