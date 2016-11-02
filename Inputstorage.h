#ifndef Inputstorage_h
#define Inputstorage_h
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;


class Inputstorage{
    protected:
        vector<string> args;
        string cmd;
        
    public:
    Inputstorage(string command, vector<string> arguments)
    :  cmd(command), args(arguments) { cout <<"constructed" << endl;
        cout <<  "command is: " << command << endl;
        cout << "arg 0: "<< args.at(0) << endl;
        cout << "arg 1:" << args.at(1) << endl;
    }
    
    char*  get_cmd(){
        char * cmdpoint = new char[cmd.length() + 1];
        strcpy(cmdpoint, cmd.c_str());
        return cmdpoint;
    }
    
    vector<string>* get_args(){
      return &args;  
    }

    
};
#endif

