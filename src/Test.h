#ifndef __TEST_H__
#define __TEST_H__
#include <string>
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include "Inputstorage.h"

bool test(Inputstorage &val) {
    
      struct stat s;
      string test = val.get_test();
      string path = val.get_path();
      //cout << "THIS IS THE PATH:  " << path << endl;
      if(stat(path.c_str(),&s) == 0)
      {
          if (test == "-d") {
               if( s.st_mode & S_IFDIR )
               {
                   return true;
               }
               return false;
          }
          if (test == "-f") {
               if( s.st_mode & S_IFREG )
               {
                   return true;
               }
               return false;
          }
          else
          {
              return true;
          }
      }
      else
      {
          return false;
      }
      
}
#endif