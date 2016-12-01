#ifndef __CD__H__
#define __CD__H__

#include <string>
#include <vector> 
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Inputstorage.h"

bool cd (Inputstorage &val) {
    
    if (val.get_cmd() == "cd") {
        int rc;
        string newDir = val.get_directory();
        //cout << "NEWDIR: " << newDir << endl; 
        if (newDir == "") {
            
            rc = chdir(getenv("HOME"));
            if (rc < 0) {
                perror("cd");
                return false;
            }
            setenv("OLDPWD",getenv("PWD"),1);
            setenv("PWD",getenv("HOME"),1);
        }
        // Case for last directory
        else if (newDir == "-") {
            //cout << getenv("OLDPWD") << endl;
            char * directory;
            directory = (char*)malloc(sizeof(char) * strlen(getenv("PWD")));
            strcpy(directory,getenv("PWD"));
            
            rc = chdir(getenv("OLDPWD"));
            if (rc < 0) {
                perror("cd");
                return false;
            }
            setenv("PWD",getenv("OLDPWD"),1);
            setenv("OLDPWD",directory,1);
            
        } 
        else {
            rc = chdir(newDir.c_str());
            if (rc < 0) {
                perror("cd");
                return false;
            }
            setenv("OLDPWD",getenv("PWD"),1);
            char temp[4096];
            setenv("PWD",(getcwd(temp, 4096) ? string( temp ) : string("")).c_str(),1);
        }
        if (rc < 0) {
                perror("cd");
                return false;
            }
        return true;
    }
    return false;
}
#endif
