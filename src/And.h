#ifndef __AND__H__
#define __AND__H__

#include "Connector.h"

class And : public Connector {
    
    String symbol = "&&"; 
    
    public: 
        virtual void connect() {
            
        }

};

#endif