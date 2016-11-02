#ifndef __PARSE__H__
#define __PARSE__H__

#include <vector>
#include <string>
#include "Connector.h"
#include "Inputstorage.h"
#include "executecmd.h"
#include <boost/tokenizer.hpp>
#include <boost/range/iterator_range.hpp>

// string convert(tokenizer::iterator &it, vector<string> &conversion) {
//     conversion.at(0) = it*;
//     string result = conversion.at(0);
//     return result;
// }

bool parse(string input) {
    
    cout << "1: inside parse: " << input << endl;
    //String Tokenizer
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    
    //Pass input into the tokenizer
    tokenizer toke(input);
    
    //Initialize iterator to the begining of toke
    tokenizer::iterator it = toke.begin();
    
    //Data fields used for looping
   
  
    
    Connector* temp = 0;
    string type = "";
    
    while(it != toke.end()) {
        string command = "DID NOT UPDATE COMMAND";
        vector<string> args;
        args.push_back("");
        
        string tester;
        string compare;
        vector<string> placeholder(1);
        
        bool is_command_only = false;
        bool skipper = false;
        
        cout << "=================" << endl;
        //START OF THE COMMAND
        
        //Exit case
        //Automatically returns false and exits on the other end
        if(input ==  "exit") {
            cout << "returned false";
            return false;
        }
        
        //strcmp((*it).c_str(), "|"))
        placeholder.at(0) = *it;
        compare = placeholder.at(0);
        
        
        
        //Or operator
        if(compare == "|") {
            type = "o";
            it++;
            placeholder.at(0) = *it;
            command = placeholder.at(0);
            cout << "Inside or" << command << endl;
        }
        
        //And operator
        else if(compare == "&") {
            type = "a";
            it++;
            placeholder.at(0) = *it;
            command = placeholder.at(0);
             cout << "Inside and" << command << endl;
        }
        
        //Semi Operator
        else if (compare == ";") {
            type = "s";
            command = compare;
            cout << "Inside and" << command << endl;
            
             
        }
        else {
            type = "s";
            command = compare;
            cout << "Inside semi: " << command << endl;
        }
        
        
        // increment the iterator
        if (it != toke.end()) {
            it++;
            if (it != toke.end()){
                placeholder.at(0) = *it;
                compare = placeholder.at(0);
                cout << "this" << endl;
            }
            else {
                is_command_only = true;
                cout << "that" << endl;
            }
        }
        
        
        //checks if its a command only
        if (compare == "|" | compare == "&" | compare == ";") {
            is_command_only = true;
        }
        
        //If it isnt the end of the command
        while (is_command_only == false) {
            
            //Comment checking
            if (compare ==  "#") {
                
                bool comment = true;
                string check;
                //Loop 
                while(comment) {
                    it++;
                    
                    if(it == toke.end()) {
                            is_command_only = true;
                            comment = false;
                            
                    }
                    else {
                        
                        placeholder.at(0) = *it;
                        check = placeholder.at(0);
                        
                        if(check == "|"){
                            is_command_only = true;
                            comment = false;
                        }
                        if(check == "&"){
                            is_command_only = true;
                            comment = false;
                        }
                        if(check == ";"){
                            is_command_only = true;
                            comment = false;
                        }
                    }
                   
                } 
               
            }
            else {
                placeholder.at(0) = *it;
                tester = placeholder.at(0);
                cout << "tester is: " << tester << endl;
                args.push_back(tester);
                it++;
                if(it == toke.end()) {
                    is_command_only = true;
                }
                else {
                    placeholder.at(0) = *it;
                    compare = placeholder.at(0);
                    if (compare == "|" || compare == "&" | compare == ";") {
                        is_command_only = true;
                        
                    }
                }
            }
        }
        
       
        Inputstorage inputS(command, args);
        if (type == "s") {
            is_command_only = executecmd(inputS,args);
        }
        
        
        if (type == "s" & it != toke.end()) {
            it++;
        }
        
    }
    
    
}




#endif