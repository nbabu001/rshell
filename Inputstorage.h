#ifndef Inputstorage_h
#define Inputstorage_h
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;


class Inputstorage{
    Protected:
        vector<string> args;
        string cmd;
        
    Public:
    Inputstorage(string command, vector<string> arguements)
    :  cmd(command), args(arguements) {}
    
    char* get_cmd(){
        char * cmdpoint = new char[cmd.length() + 1];
        strcopy(cmdpoint, cmd.c_str())
        return cmdpoint;
    }
    
    char* get_args(){
        string temp;
        for(int x = 0; x < args.size(); x++){
            temp = temp + args.at(x);
            temp = temp + " ";
        }
        temp = temp + "\0"
        char *argpoint = temp.c_str();
        return argpoint;
    }

    
};
#endif

