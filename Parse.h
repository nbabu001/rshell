#ifndef __PARSE__H__
#define __PARSE__H__

#include <iostream>
#include <vector>
#include <string>

#include <boost/tokenizer.h>

bool parse(string input) {
    
    //String Tokenizer
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    
    //
    tokenizer toke{input};
    
    tokenizer::iterator it;
    it = toke.begin();
    
    Connector* temp = 0;
    String command;
    vector<string> args;
    
    while(it != toke.end()) {
        
        if (it* == "exit") {
            return false;
        }
        
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
}

