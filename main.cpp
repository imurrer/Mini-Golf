//main.cpp
// Bella Murrer and Hannah Sarkey

#include "gfx3.h"
#include <iostream>
using namespace std;

int main() {
  bool loop = true;
  char c;
  gfx_open(600, 800, "Putt Putt");
  
  Golf h1;
  
  while (loop) {
     if (gfx_event_waiting()) {
       c = gfx_wait();
       if (c == 'q') {
         break;
       }
     }
     h1.display();
     
    //switch(c) {
     //   case 
   
  }
}
    
    
