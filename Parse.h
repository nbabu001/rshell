#ifndef __PARSE__H__
#define __PARSE__H__

#include <iostream>
#include <vector>
#include <string>

#include <boost/tokenizer.hpp>

bool parse(string input) {
    
    //String Tokenizer
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    
    //Pass input into the tokenizer
    tokenizer toke{input};
    
    tokenizer::iterator it;
    it = toke.begin();
    
    bool is_command_only = false;
    String command;
    vector<string> args;
    Connector* temp = 0;
    
    while(it != toke.end()) {
        
        //START OF THE COMMAND
        
        //Exit case
        //Automatically returns false and exits on the other end
        if(it* == "exit") {
            return false;
        }
        
        //Or operator
        else if(*it == "||") {
            temp = new Or();
            it++;
            command = it*;
        }
        
        //And operator
        else if(*it == "&&") {
            temp = new And();
            it++;
            command = it*;
        }
        
        //Semi Operator
        else {
            temp = new Semi();
            command = it*;
        }
        
        // increment the iterator
        it++;
        
        //checks if its a command only
        if (it* == "||" || it* == "&&" || it* == ";") {
            is_command_only = true;
        }
        
        
        while (is_command_only == false) {
            
            if (it* == "#") {
            
                while(it != toke.end() || it* != "||"  || it* != ";" || it* != "&&") {
                    it++;
                    is_command_only = true;
                } 
               
            }
            
            else {
                
                args.push_back(it*);
                it++;
                if(it == toke.end()) {
                    is_command_only = true;
                }
                else {
                    if (it* == "||" || it* == "&&" || it* == ";") {
                        is_command_only = true;
                    }
                }
            
            }
            
            
        }
        
        
        InputStorage input(command, args);
        executecmd(input);
        
        
    }
    
    
}

#endif