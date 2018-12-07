//golf.h

#include <iostream>
#include "gfx3.h"

class Golf {
  public:
    Golf();
    ~Golf();
    void display();
  /*
    void rotateMill();
    void throughMill();
    void ballAngle();
    void ballSpeed();*/
  private:
    float angWM;
    float bx, by, ty, tx, l, w;
    float mx, my, ml, mw;
    float hx, hy, hw, hl, a1, a2;
    float arrowX, arrowY;
};
