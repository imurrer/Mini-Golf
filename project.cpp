//project.cpp
// Bella Murrer and Hannah Sarkey

#include "golf.h"

int main() {
  Golf h1;
  bool loop = true;
  char c;
  gfx_open(600, 800, "Putt Putt");
  
  while (loop) {
     if (gfx_event_waiting()) {
       c = gfx_wait();
       if (c == 'q') {
         break;
       }
     }
     h1.display();
     h1.rotateMill();
     
    //switch(c) {
     //   case 
   
  }
}
    
    
