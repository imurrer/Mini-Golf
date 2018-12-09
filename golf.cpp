//golf.cpp
//Lab 12 Implementation
//Bella Murrer and Hannah Sarkey

#include "golf.h"

Golf::Golf() { // initialize private objects
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

Golf::~Golf() { } // destructor

void Golf::resetplacements() { // reset placement of ball if user decides to play again
	ballx = 300;
	bally= 740;
	arrowx= 300;
	arrowy = 675;
}

void Golf::displayinhole() { // displays ball in hole when users gets it in
	ballx = 150;
	bally = 100;
	display();
}

void Golf::display() { // displays entire course
	gfx_color(29, 147, 41); // green course
	gfx_fill_rectangle(tx, ty, l, w);
	gfx_fill_rectangle(mx, my, mw, ml);
	gfx_fill_rectangle(bx, by, l, w);

	gfx_color(255, 255, 255); // draw ball
	gfx_fill_circle(ballx, bally, ballrad);

	gfx_color(170, 184, 255);  // the windmill herself
	gfx_fill_rectangle(250, 400, 100, 150);
	XPoint pt = {200, 550};
	XPoint mypoints1[] = { {200, 550}, {250, 400}, {250, 550} }; // struct to make windmill triangles
	XPoint mypoints2[] = { {350, 550}, {350, 400}, {400, 550} };
	int size1 = sizeof(mypoints1)/sizeof(pt);
	gfx_fill_polygon(mypoints1, size1);
	gfx_fill_polygon(mypoints2, size1);

	gfx_color(0, 0, 0); // hole arc & hole
	gfx_fill_arc(hx, hy, hw, hl, a1, a2);
	gfx_fill_circle(150, 100, 10);

	gfx_color(0,43,4); // dropoff line behind the windmill
	gfx_line(200, 250, 400 , 250);
}


void Golf::rotateMill() { // rotates mill
	XPoint pt = {(short)millcentX, (short)millcentY};   
	XPoint mypoints1[] = { {(short)millcentX, (short)millcentY}, {(short)triX1, (short)triY1}, {(short)triX2, (short)triY2} };
	XPoint mypoints2[] = { {(short)millcentX, (short)millcentY}, {(short)triX3, (short)triY3}, {(short)triX4, (short)triY4} };
	int size1 = sizeof(mypoints1)/sizeof(pt);
	gfx_color(192, 242, 247);
	gfx_fill_polygon(mypoints1, size1);
	gfx_fill_polygon(mypoints2, size1);
	//first top triangle
	angmill1+=M_PI/6;
	angmill2+=M_PI/6;
	triX1 = triX1+(radmill*(cos(angmill1-M_PI/6)-cos(angmill1)));      //rotate triangles around center point by pi/6
	triY1 = triY1+(radmill*(sin(angmill1-M_PI/6)-sin(angmill1)));
	triX2 = triX2+(radmill*(cos(angmill2-M_PI/6)-cos(angmill2)));
	triY2 = triY2+(radmill*(sin(angmill2-M_PI/6)-sin(angmill2)));
	//bottom triangle
	angmill3+=M_PI/6;
	angmill4+=M_PI/6;
	triX3 = triX3+(radmill*(cos(angmill3-M_PI/6)-cos(angmill3)));
	triY3 = triY3+(radmill*(sin(angmill3-M_PI/6)-sin(angmill3)));
	triX4 = triX4+(radmill*(cos(angmill4-M_PI/6)-cos(angmill4)));
	triY4 = triY4+(radmill*(sin(angmill4-M_PI/6)-sin(angmill4)));
}

void Golf::displayarrow() { // displays guide line
	gfx_color(24, 60, 242);
	gfx_line(ballx, bally, arrowx, arrowy);
}

void Golf::changearrow(char c){   // changes guide line based on user click 
	arrowx = gfx_xpos();
	arrowy = gfx_ypos();
	if (arrowx > 500) { // if user clicks too far right
		arrowx = 500;
	}
	if (arrowx < 100) { // if user clicks off course to the left
		arrowx = 100;
	}
	if ((bally > 550)&& (bally <750)) { // if user click outside of bottom green
		if (arrowy < 550)
			arrowy = 550;
		if (arrowy > 750)
			arrowy = 750;
	}
	if ((bally > 50) && (bally <250)) { // if user clicks outside of top green
		if (arrowy <50) 
			arrowy = 50;
		if (arrowy >250)
			arrowy = 250;
	}
	gfx_line(ballx, bally, arrowx, arrowy); // draw new guideline
	gfx_flush();
}

bool Golf::releaseball() { //moves the ball
	bool run = true;
	bool endGame = false;
	float minusX=0, minusY=0, dx = 1, dy = 1, smallx, smally, awayx = 0, awayy = 0;
	radline = pow(pow(arrowx-ballx, 2) + pow(arrowy-bally,2), 0.5);   //the length of the arrow

	//sets the change in x and y directions proportional to the ratio between x and y
	//smallx and smally are values proportional to the dx and dy values that will be subtracted from dx and dy
	//this will slow the balls down in the direction that the arrow was pointing
	float x = arrowx-ballx, y = arrowy-bally, ratio;
	if(x==0){
		dx = 0;
		if(y<0)
			dy = -1*radline*.35;
		else
			dy = radline*.35;
		smally = abs(.05*dy);
	}
	else if(y==0){
		dy = 0;
		if(x<0)
			dx = -1*radline*.35;
		else
			dx = radline*.35;
		smallx = abs(.05*dx);
	}
	else{
		if(abs(x)>abs(y)){
			ratio = y/x;
			if(x<0)
				dx = -1*(radline*.35);
			else
				dx = (radline*.35);
			if(y<0)
				dy = -1*abs(ratio*dx);  
			else
				dy = abs(ratio*dx);
			smallx = abs(.05*dx);
			smally = abs(smallx*ratio);
		}
		else if(abs(y)>abs(x)){
			ratio = x/y;
			if(y<0)
				dy = -1*(radline*.35); 
			else
				dy = (radline*.35);
			if(x<0)
				dx = -1*abs(ratio*dy); 
			else
				dx = abs(ratio*dy);
			smally = abs(.05*dy);
			smallx = abs(smally*ratio);
		}
	}

	while (run) {     //continues to run until dx or dy values are decreasing by an amount larger than themselves
		bool inMill = throughMill();
		bool win = inhole();
		//places ball on other side of windmill if it gets through mill
		if(inMill) {
			display();
			ballx = 300;
			bally = 250-ballrad-1;
			inMill = false;
		}
		//leaves the loop if the ball gets in the end hoole
		if(win){
			display();
			endGame = true;
			goto END;      //get to end of the method if user has won
		}
		display();
		rotateMill();

		//change the center location of the ball
		ballx = dx + ballx;
		bally = dy + bally;

		//reverses direction of the ball and resets it to edge if it hits a boundary
		if (ballx >= 500-ballrad){       
			dx = -dx;
			ballx = 500-ballrad-3;
		}
		else if(ballx <= 100+ballrad){
			dx = -dx;
			ballx = 100+ballrad+3;
		}
		if (bally >= 250-ballrad && bally < 400){
			dy = -dy;
			bally = 250-ballrad-3;
		}
		else if(bally <= 550+ballrad && bally > 300){ 
			dy = -dy;
			bally = 550+ballrad+3;
		}
		else if(bally >= 750-ballrad){
			dy = -dy;
			bally = 750-ballrad-3;  
		}
		else if(bally <= 50+ballrad){
			dy = -dy;
			bally = 50+ballrad+3;
		}

		//makes the absolute value of the change in x and y decrease each time the ball moves by smallx or smally
		//slow ball down
		if(dx<0){         
			awayx += smallx;
			dx = dx + awayx;
		}
		else if(dx>0){
			awayx += smallx;
			dx = dx-awayx;
		}
		else if(x!=0) {break;}

		if(dy<0){
			awayy += smally;
			dy = dy + awayy;
		}
		else if(dy>0){
			awayy += smally;
			dy = dy-awayy;
		}
		else if(y!=0) {break;}

		//check if the change in x or y direction is smaller than the amount by which they are getting smaller
		if(awayx>abs(dx) && x!=0)
			run = false;
		if(awayy>abs(dy))
			run = false;

		//clear screen in between each movement of the ball  
		gfx_flush();
		usleep(70000);
		gfx_clear();  
	}

	END: {}     // comes here if user won

	if ((bally >=550) && (bally <= 750)) { // resets guide line in bottom green
		arrowx = 300;
		arrowy = 675;
	}
	if ((bally <=250) && (bally >=50)) { // resets guide line in top green
		arrowx = 300;
		arrowy= 150;
	}

	return endGame;
}

// checks to see if ball went through mill
bool Golf::throughMill() { 
	bool inMill = false;
	if(triY1!=550 && triY4!=550) {    //will only go through mill if the mill's triangles aren't blocking hole
		if ((ballx > 287.5) && (ballx < 312.5)) {   //must be within range of the mill's hole
			if (bally-1.5*ballrad < 550 && bally+ballrad > 250) {
				inMill = true;
			}
		}
	}
	return inMill;
}

// checks to see if any of the four quadrants of the ball went into the hole and returns true if so
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
