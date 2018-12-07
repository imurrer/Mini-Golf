//main.cpp

#include "gfx2.h"

int main() {
  bool loop = true;
  gfx_open(600, 800, "Putt Putt");
  
  while (loop) {
    float bx = 100, by = 550;
    float mx = 200, my = 250;
    float tx = 100, ty = 50;
    float l = 400, w = 200;
    float ml = 300, mw = 200;
    
    gfx_color(29, 147, 41);
    gfx_fill_rectangle(tx, ty, w, l);
    gfx_fill_rectangle(mx, my, mw, ml);
    gfx_fill_rectangle(bx, by, w, l);
    
    
