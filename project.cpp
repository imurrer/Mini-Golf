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
        h1.display();
        h1.rotateMill();
        h1.displayarrow();
        //if ((c=='R') || (c=='S') || (c=='T') || (c=='Q')) {
        //  h1.changearrow(c);
        //}
      // if (c== '32') { //space bar to release ball
       //  h1.releaseball();
      // }
       if (c == 'q') {
         break;
       }
       gfx_flush();
       usleep(70000);
       //gfx_clear();
     }
  }
}
    
    
