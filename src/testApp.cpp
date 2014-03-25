#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    // FONT
    ofTrueTypeFont::setGlobalDpi(72);
	typo64.loadFont("Existence-StencilLight.otf", 64, true, true);
    typo64.setLineHeight(64.0f);
	typo64.setLetterSpacing(1.037);

	typo32.loadFont("Existence-StencilLight.otf", 32, true, true);
    typo32.setLineHeight(64.0f);
	typo32.setLetterSpacing(1.037);

	// TEXTOS
	stitol = "COM BATEGA LA CULTURA...";
	sbatega0 = "EL COR D'UN NEN";
	sbatega1 = "EL COR D'UN ADULT";
	sbatega2 = "UN ACRÒBATA EN ESCENA";
	sbatega3 = "S'OMPLE UNA BUTACA DE CINE";
	sbatega4 = "S'OMPLE UNA BUTACA DE TEATRE";
	sbatega5 = "BUTACA DE DANSA";
	sbatega6 = "BUTACA DE CIRC";

	// GUI
	int dim = 20;
	gui1 = new ofxUICanvas(0, 0, ofGetWidth()/4, ofGetHeight());
    gui1->addFPSSlider("FPS SLIDER", 500);
    gui1->addSpacer(ofGetWidth()/5, 2);
    gui1->addTextInput("TITOLtext", stitol, dim)->setAutoClear(false);
    gui1->addSlider("TITOLx", 0, ofGetWidth(), &ptitol.x);
	gui1->addSlider("TITOLy", 0, ofGetHeight(), &ptitol.y);
	gui1->addSlider("TITOLduration", 0, MAX_DURATION_MS, &durtweentitol);
	gui1->addSlider("TITOLdelay", 0, MAX_DELAY_MS, &dtweentitol);
	gui1->addSpacer(ofGetWidth()/5, 2);
    gui1->addTextInput("BATEGA0text", sbatega0, dim)->setAutoClear(false);
    gui1->addSlider("BATEGA0x", 0, ofGetWidth(), &pbatega0.x);
	gui1->addSlider("BATEGA0y", 0, ofGetHeight(), &pbatega0.y);
	gui1->addSlider("BATEGA0duration", 0, MAX_DURATION_MS, &durtweenbatega0);
	gui1->addSlider("BATEGA0delay", 0, MAX_DELAY_MS, &dtweenbatega0);
	gui1->addSpacer(ofGetWidth()/5, 2);
    gui1->addTextInput("BATEGA1text", sbatega1, dim)->setAutoClear(false);
    gui1->addSlider("BATEGA1x", 0, ofGetWidth(), &pbatega1.x);
	gui1->addSlider("BATEGA1y", 0, ofGetHeight(), &pbatega1.y);
	gui1->addSlider("BATEGA1duration", 0, MAX_DURATION_MS, &durtweenbatega1);
	gui1->addSlider("BATEGA1delay", 0, MAX_DELAY_MS, &dtweenbatega1);
	gui1->addSpacer(ofGetWidth()/5, 2);
    gui1->addTextInput("BATEGA2text", sbatega2, dim)->setAutoClear(false);
    gui1->addSlider("BATEGA2x", 0, ofGetWidth(), &pbatega2.x);
	gui1->addSlider("BATEGA2y", 0, ofGetHeight(), &pbatega2.y);
    gui1->addSlider("BATEGA2duration", 0, MAX_DURATION_MS, &durtweenbatega2);
	gui1->addSlider("BATEGA2delay", 0, MAX_DELAY_MS, &dtweenbatega2);

	gui2 = new ofxUICanvas(ofGetWidth()/4, 0, ofGetWidth()/4, ofGetHeight());
	gui2->addTextInput("BATEGA3text", sbatega3, dim)->setAutoClear(false);
    gui2->addWidgetDown(new ofxUILabel("BATEGA 3", OFX_UI_FONT_LARGE));
	gui2->addSlider("BATEGA3x", 0, ofGetWidth(), &pbatega3.x);
	gui2->addSlider("BATEGA3y", 0, ofGetHeight(), &pbatega3.y);
	gui2->addSlider("BATEGA3duration", 0, MAX_DURATION_MS, &durtweenbatega3);
	gui2->addSlider("BATEGA3delay", 0, MAX_DELAY_MS, &dtweenbatega3);
	gui2->addSpacer(ofGetWidth()/5, 2);
    gui2->addTextInput("BATEGA4text", sbatega4, dim)->setAutoClear(false);
    gui2->addSlider("BATEGA4x", 0, ofGetWidth(), &pbatega4.x);
	gui2->addSlider("BATEGA4y", 0, ofGetHeight(), &pbatega4.y);
	gui2->addSlider("BATEGA4duration", 0, MAX_DURATION_MS, &durtweenbatega4);
	gui2->addSlider("BATEGA4delay", 0, MAX_DELAY_MS, &dtweenbatega4);
	gui2->addSpacer(ofGetWidth()/5, 2);
    gui2->addTextInput("BATEGA5text", sbatega5, dim)->setAutoClear(false);
    gui2->addSlider("BATEGA5x", 0, ofGetWidth(), &pbatega5.x);
	gui2->addSlider("BATEGA5y", 0, ofGetHeight(), &pbatega5.y);
    gui2->addSlider("BATEGA5duration", 0, MAX_DURATION_MS, &durtweenbatega5);
	gui2->addSlider("BATEGA5delay", 0, MAX_DELAY_MS, &dtweenbatega5);

	gui3 = new ofxUICanvas(ofGetWidth()/2, 0, ofGetWidth()/4, ofGetHeight());
	gui3->addTextInput("BATEGA6text", sbatega6, dim)->setAutoClear(false);
    gui3->addSlider("BATEGA6x", 0, ofGetWidth(), &pbatega6.x);
	gui3->addSlider("BATEGA6y", 0, ofGetHeight(), &pbatega6.y);
    gui3->addSlider("BATEGA6duration", 0, MAX_DURATION_MS, &durtweenbatega6);
	gui3->addSlider("BATEGA6delay", 0, MAX_DELAY_MS, &dtweenbatega6);

	gui1->loadSettings("GUI/guiSettings1.xml");
    gui2->loadSettings("GUI/guiSettings2.xml");
    gui3->loadSettings("GUI/guiSettings3.xml");
    ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);
    ofAddListener(gui2->newGUIEvent,this,&testApp::guiEvent);
    ofAddListener(gui3->newGUIEvent,this,&testApp::guiEvent);

	tweentitol.setParameters(0,easingtitol,ofxTween::easeOut,0,255,durtweentitol,dtweentitol);
	tweenbatega0.setParameters(1,easingbatega0,ofxTween::easeOut,0,255,durtweenbatega0,dtweenbatega0);
	tweenbatega1.setParameters(1,easingbatega0,ofxTween::easeOut,0,255,durtweenbatega1,dtweenbatega1);
	tweenbatega2.setParameters(1,easingbatega0,ofxTween::easeOut,0,255,durtweenbatega2,dtweenbatega2);
	tweenbatega3.setParameters(1,easingbatega0,ofxTween::easeOut,0,255,durtweenbatega3,dtweenbatega3);
	tweenbatega4.setParameters(1,easingbatega0,ofxTween::easeOut,0,255,durtweenbatega4,dtweenbatega4);
	tweenbatega5.setParameters(1,easingbatega0,ofxTween::easeOut,0,255,durtweenbatega5,dtweenbatega5);
	tweenbatega6.setParameters(1,easingbatega0,ofxTween::easeOut,0,255,durtweenbatega6,dtweenbatega6);
	tweentitol.start();
	tweenbatega0.start();
	tweenbatega1.start();
	tweenbatega2.start();
	tweenbatega3.start();
	tweenbatega4.start();
	tweenbatega5.start();
	tweenbatega6.start();
	backtweentitol.setParameters(0,easingtitol,ofxTween::easeOut,0,255,durtweentitol,dtweentitol);
	backtweenbatega0.setParameters(1,easingbatega0,ofxTween::easeOut,255,0,durtweenbatega0,dtweenbatega0);
	backtweenbatega1.setParameters(1,easingbatega0,ofxTween::easeOut,255,0,durtweenbatega1,dtweenbatega1);
	backtweenbatega2.setParameters(1,easingbatega0,ofxTween::easeOut,255,0,durtweenbatega2,dtweenbatega2);
	backtweenbatega3.setParameters(1,easingbatega0,ofxTween::easeOut,255,0,durtweenbatega3,dtweenbatega3);
	backtweenbatega4.setParameters(1,easingbatega0,ofxTween::easeOut,255,0,durtweenbatega4,dtweenbatega4);
	backtweenbatega5.setParameters(1,easingbatega0,ofxTween::easeOut,255,0,durtweenbatega5,dtweenbatega5);
	backtweenbatega6.setParameters(1,easingbatega0,ofxTween::easeOut,255,0,durtweenbatega6,dtweenbatega6);
    bshowgrid = false;

}

