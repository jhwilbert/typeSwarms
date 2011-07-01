#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "stroke.h"




class testApp : public ofSimpleApp{
	
public:
	
	bool activateDraw;
	bool activateLoop;
	
	
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased (int key);
	
	void writeShape();
	
	
	void writeShape2();
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
	stroke	myStroke;
	
	// let's make a vector of them
	vector <particle> particles;
	string Wrd;
	
	bool	bRepel;
	float	radius;
	float	strength;
	
	
	ofTrueTypeFont testFont;
	
	bool bCircle;
	
	int ptsx;
	int ptsy;	
	
	int letter;
	
};

#endif

