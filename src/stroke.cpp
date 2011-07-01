#include "stroke.h"


void stroke::addPoint(float x, float y){
	pts.push_back(ofxVec2f(x,y));
}

void stroke::clear(){
	pts.clear();
}

void stroke::draw(){
	ofSetColor(0,0,0);
	if (pts.size() > 1){
		for (int i = 0; i < pts.size()-1; i++){
			ofLine (  pts[i].x, pts[i].y, pts[i+1].x, pts[i+1].y);
		}
	}
}

float stroke::getLength(){
	
	
	float length = 0;
	if (pts.size() > 1){
		for (int i = 0; i < pts.size()-1; i++){
			length += (pts[i] - pts[i+1]).length();
		}
	}
	return length;
}



void stroke::resample(int newNumPts){
	
	float interval = getLength() / (newNumPts - 1); // calc interval length
	
	float D = 0.0;									// total distance, as we walk across
	
	vector <ofxVec2f> newPts;						// new pts
 
	//--- store first point since we'll never resample it out of existence
	newPts.push_back(pts.front());
	for(int i = 1; i < (int)pts.size(); i++){
		
		ofxVec2f currentPoint  = pts[i];
		ofxVec2f previousPoint = pts[i-1];
		float d = (previousPoint - currentPoint).length();
		if ((D + d) >= interval){
			float qx = previousPoint.x + ((interval - D) / d) * (currentPoint.x - previousPoint.x);
			float qy = previousPoint.y + ((interval - D) / d) * (currentPoint.y - previousPoint.y);
			ofxVec2f point(qx, qy);
			newPts.push_back(point);
			pts.insert(pts.begin() + i, point);
			D = 0.0;
		}
		else D += d;
	}
 
	// somtimes we fall a rounding-error short of adding the last point, so add it if so
	if (newPts.size() == (newNumPts - 1)){
		newPts.push_back(pts.back());
	}
	
	pts = newPts;
	
	
//	printf("--------------------- \n");
	for (int i = 0; i < pts.size()-1; i++){
	//	printf(" %f   \n", (pts[i] - pts[i+1]).length());
	}
	
	
	//return newPoints;
 }
 