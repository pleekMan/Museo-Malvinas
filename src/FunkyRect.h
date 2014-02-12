//
//  FunkyRect.h
//  animatableTest
//
//  Created by Wanda on 11/02/14.
//
//

#ifndef __animatableTest__FunkyRect__
#define __animatableTest__FunkyRect__

#include <iostream>
#include "ofxAnimatableObject.h"

#endif /* defined(__animatableTest__FunkyRect__) */

class FunkyRect{
    
    
public:
    
    FunkyRect(){};
    
    void setup(bool state, ofPoint _pos, float _width, float _height);
    void setState(bool onState);
    void moveTo(ofPoint target);
    void colorTo(ofColor targetColor);
    void rotate(float angleRad);
    void setToStateColor(bool onState);
    void update(float time);
    void draw();
    
    ofxAnimatableOfPoint pos;
    float angle;
    int width, height;
    ofxAnimatableOfColor color;
    
    bool isRotating;
    
private:
    

};