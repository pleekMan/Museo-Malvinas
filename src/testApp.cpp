#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    background.loadImage("tempBack.png");
    
    navigator01.setup(ofPoint(20.0,20.0));
    navigator01.allocate(navigator01.width , navigator01.height);
    navigator01.initialize();
    
    
    /*
    img.loadImage("conejo1.jpg");
       
    img.position.setRepeatType(LOOP_BACK_AND_FORTH);
    img.position.setDuration(5.);
    img.position.animateToAfterDelay(ofPoint(0.5*ofGetWidth(),0.5*ofGetHeight()),.5);
    bool tr = img.position.isAnimating();
    
    img.setSize(0.5);
    img.size.setCurve(EASE_OUT);
    img.size.setDuration(2.);
    img.size.setRepeatType(LOOP_BACK_AND_FORTH);
    img.size.animateTo(0.8);
     */
}

//--------------------------------------------------------------
void testApp::update(){
    float dt=1./ofGetFrameRate();
    navigator01.update(dt);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    background.draw(0, 0);
    
    navigator01.draw();
    
    ofDrawBitmapString("X: " + ofToString(mouseX) + " - Y: " + ofToString(mouseY), ofPoint(mouseX,mouseY));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
    
    //navigator01.setup(ofPoint(mouseX, mouseY));
    //navigator01.initialize();
    
    navigator01.checkClick(mouseX, mouseY);
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