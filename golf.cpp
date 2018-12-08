//golf.cpp
//Bella Murrer and Hannah Sarkey

#include "golf.h"

Golf::Golf() {
   ballx = 300, bally = 740, ballrad = 7.5;
   bx = 100, by = 550;
   mx = 200, my = 250;
   tx = 100, ty = 50;
   l = 400, w = 200;
   ml = 300, mw = 200;
   hx= 287.5 , hy= 537.5 , hl = 25, hw = 20, a1 =0, a2 =180;
   millcentX = 300, millcentY = 400, triX1 = 270, triY1 = 250, triX2 = 330, triY2 = 250;
   triX3 = triX2, triY3 = triY2+2*(millcentY-triY2), triX4 = triX1, triY4 = triY1+2*(millcentY-triY1);
   radmill = pow(pow(millcentX-triX2, 2)+pow(millcentY-triY2, 2), .5);
   angmill1 = acos((triX2-millcentX)/radmill);
   angmill2 = angmill1+2*atan((triX2-triX1)*.5/radmill);
   angmill3 = M_PI+angmill1;
   angmill4 = M_PI+angmill2;
   arrowx = 300, arrowy =675;
   radline =pow(pow(arrowx-ballx, 2) + pow(arrowy-bally,2), 0.5), angline = M_PI/2;
}

Golf::~Golf() { }

void Golf::resetplacements() {
   ballx = 300;
   bally= 740;
   arrowx= 300;
   arrowy = 675;
}

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


void Golf::rotateMill() {
  //first top triangle
  XPoint pt = {(short)millcentX, (short)millcentY};
  XPoint mypoints1[] = { {(short)millcentX, (short)millcentY}, {(short)triX1, (short)triY1}, {(short)triX2, (short)triY2} };
  XPoint mypoints2[] = { {(short)millcentX, (short)millcentY}, {(short)triX3, (short)triY3}, {(short)triX4, (short)triY4} };
  int size1 = sizeof(mypoints1)/sizeof(pt);
  gfx_color(192, 242, 247);
  gfx_fill_polygon(mypoints1, size1);
  gfx_fill_polygon(mypoints2, size1);
  angmill1+=M_PI/6;
  angmill2+=M_PI/6;
  triX1 = triX1+(radmill*(cos(angmill1-M_PI/6)-cos(angmill1)));
  triY1 = triY1+(radmill*(sin(angmill1-M_PI/6)-sin(angmill1)));
  triX2 = triX2+(radmill*(cos(angmill2-M_PI/6)-cos(angmill2)));
  triY2 = triY2+(radmill*(sin(angmill2-M_PI/6)-sin(angmill2)));
  angmill3+=M_PI/6;
  angmill4+=M_PI/6;
  triX3 = triX3+(radmill*(cos(angmill3-M_PI/6)-cos(angmill3)));
  triY3 = triY3+(radmill*(sin(angmill3-M_PI/6)-sin(angmill3)));
  triX4 = triX4+(radmill*(cos(angmill4-M_PI/6)-cos(angmill4)));
  triY4 = triY4+(radmill*(sin(angmill4-M_PI/6)-sin(angmill4)));
}

void Golf::displayarrow() {
   gfx_color(24, 60, 242);
 //  if ((bally >=550) && (bally <= 750)) {
   gfx_line(ballx, bally, arrowx, arrowy);
//   }
  // if ((bally <=250) && (bally >=50)) {
    //  gfx_line(ballx, bally, 300, 150);
  // }
}

void Golf::changearrow(char c){  
      //display();
      //rotateMill();
         arrowx = gfx_xpos();
         arrowy = gfx_ypos();
         cout << arrowx << arrowy << endl;
         if (arrowx > 500) {
           arrowx = 500;
          }
          if (arrowx < 100) {
            arrowx = 100;
          }
          if ((bally > 550)&& (bally <750)) {
             if (arrowy < 550)
                arrowy = 550;
             if (arrowy > 750)
                arrowy = 750;
          }
         if ((bally > 50) && (bally <250)) {
            if (arrowy <50) 
               arrowy = 50;
            if (arrowy >250)
               arrowy = 250;
         }
      gfx_line(ballx, bally, arrowx, arrowy);
      gfx_flush();
     // usleep(70000);
     // gfx_clear();
 }

