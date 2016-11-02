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

bool executecmd(Inputstorage &val, vector<string> &v){

      char * argus[1024];
    //bool success = true; //this will be function return value
    //obtain user command
    string scmd = val.get_cmd();
    //if(cmd == "exit"){ //checks for exit command
        //loop = false;
        //break;
      //  exit(0);
    //}
    
    argus [0] = (char*)scmd.c_str(); //place cmd at front of array
    
    
    //fill rest of array with arguments then null character
    unsigned i = 0;
    for(i = 0; i < v.size(); ++i){
        argus[i+1] = (char*)v.at(i).c_str();
    }
    //add null character at end
    argus [i+1] = '\0';
    
     //pid_t pid = fork();
     //int status;
     //pid_t done = wait(&status);
     bool complete = true;
     //char * argpoint [2048];
     //int i = 0;
     //for(i = 0; i < val.get_args()->size(); i++){
     //     argpoint[i] = (char*)val.get_args()->at(i).c_str();
     //}
     //argpoint[i+1] = '\0';
     
     pid_t pid = fork();

     if (pid < 0) {     /* fork a child process           */
          perror("ERROR: forking child process failed");
          complete = false;
          exit(-1);
     }
     else if (pid == 0) {          /* for the child process:         */
          if ((execvp(argus[0], argus)) < 0) {     /* execute the command  */
               perror("ERROR: exec failed");
               complete = false;
               exit(1);
          }
     }
     else {
         if(wait(0) == -1){
             perror("Waiting process failed");
             complete = false;
         }/* for the parent:      */       /* wait for completion  */
     }
}
#endif