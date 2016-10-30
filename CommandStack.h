#ifndef __COMMANDSTACK__H__
#define __COMMANDSTACK__H__

#include <vector>
#include <String>
 
class CommandStack {
    
    private:
        std::vector<String> connectors;
        std::vector<String> executables;
        
    
    public: 
        virtual void connect() = 0;

};

#endif