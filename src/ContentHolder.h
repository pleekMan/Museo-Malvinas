//
//  ContentHolder.h
//  animatableTest
//
//  Created by Wanda on 10/02/14.
//
//

#ifndef __animatableTest__Navigator__
#define __animatableTest__Navigator__

#include <iostream>

#include "ofMain.h"
#include "ofxAnimatableObject.h"
#include "ofxAnimatableImageMasked.h"

#endif /* defined(__animatableTest__ContentHolder__) */

class ContentHolder{

public:

    ContentHolder(){};
    ~ContentHolder(){};

    void setup(string path);
    void appear(float delay);
    void disappear();
    void update(float time);
    void draw();

    void thumbPressed(int selection);
    bool isOrWillBeAnimating();



    vector < ofxAnimatableObject<ofImage> > thumbs;
    vector < ofxAnimatableImageMasked > images;
    vector < vector<ofxAnimatableImageMasked> > texts;

    int currentThumb;
    int nextThumb;

    int currentText;
    int nextText;

    string path;
    
private:
    void reset();

};