//--------------------------------------------------------------
void testApp::update(){
    // ping
    if(tweentitol.isCompleted()){
        tweentitol.reset();
        backtweentitol.start();
    }
    if(tweenbatega0.isCompleted()){
        tweenbatega0.reset();
        backtweenbatega0.start();
    }
    if(tweenbatega1.isCompleted()){
        tweenbatega1.reset();
        backtweenbatega1.start();
    }
    if(tweenbatega2.isCompleted()){
        tweenbatega2.reset();
        backtweenbatega2.start();
    }
    if(tweenbatega3.isCompleted()){
        tweenbatega3.reset();
        backtweenbatega3.start();
    }
    if(tweenbatega4.isCompleted()){
        tweenbatega4.reset();
        backtweenbatega4.start();
    }
    if(tweenbatega5.isCompleted()){
        tweenbatega5.reset();
        backtweenbatega5.start();
    }
    if(tweenbatega6.isCompleted()){
        tweenbatega6.reset();
        backtweenbatega6.start();
    }

    // pong
    if(backtweentitol.isCompleted()){
        backtweentitol.reset();
        tweentitol.start();
    }
    if(backtweenbatega0.isCompleted()){
        backtweenbatega0.reset();
        tweenbatega0.start();
    }
    if(backtweenbatega1.isCompleted()){
        backtweenbatega1.reset();
        tweenbatega1.start();
    }
    if(backtweenbatega2.isCompleted()){
        backtweenbatega2.reset();
        tweenbatega2.start();
    }
    if(backtweenbatega3.isCompleted()){
        backtweenbatega3.reset();
        tweenbatega3.start();
    }
    if(backtweenbatega4.isCompleted()){
        backtweenbatega4.reset();
        tweenbatega4.start();
    }
    if(backtweenbatega5.isCompleted()){
        backtweenbatega5.reset();
        tweenbatega5.start();
    }
    if(backtweenbatega6.isCompleted()){
        backtweenbatega6.reset();
        tweenbatega6.start();
    }

    // update alpha
    if(tweentitol.isRunning()){
        alphatitol = tweentitol.update();
    }
    if(backtweentitol.isRunning()){
        alphatitol = backtweentitol.update();
    }
    if(tweenbatega0.isRunning()){
        alphabatega0 = tweenbatega0.update();
    }
    if(backtweenbatega0.isRunning()){
        alphabatega0 = backtweenbatega0.update();
    }
    if(tweenbatega1.isRunning()){
        alphabatega1 = tweenbatega1.update();
    }
    if(backtweenbatega1.isRunning()){
        alphabatega1 = backtweenbatega1.update();
    }
    if(tweenbatega2.isRunning()){
        alphabatega2 = tweenbatega2.update();
    }
    if(backtweenbatega2.isRunning()){
        alphabatega2 = backtweenbatega2.update();
    }
    if(tweenbatega3.isRunning()){
        alphabatega3 = tweenbatega3.update();
    }
    if(backtweenbatega3.isRunning()){
        alphabatega3 = backtweenbatega3.update();
    }
    if(tweenbatega4.isRunning()){
        alphabatega4 = tweenbatega4.update();
    }
    if(backtweenbatega4.isRunning()){
        alphabatega4 = backtweenbatega4.update();
    }
    if(tweenbatega5.isRunning()){
        alphabatega5 = tweenbatega5.update();
    }
    if(backtweenbatega5.isRunning()){
        alphabatega5 = backtweenbatega5.update();
    }
    if(tweenbatega6.isRunning()){
        alphabatega6 = tweenbatega6.update();
    }
    if(backtweenbatega6.isRunning()){
        alphabatega6 = backtweenbatega6.update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(100, 20, OF_GRADIENT_CIRCULAR);
    ofSetColor(255);

    // GRID
    if(bshowgrid){
        ofNoFill();
        float uncinque = 1.0/5.0;
        for(int i=0; i<5; i++){
            ofLine(0,ofGetHeight()*uncinque*i, ofGetWidth(),ofGetHeight()*uncinque*i);
        }
        for(int i=0; i<5; i++){
            ofLine(ofGetWidth()*uncinque*i, 0, ofGetWidth()*uncinque*i,ofGetHeight());
        }
    }

    // TEXT
    ofSetColor(255,255,255,alphatitol);
    typo64.drawString(stitol, ptitol.x, ptitol.y);
    ofSetColor(255,255,255,alphabatega0);
    typo32.drawString(sbatega0, pbatega0.x, pbatega0.y);
    ofSetColor(255,255,255,alphabatega1);
    typo32.drawString(sbatega1, pbatega1.x, pbatega1.y);
    ofSetColor(255,255,255,alphabatega2);
    typo32.drawString(sbatega2, pbatega2.x, pbatega2.y);
    ofSetColor(255,255,255,alphabatega3);
    typo32.drawString(sbatega3, pbatega3.x, pbatega3.y);
    ofSetColor(255,255,255,alphabatega4);
    typo32.drawString(sbatega4, pbatega4.x, pbatega4.y);
    ofSetColor(255,255,255,alphabatega5);
    typo32.drawString(sbatega5, pbatega5.x, pbatega5.y);
    ofSetColor(255,255,255,alphabatega6);
    typo32.drawString(sbatega6, pbatega6.x, pbatega6.y);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key){
        case 'h':
            gui1->toggleVisible();
            gui2->toggleVisible();
            gui3->toggleVisible();
            break;
        case 'g':
            bshowgrid = !bshowgrid;
            break;
        default:
            break;

    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	int kind = e.widget->getKind();


	if(name == "TITOLtext"){
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS){
            stitol = textinput->getTextString();
        }
    }
    else if(name == "BATEGA0text"){
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS){
            sbatega0 = textinput->getTextString();
        }
    }
    else if(name == "BATEGA1text"){
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS){
            sbatega1 = textinput->getTextString();
        }
    }
    else if(name == "BATEGA2text"){
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS){
            sbatega2 = textinput->getTextString();
        }
    }
    else if(name == "BATEGA3text"){
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS){
            sbatega3 = textinput->getTextString();
        }
    }
    else if(name == "BATEGA4text"){
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS){
            sbatega4 = textinput->getTextString();
        }
    }
    else if(name == "BATEGA5text"){
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS){
            sbatega5 = textinput->getTextString();
        }
    }
    else if(name == "BATEGA6text"){
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS){
            sbatega6 = textinput->getTextString();
        }
    }

}

//--------------------------------------------------------------
void testApp::exit(){
    gui1->saveSettings("GUI/guiSettings1.xml");
    gui2->saveSettings("GUI/guiSettings2.xml");
    gui3->saveSettings("GUI/guiSettings3.xml");
    delete gui1;
    delete gui2;
    delete gui3;
}
