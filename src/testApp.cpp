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
	// guardar el fitxer en UTF-8 per a que entengui els accents!
	if(XMLtext.loadFile("textsBatega.xml")){
		cout << "XML:: textsBatega.xml loaded!" << endl;
		int ntexts = XMLtext.getNumTags("TEXT");
		if(ntexts > 0){
            string txt = "";
            for(int i=0; i<ntexts; i++){
                //the last argument of getValue can be used to specify
                //which tag out of multiple tags you are refering to.
                txt = XMLtext.getValue("TEXT", "no text", i);
                stext.push_back(txt);
            }
        }
	}
	else{
		cout << "XML:: unable to load textsBatega.xml check data/ folder" << endl;
	}


	// GUI
	int dim = 20;
	gui1 = new ofxUICanvas(0, 0, ofGetWidth()/4, ofGetHeight());
    gui1->addFPSSlider("FPS SLIDER", 500);
    gui1->addSpacer(ofGetWidth()/5, 2);
    gui1->addSlider("DURATIONup", 0, 1000, &durationup);
    gui1->addSlider("ALPHAmin", 0, 255, &alphamin);
    gui1->addSlider("ALPHAmax", 0, 255, &alphamax);

    gui2 = new ofxUICanvas(ofGetWidth()/4, 0, ofGetWidth()/4, ofGetHeight());
	for(int i=0; i<stext.size(); i++){
        frequency.push_back(0.0f);
        postext.push_back(ofPoint(0.0f,0.0f));
	}
	for(int i=0; i<stext.size(); i++){
        gui2->addLabel(stext.at(i), OFX_UI_FONT_SMALL);
        gui2->addSlider("FREQ_"+ofToString(i), 1, 150, &frequency.at(i));
        gui2->addSlider("POSx_"+ofToString(i), 0, ofGetWidth(), &postext.at(i).x);
        gui2->addSlider("POSy_"+ofToString(i), 0, ofGetHeight(), &postext.at(i).y);
        gui2->addSpacer(ofGetWidth()/5, 2);
	}

	gui1->loadSettings("GUI/guiSettings1.xml");
    gui2->loadSettings("GUI/guiSettings2.xml");
    ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);
    ofAddListener(gui2->newGUIEvent,this,&testApp::guiEvent);

    for(int i=0; i<stext.size(); i++){
        alpha.push_back(alphamin);
	}

	for(int j=0; j<stext.size(); j++){
        currenttime.push_back(ofGetElapsedTimeMillis());
	}

	for(int k=0; k<stext.size(); k++){
        durationdown.push_back( (60000 - (frequency.at(k)*durationup)) * (1/frequency.at(k)) );
	}

    bshowgrid = false;

}

//--------------------------------------------------------------
void testApp::update(){

    for(int i=0; i<stext.size(); i++){
        if(alpha.at(i) == alphamin){
            // estem a down
            if(ofGetElapsedTimeMillis() - currenttime.at(i) > durationdown.at(i)){
                alpha.at(i) = alphamax;
                currenttime.at(i) = ofGetElapsedTimeMillis();
            }
        }
        else{
            // estem a up
            if(ofGetElapsedTimeMillis() - currenttime.at(i) > durationup){
                alpha.at(i) = alphamin;
                currenttime.at(i) = ofGetElapsedTimeMillis();
            }
        }
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
    if(stext.size()>0){
        // titol
        ofSetColor(255,255,255,alpha.at(0));
        typo64.drawString(stext.at(0), postext.at(0).x, postext.at(0).y);
	}
    for(int k=1; k<stext.size(); k++){
        // textos
        ofSetColor(255,255,255,alpha.at(k));
        typo32.drawString(stext.at(k), postext.at(k).x, postext.at(k).y);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key){
        case 'h':
            gui1->toggleVisible();
            gui2->toggleVisible();
            break;
        case 'g':
            bshowgrid = !bshowgrid;
            break;
        case 'f':
            ofToggleFullscreen();
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

	if(name.find("FREQ") != std::string::npos){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		string ch = name.substr(name.length()-1);
		int i = ofToInt(ch);
		frequency.at(i) = slider->getScaledValue();
        durationdown.at(i) = (60000 - (frequency.at(i)*durationup)) * (1/frequency.at(i));
	}
}

//--------------------------------------------------------------
void testApp::exit(){
    gui1->saveSettings("GUI/guiSettings1.xml");
    gui2->saveSettings("GUI/guiSettings2.xml");
    delete gui1;
    delete gui2;

    XMLtext.clear();
    for(int k=0; k<stext.size(); k++){
        int tagNum = XMLtext.addTag("TEXT");
		XMLtext.setValue("TEXT", stext.at(k), tagNum);
	}
	XMLtext.saveFile("textsBatega.xml");
}
