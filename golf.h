//golf.h

#include <iostream>
#include "gfx3.h"
#include <unistd.h>
#include <cmath>
#include <math.h>
using namespace std;

class Golf {
  public:
    Golf();
    ~Golf();
    void display();
    void rotateMill(); 
    void displayarrow();
    void changearrow(char);
    void releaseball();
    void throughMill();
    /*void ballAngle();
    void ballSpeed();*/
  private:
    float angWM;
    float bx, by, ty, tx, l, w;
    float mx, my, ml, mw;
    float hx, hy, hw, hl, a1, a2;
    float ballx, bally, ballrad;
    float arrowx, arrowy;
    float millcentX, millcentY, triX1, triY1, triX2, triY2;
    float angmill1, angmill2, radmill;
    float radline, angline;
};
