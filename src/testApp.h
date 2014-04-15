#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxTween.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont  typo64;
		ofTrueTypeFont  typo32;

        float durationup;
        float alphamin, alphamax;

        vector <float> frequency;
        vector <float> currenttime;
        vector <float> durationdown;

        vector <string> stext;
        vector <ofPoint> postext;

        vector <float> alpha;

		ofxUICanvas *gui1;
		ofxUICanvas *gui2;
        void guiEvent(ofxUIEventArgs &e);
        bool bshowgrid;

};