bool Golf::releaseball() {
   bool endGame = false;
   float minusX=0, minusY=0, dx = 1, dy = 1;
   cout << "AT BEGIN " << endl;
   cout << "ABS values" << abs(dx) <<" " <<abs(dy) << endl;
   radline = pow(pow(arrowx-ballx, 2) + pow(arrowy-bally,2), 0.5);
   while (abs(minusX)<abs(dx) || abs(minusY)<abs(dy)) {    //can't be while dx>0 and dy >0; what if dx or dy is negative or 0
      float x = arrowx-ballx, y = arrowy-bally, ratio;
      cout << "THIS IS Y " << y << endl;
      cout << "initial dy dx" << dx << " " << dy << endl;
      if(x==0){
         dx = 0;
         if(dy<0)
            dy = -1*radline*.4;
         else
            dy = radline*.4;
      }
      else if(y==0){
         dy = 0;
         if(dx<0)
            dx = -1*radline*.4;
         else
            dx = radline*.4;
      }
      else{
         ratio = abs(y/x);
         if(dx<0 || x<0)
            dx = -1*(radline*.4);
         else
            dx = (radline*.4);
         if(dy<0 || y<0)
            dy = -1*ratio*dx;  
         else
            dy = ratio*dx;
      }
      cout << "ratio" << ratio <<" "<< dx << " " <<dy << endl;
      bool inMill = throughMill();
      bool win = inhole();
      if(inMill) {
         display();
         cout << "winner??" << endl;
         ballx = 300;
         bally = 250-ballrad-1;
         inMill = false;
      }
      if(win){
         display();
         cout << "WINNN" << endl;
         endGame = true;
         goto END;
      }
      cout << "yodel" << ballx << " " << bally << endl;
      display();
      rotateMill();
      cout << radline << "radline" <<endl;
      
      cout << "HERE IS MINUS " << minusX << " "<<minusY << endl;
      if(radline > 357){
        if(dx!=0){
           dx = dx-minusX; //do angle stuff with direction of ball
           if(dx>0)
              minusX+=1;
           else if(dx<0)
              minusX-=1;
         }
         if(dy!=0){
           dy = dy-minusY;
           if(dy>0)
              minusY+=1;
           else if(dy<0)
              minusY-=1;
         }
      }
      else if(radline <= 357 && radline > 267){
         if(dx!=0){
           dx = dx-minusX; //do angle stuff with direction of ball
           if(dx>0)
              minusX+=1.5;
           else if(dx<0)
              minusX-=1.5;
         }
         if(dy!=0){
           dy = dy-minusY;
           if(dy>0)
              minusY+=1.5;
           else if(dy<0)
              minusY-=1.5;
         }
      }
      else if(radline <= 267 && radline > 177){
         if(dx!=0){
           dx = dx-minusX; //do angle stuff with direction of ball
           if(dx>0)
              minusX+=2;
           else if(dx<0)
              minusX-=2;
         }
         if(dy!=0){
           dy = dy-minusY;
           if(dy>0)
              minusY+=2;
           else if(dy<0)
              minusY-=2;
         }
      }
      else if(radline <= 177 && radline > 97){
         if(dx!=0){
           dx = dx-minusX; //do angle stuff with direction of ball
           if(dx>0)
              minusX+=2.5;
           else if(dx<0)
              minusX-=2.5;
         }
         if(dy!=0){
           dy = dy-minusY;
           if(dy>0)
              minusY+=2.5;
           else if(dy<0)
              minusY-=2.5;
         }
      }
      else if(radline <= 97){
         if(dx!=0){
           dx = dx-minusX; //do angle stuff with direction of ball
           if(dx>0)
              minusX+=3;
           else if(dx<0)
              minusX-=3;
         }
         if(dy!=0){
           dy = dy-minusY;
           if(dy>0)
              minusY+=3;
           else if(dy<0)
              minusY-=3;
         }
         cout << "5" <<"  "<< minusX << " "<< minusY << endl;
      }
      
      cout << "ball points:" << endl;
      cout << ballx << " " << bally << " dy " << dy << endl;
      ballx = dx + ballx;
      bally = dy + bally;
      cout << ballx << " " << bally << endl;
     
   //if ((ballx <=0) || (bally <=0))
     // break;
   if (ballx >= 500-ballrad){
      dx = -dx;
      minusX = -minusX;
      ballx = 500-ballrad-3;
   }
   else if(ballx <= 100+ballrad){
      dx = -dx;
      minusX = -minusX;
      ballx = 100+ballrad+3;
   }
   if (bally >= 250-ballrad && bally < 400){
      dy = -dy;
      minusY = -minusY;
      bally = 250-ballrad-3;
   }
   else if(bally <= 550+ballrad && bally > 300){ 
      dy = -dy;
      minusY = -minusY;
      cout << "hey" << endl;
      bally = 550+ballrad+3;
   }
   else if(bally >= 750-ballrad){
      cout << "over the edge" << endl;
      dy = -dy;
      minusY = -minusY;
      bally = 750-ballrad-3;
      
   }
   else if(bally <= 50+ballrad){
      bally = 50+ballrad+3;
      dy = -dy;
   }
   cout << radline << "dx dy  " << dx << " " << dy << endl;
   gfx_flush();
   usleep(75000);
   gfx_clear();
  }
  END: {}
  if ((bally >=550) && (bally <= 750)) {
     arrowx = 300;
     arrowy = 675;
   }
   if ((bally <=250) && (bally >=50)) {
      arrowx = 300;
      arrowy= 150;
   }
  return endGame;
}

bool Golf::throughMill() {
  bool inMill = false;
  if(triY1!=550 && triY4!=550) {
    if ((ballx > 287.5) && (ballx < 312.5)) {
      if (bally-1.5*ballrad < 550 && bally+ballrad > 250) {
        inMill = true;
      }
    }
  }
  return inMill;
}

bool Golf::inhole() {
   bool win = false;
   if ((ballx >=135) && (ballx+ballrad<= 165) && (bally+ballrad <=115) && (bally >= 85)) {
         win = true;
      }
   if ((ballx-ballrad >=135) && (ballx<= 165) && (bally+ballrad <=115) && (bally >=85)) {
         win = true;
      }
   if ((ballx >=135) && (ballx+ballrad <= 165) && (bally <=115) && (bally-ballrad >=85)) {
         win = true;
      }
    if ((ballx-ballrad >=135) && (ballx <= 165) && (bally <=115) && (bally-ballrad >=85)) {
         win = true;
      }
   return win;
}
   
      



