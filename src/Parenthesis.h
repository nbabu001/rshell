#ifndef __PARENTHESIS__H__
#define __PARENTHESIS__H__

#include <vector>
#include <string>
#include "Connector.h"
#include "Inputstorage.h"
#include "Test.h"
#include "executecmd.h"
#include "Parse.h"
#include <boost/tokenizer.hpp>
#include <boost/range/iterator_range.hpp>

typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

void parenthesisParse(tokenizer::iterator &it, tokenizer &toke) {
    
    bool status = true;
    int count = 0;
    vector<string>placeholder(1);
    string current;
    ++it;
    
    count = 1;
    while(it != toke.end() && status){
        placeholder.at(0) = *it;
        current = placeholder.at(0);
        if(current == "("){
            count++; //number of internal parenthesis
        }
        if(current == ")"){
            count--;
            if(count == 0){
                status = false;
            }
        }
        
        ++it;
    }
    status = true;
    while(it != toke.end() && status){
        placeholder.at(0) = *it;
        current = placeholder.at(0);
        //cout << "current = " << current << endl;
        if(current == ";" || current == "|" || current == "&" || current == ")"){
            status = false;
            break;
        }
            ++it;
    }

}

#endif