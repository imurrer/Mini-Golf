//project.cpp
// Bella Murrer and Hannah Sarkey

#include "golf.h"

int main() {
  Golf h1;
  bool loop = true;
  bool win  = false;
  bool directions = true;
  bool windisplay = true;
  char c, d, f;
  
  BEGIN: { }

  gfx_open(600, 800, "Putt Putt");
  
  while (directions) {
    gfx_color(170, 184, 255);
    gfx_text(210, 350, "Welcome to Mini-Golf!");
    gfx_text(30, 375, "Click to adjust the direction and speed of your ball. This will be shown as the blue line."); 
    gfx_text(170, 400, "Hit space bar when you are ready to putt.");
    gfx_text(195, 650, "If you are ready to play, hit p!");
    if (gfx_event_waiting()) {
      c= gfx_wait();
      if (c=='p') {
        break;
      }
    }  
   }
  while (loop) {
     h1.display();
     h1.rotateMill();
     h1.displayarrow();
     if (gfx_event_waiting()) {
       c = gfx_wait();
       h1.displayarrow();
       if (c== 1) {
          h1.changearrow(c);
          c = gfx_wait();
        }
       if (c== 32) { //space bar to release ball
         win = h1.releaseball();
         if(win)
           goto END;
         c = gfx_wait();
       }
       if (c == 'q') {
         break;
       }
     }
     gfx_flush();
     usleep(70000);
     gfx_clear();
  }
  END: {}
  if (win) {
    gfx_clear();
    while (windisplay) {
      gfx_color(170, 184, 255);
      gfx_changefont('12x24' );
      gfx_text(275, 400, "WINNER!");
      gfx_text(250, 700, "Hit a to play again.");
      if (gfx_event_waiting()) {
        d = gfx_wait();
        if (d=='a') {
          break;
          goto BEGIN;
        }
      }
    }
  }
  //h1.displayWin();
}
    
    
