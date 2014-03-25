#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxTween.h"

#define MAX_DURATION_MS     5000
#define MAX_DELAY_MS        3000

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

		float alphatitol, alphabatega0, alphabatega1, alphabatega2, alphabatega3, alphabatega4, alphabatega5, alphabatega6;

		string stitol, sbatega0, sbatega1, sbatega2, sbatega3, sbatega4, sbatega5, sbatega6;
		ofPoint ptitol, pbatega0, pbatega1, pbatega2, pbatega3, pbatega4, pbatega5, pbatega6;

		ofxTween tweentitol, tweenbatega0, tweenbatega1, tweenbatega2, tweenbatega3, tweenbatega4, tweenbatega5, tweenbatega6;
        ofxEasingExpo 	easingtitol, easingbatega0, easingbatega1, easingbatega2, easingbatega3, easingbatega4, easingbatega5, easingbatega6;
        float durtweentitol, durtweenbatega0, durtweenbatega1, durtweenbatega2, durtweenbatega3, durtweenbatega4, durtweenbatega5, durtweenbatega6;
        float dtweentitol, dtweenbatega0, dtweenbatega1, dtweenbatega2, dtweenbatega3, dtweenbatega4, dtweenbatega5, dtweenbatega6;

        ofxTween backtweentitol, backtweenbatega0, backtweenbatega1, backtweenbatega2, backtweenbatega3, backtweenbatega4, backtweenbatega5, backtweenbatega6;

		ofxUICanvas *gui1;
		ofxUICanvas *gui2;
		ofxUICanvas *gui3;
        void guiEvent(ofxUIEventArgs &e);
        bool bshowgrid;

};
