#include <iostream>
#include <string>
#include <vector>

#include "Parse.h"
#include "executecmd.h"
#include "Inputstorage.h"


using namespace std;
int main(int argc, char** argv) {
    while(1) {
        
    //this array will hold the host info
    char hostinfo[2048];
    hostinfo[2047] = '\0';
    // this char* will hold the info to user 
    char *userlogin;
    // get login
    userlogin = getlogin();
    // get user
    gethostname(hostinfo, 2047);
    int i = 0;
    //output user info
    while(userlogin[i] != '\0'){
        cout << userlogin[i];
        i++;
    }
    cout << "@";
    int x = 0;
    //output host info
    while(hostinfo[x] != '\0'){
        cout << hostinfo[x];
         x++;
     }
     cout << "$ ";
         
        string str;
        getline(cin, str);
        if (!parse(str)) {
            // if exit is called 
            break;
        }
    }
   
    
    return 0;
}



