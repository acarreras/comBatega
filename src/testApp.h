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

		string stitol, sbatega0, sbatega1, sbatega2, sbatega3, sbatega4, sbatega5, sbatega6;
		ofPoint ptitol, pbatega0, pbatega1, pbatega2, pbatega3, pbatega4, pbatega5, pbatega6;

		ofxTween tweenexpo;
		ofxEasingExpo 	easingexpo;

		ofxUICanvas *gui;
        void guiEvent(ofxUIEventArgs &e);
        bool bshowgrid;

};
