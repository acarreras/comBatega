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
	gui = new ofxUICanvas(0, 0, ofGetWidth()/4, ofGetHeight());
    gui->addFPSSlider("FPS SLIDER", 500);
    gui->addSpacer(ofGetWidth()/5, 2);
    gui->addTextInput("TITOLtext", stitol, dim)->setAutoClear(false);
    gui->addSlider("TITOLx", 0, ofGetWidth(), &ptitol.x);
	gui->addSlider("TITOLy", 0, ofGetHeight(), &ptitol.y);
	gui->addSpacer(ofGetWidth()/5, 2);
    gui->addTextInput("BATEGA0text", sbatega0, dim)->setAutoClear(false);
    gui->addSlider("BATEGA0x", 0, ofGetWidth(), &pbatega0.x);
	gui->addSlider("BATEGA0y", 0, ofGetHeight(), &pbatega0.y);
	gui->addSpacer(ofGetWidth()/5, 2);
    gui->addTextInput("BATEGA1text", sbatega1, dim)->setAutoClear(false);
    gui->addSlider("BATEGA1x", 0, ofGetWidth(), &pbatega1.x);
	gui->addSlider("BATEGA1y", 0, ofGetHeight(), &pbatega1.y);
	gui->addSpacer(ofGetWidth()/5, 2);
    gui->addTextInput("BATEGA2text", sbatega2, dim)->setAutoClear(false);
    gui->addSlider("BATEGA2x", 0, ofGetWidth(), &pbatega2.x);
	gui->addSlider("BATEGA2y", 0, ofGetHeight(), &pbatega2.y);
	gui->addSpacer(ofGetWidth()/5, 2);
    gui->addTextInput("BATEGA3text", sbatega3, dim)->setAutoClear(false);
    gui->addWidgetDown(new ofxUILabel("BATEGA 3", OFX_UI_FONT_LARGE));
	gui->addSlider("BATEGA3x", 0, ofGetWidth(), &pbatega3.x);
	gui->addSlider("BATEGA3y", 0, ofGetHeight(), &pbatega3.y);
	gui->addSpacer(ofGetWidth()/5, 2);
    gui->addTextInput("BATEGA4text", sbatega4, dim)->setAutoClear(false);
    gui->addSlider("BATEGA4x", 0, ofGetWidth(), &pbatega4.x);
	gui->addSlider("BATEGA4y", 0, ofGetHeight(), &pbatega4.y);
	gui->addSpacer(ofGetWidth()/5, 2);
    gui->addTextInput("BATEGA5text", sbatega5, dim)->setAutoClear(false);
    gui->addSlider("BATEGA5x", 0, ofGetWidth(), &pbatega5.x);
	gui->addSlider("BATEGA5y", 0, ofGetHeight(), &pbatega5.y);
	gui->addSpacer(ofGetWidth()/5, 2);
    gui->addTextInput("BATEGA6text", sbatega6, dim)->setAutoClear(false);
    gui->addSlider("BATEGA6x", 0, ofGetWidth(), &pbatega6.x);
	gui->addSlider("BATEGA6y", 0, ofGetHeight(), &pbatega6.y);

	gui->loadSettings("GUI/guiSettings.xml");
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);

    bshowgrid = false;

}

//--------------------------------------------------------------
void testApp::update(){

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
    typo64.drawString(stitol, ptitol.x, ptitol.y);
    typo32.drawString(sbatega0, pbatega0.x, pbatega0.y);
    typo32.drawString(sbatega1, pbatega1.x, pbatega1.y);
    typo32.drawString(sbatega2, pbatega2.x, pbatega2.y);
    typo32.drawString(sbatega3, pbatega3.x, pbatega3.y);
    typo32.drawString(sbatega4, pbatega4.x, pbatega4.y);
    typo32.drawString(sbatega5, pbatega5.x, pbatega5.y);
    typo32.drawString(sbatega6, pbatega6.x, pbatega6.y);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key){
        case 'h':
            gui->toggleVisible();
            break;
        case 'g':
            bshowgrid = !bshowgrid;
            break;
        default:
            break;ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);

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
    gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
}
