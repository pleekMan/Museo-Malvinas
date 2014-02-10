//
//  Navigator.h
//  animatableTest
//
//  Created by Wanda on 07/02/14.
//
//

#ifndef __animatableTest__Navigator__
#define __animatableTest__Navigator__

#include <iostream>

#include "ofMain.h"
#include "ofxAnimatableObject.h"
#include "ofxAnimatableImageMasked.h"


#endif /* defined(__animatableTest__Navigator__) */

class Navigator : public ofFbo{

    public:
        Navigator(){};
    
        void setup(ofPoint initPos);
        void initialize();
        void update(float time);
        void draw();
    
        void checkClick(int mx, int my);
        void optionPressed(string type, int selection); // type: SECTION or THUMB,

    float x, y;
    int width, height;
    
    ofxAnimatableObject<ofFbo> fbo;

    ofxAnimatableObject<ofImage> titulo;
    ofxAnimatableObject<ofImage> boton01;
    ofxAnimatableObject<ofImage> boton02;
    ofxAnimatableObject<ofImage> boton03;
    
    ofxAnimatableImageMasked imagen01;
    ofxAnimatableImageMasked imagen02;
    
    ofxAnimatableImageMasked texto01;
    ofxAnimatableImageMasked texto02;
    
    ofxAnimatableObject<ofImage> thumb01;
    ofxAnimatableObject<ofImage> thumb02;
    ofxAnimatableObject<ofImage> thumb03;


};