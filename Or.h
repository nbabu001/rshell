#ifndef __OR__H__
#define __OR__H__

#include "Connector.h"

class Or : public Connector {
    
    String symbol = "||"; 
    
    public: 
        virtual void connect() {
            
        }

};

#endif