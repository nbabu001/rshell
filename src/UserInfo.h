#ifndef __USERINFO_H__
#define __USERINFO_H__
#include <iostream>
#include <unistd.h>
#include <stdio.h>
using namespace std;

void get_info(){
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
}
#endif