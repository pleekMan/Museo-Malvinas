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
#include "ContentHolder.h"
#include "FunkyRect.h"
#include "Wave.h"


#endif /* defined(__animatableTest__Navigator__) */

class Navigator : public ofFbo{

    public:
        Navigator(){};
        ~Navigator(){};

        void setup(string p, ofPoint initPos);
        void appear();
        void disappear();
        void update(float time);
        void draw();

        void checkClick(int mx, int my);
        void optionPressed(int selection); // type: SECTION or THUMB,

    string path;
    float x, y;
    int width, height;

    ofxAnimatableObject<ofFbo> fbo;

    ofxAnimatableObject<ofImage> titulo;

    vector< ofxAnimatableObject<ofImage> > buttons;
    vector <ofPoint> buttonBackPos;
    vector <FunkyRect> buttonsBackG;
    

    int currentContent;
    int nextContent;

    vector< ContentHolder > contents;

    Wave wave;
    FunkyRect swizzer;
    vector <FunkyRect> beepers;



};
