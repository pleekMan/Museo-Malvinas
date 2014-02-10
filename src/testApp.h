#pragma once

#include "ofMain.h"

#include "ofxAnimatableObject.h"
#include "Navigator.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage background;
    Navigator navigator01;
    
    /*
    void pressedOption1(){
        option1.color.setColor(ofColor(255)));
        option1.color.animateTo(193029).
        
        imagenPrincipal.setPtr(thumnail1);
        imagenPrincial.mask.animtatto)10.
        
    }
    
    draw(){
        title.draw();
        
        option1.draw(0,title.height);
        option2.draw
    }
    
    ofxAnimatableObject<ofImage> title;
    
     ofxAnimatableObject<ofImageMasked> option1;
    
     ofxAnimatableObject<ofImage> img;
    
    
     ofxAnimatableObject<ofImage *> imgPrincipal;
    
    
     ofxAnimatableObject<ofImage> img;
    
    ofxAniObject<ofNavegador> navegador;
	*/
};

/*
class ofNavegador : ofFbo{
    
    
}
*/