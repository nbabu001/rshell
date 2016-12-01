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
    :  cmd(command), args(arguments) {
        // for (unsigned int i = 0; i < args.size(); i++) {
        //     cout << args.at(i) << endl;
        // }
    }
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
    
    string get_cmd() {
        return cmd;
    }
    
    string get_test() {
        string test;
        if (args.size() >= 1) {
            test = args.at(0);
        }
        return test;
    }
    
    string get_path() {
        string path = "";
        for (unsigned int i = 1; i < args.size(); i++) {
            //cout << args.at(i) << endl;
            path = path + args.at(i);
        }
        return path;
    }
    
    string get_directory() {
        string path = "";
        if (args.size() == 0) {
            return path;
        }
        for (unsigned int i = 0; i < args.size(); i++) {
            //cout << args.at(i) << endl;
            path = path + args.at(i);
        }
        return path;
    }
    
};
#endif

