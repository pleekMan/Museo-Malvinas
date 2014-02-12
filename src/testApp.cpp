#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    background.loadImage("tempBack.png");

    navigator01.setup("Navigator_0",ofPoint(20.0,20.0));
    navigator01.allocate(navigator01.width , navigator01.height);
    navigator01.appear();
    
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
    
    if (key == '1') {
        navigator01.appear();
    }
    if (key == '2') {
        navigator01.disappear();
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
