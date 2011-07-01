#ifndef _STROKE_H
#define _STROKE_H

#include "ofMain.h"

#include "ofxVectorMath.h"


class stroke {
	
	public:
		
		void	addPoint(float x, float y);
		void	clear();
		void	draw();
		float	getLength();
		void	resample(int newNumPts);
		
		vector <ofxVec2f> pts;

};

#endif
	
