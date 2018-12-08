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
  gfx_open(600, 800, "Directions");
  while (directions) {
    gfx_color(170, 184, 255);
    gfx_text(230, 350, "Welcome to Mini-Golf!");
    gfx_text(110, 375, "Click to adjust the direction and speed of your ball. This will be shown as the blue line."); 
    gfx_text(230, 400, "Hit space bar when you are ready to putt.");
    gfx_text(215, 425, "When you are ready to play, hit space bar to continue!");
    if (gfx_event_waiting()) {
      f= gfx_wait();
      if (f==32) {
        break;
      }
    }  
   }
  
  gfx_open(600, 800, "Putt Putt");
  
  while (loop) {
     h1.rotateMill();
     h1.displayarrow();
     if (gfx_event_waiting()) {
       c = gfx_wait();
        h1.displayarrow();
        if (c== 1) {
           h1.changearrow(c);
        }
       if (c== 32) { //space bar to release ball
         win = h1.releaseball();
         if(win)
           goto END;
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
  gfx_open(600, 800, "Win!");
  while (windisplay) {
    gfx_color(170, 184, 255);
   // gfx_change_font( -sony-fixed-medium-r-normal--24-170-100-100-c-120-iso8859-1);
    gfx_text(275, 400, "WINNER!");
    gfx_text(250, 700, "Hit space bar to play again.");
    if (gfx_event_waiting()) {
      d = gfx_wait();
      if (d==32) {
        break;
        goto BEGIN;
      }
    }
  }
  //h1.displayWin();
}
    
    
