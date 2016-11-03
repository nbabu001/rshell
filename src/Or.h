#ifndef __OR__H__
#define __OR__H__

#include <iostream>

#include "Connector.h"


class Or : public Connector {
    
    String symbol = "||";
    
    public: 
        virtual string connect() {
            return symbol;
        }

};

#endif