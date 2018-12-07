//golf.cpp
//Bella Murrer and Hannah Sarkey

#include "golf.h"
#include <iostream>
using namespace std;

Golf::Golf() {
   float ballx = 300, bally = 740, ballrad = 7.5;
   float bx = 100, by = 550;
   float mx = 200, my = 250;
   float tx = 100, ty = 50;
   float l = 400, w = 200;
   float ml = 300, mw = 200;
   float hx= 287.5 , hy= 537.5 , hl = 25, hw = 20, a1 =0, a2 =180;
}

Golf::~Golf() { }

void Golf::display() {
   gfx_color(29, 147, 41); // green course
    gfx_fill_rectangle(tx, ty, l, w);
    gfx_fill_rectangle(mx, my, mw, ml);
    gfx_fill_rectangle(bx, by, l, w);
    
    //Ms. Ball
    gfx_color(255, 255, 255);
    gfx_fill_circle(ballx, bally, ballrad);
       
    gfx_color(170, 184, 255);  //the windmill herself
    gfx_fill_rectangle(250, 400, 100, 150);
    //her lucious triangles
    XPoint pt = {200, 550};
    XPoint mypoints1[] = { {200, 550}, {250, 400}, {250, 550} };
    XPoint mypoints2[] = { {350, 550}, {350, 400}, {400, 550} };
    int size1 = sizeof(mypoints1)/sizeof(pt);
    gfx_fill_polygon(mypoints1, size1);
    gfx_fill_polygon(mypoints2, size1);
    
    gfx_color(0, 0, 0); // hole arc & hole
    gfx_fill_arc(hx, hy, hw, hl, a1, a2);
    gfx_fill_circle(150, 100, 10);

    gfx_color(0,43,4); // dropoff line
    gfx_line(200, 250, 400 , 250);
}

/*
void Golf::rotateMill() {
  
}

bool Golf::throughMill() {
  
}

float Golf::ballAngle() {

}

float Golf::ballSpeed() {

}*/


