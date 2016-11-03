#ifndef __INPUTSTORAGE_H__
#define __INPUTSTORAGE_H__
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;


class Inputstorage{
    protected:
        string cmd;
        vector<string> args;
        
        
    public:
    Inputstorage(string command, vector<string> arguments)
    :  cmd(command), args(arguments) {}
    // gets the command as a char* to a c string so it's easier to put into execvp
        char *ret_cmd(){
        char * cmdpoint = new char[cmd.length() + 1];
        strcpy(cmdpoint, cmd.c_str());
        return cmdpoint;
    }
    // returns a pointer to the vector of arguements so easy to access in the execvp function
    vector<string>* get_args(){
      return &args;  
    }

    
};
#endif

