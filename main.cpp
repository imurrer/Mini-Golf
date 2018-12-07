//main.cpp
// Bella Murrer and Hannah Sarkey

#include "gfx2.h"
#include <iostream>
using namespace std;

int main() {
  bool loop = true;
  char c;
  gfx_open(600, 800, "Putt Putt");
  
  while (loop) {
    c= gfx_wait();
    gfx_clear();
    switch(c) {
        case '
    
    float bx = 100, by = 550;
    float mx = 200, my = 250;
    float tx = 100, ty = 50;
    float l = 400, w = 200;
    float ml = 300, mw = 200;
    float hx= 192.5 , hy= 538 , hl = 15, hw = 12, a1 =0, a2 =180;
    
    gfx_color(29, 147, 41);
    gfx_fill_rectangle(tx, ty, l, w);
    gfx_fill_rectangle(mx, my, mw, ml);
    gfx_fill_rectangle(bx, by, l, w);
    
    gfx_color(0, 0, 0);
    gfx_fill_arc(hx, hy, hw, hl, a1, a2);
    
    }
  }
    
    
