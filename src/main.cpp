#include <iostream>
#include <string>
#include <vector>

#include "Parse.h"
#include "executecmd.h"
#include "Inputstorage.h"

using namespace std;
int main(int argc, char** argv) {
    
    //Test: ls for executemd, Inputstorage, No args
    // std::vector<string> test(1);
    // Inputstorage fuck("ls", test);
    // bool temp = executecmd(fuck);
    
    //Test: echo for executemd, Inputstorage, run
    // std::vector<string> test(1);
    // test.push_back("run");
    // Inputstorage fuck("echo", test);
    // bool temp = executecmd(fuck, test);
    
    // //Test: ls for executemd, Inputstorage, No args
    // std::vector<string> tpo(1);
    // Inputstorage fu("ls", tpo);
    // bool tep = executecmd(fu, tpo);
    
    //Test: echo for executemd, Inputstorage, run
    // std::vector<string> test(1);
    // Inputstorage fuck(";", test);
    // bool temp = executecmd(fuck);
    cout << "TRUE: " << true << endl;
    
    while(1) {
        //print $user@host()
        string str;
        getline(cin, str);
        if (!parse(str)) {
            // if exit is called 
            break;
        }
    }
   
    
    return 0;
}



