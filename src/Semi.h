#ifndef __SEMI__H__
#define __SEMI__H__

#include "Connector.h"

class Semi : public Connector {
    
    String symbol = ";"; 
    
    public: 
        virtual void connect() {
            
        }

};

#endif