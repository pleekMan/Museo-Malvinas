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
#include "TriangleBlast.h"
#include "Stripper.h"


#endif /* defined(__animatableTest__Navigator__) */

class Navigator{

    public:
        Navigator(){};
        ~Navigator(){};

        void setup(string p, ofPoint initPos);
        void appear(float delay);
        void disappear();
        void update(float time);
        void draw();
        void drawMisc();

        void checkClick(int mx, int my);
        void optionPressed(int selection); // type: SECTION or THUMB,
    bool closePressed(int mx, int my);
    bool isVisible();

    string path;
    int width, height;
    bool visible;

    ofxAnimatableObject<ofFbo> fbo;

    ofxAnimatableObject<ofImage> titulo;
    ofxAnimatableObject<ofImage> close;

    vector< ofxAnimatableObject<ofImage> > buttons;
    vector <ofPoint> buttonBackPos;
    vector <FunkyRect> buttonsBackG;
    

    int currentContent;
    int nextContent;
    
    vector< ContentHolder > contents;

    Wave wave;
    FunkyRect swizzer;
    vector <FunkyRect> beepers;
    ofxAnimatableObject<ofImage> triangle;
    //TriangleBlast triangle;
    Stripper stripper;    

};
