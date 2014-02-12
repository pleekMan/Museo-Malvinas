//
//  FunkyRect.cpp
//  animatableTest
//
//  Created by Wanda on 11/02/14.
//
//

#include "FunkyRect.h"


void FunkyRect::setup(bool state, ofPoint _pos, float _width, float _height){
    
    setToStateColor(state);
    
    color.setDuration(0.5);
    pos.setPosition(_pos);
    width = _width;
    height = _height;
    angle = 0;
    
    isRotating = false;
    
    
}

void FunkyRect::setState(bool onState){
    setToStateColor(onState);
}

void FunkyRect::update(float time){
    pos.update(time);
    color.update(time);
    
    


}

void FunkyRect::draw(){
    
    if (isRotating) {
           
    ofPushMatrix();
    ofTranslate(pos.getCurrentPosition().x, pos.getCurrentPosition().y);
    
    ofRotate(ofRadToDeg(angle));


    ofSetColor(color.getCurrentColor());
    ofFill();
    ofRect(-(width * 0.5), -(height * 0.5), width, height);
    ofSetColor(255,255);
    
    ofPopMatrix();
        
    } else {
        
        ofSetColor(color.getCurrentColor());
        ofFill();
        ofRect(pos.getCurrentPosition().x, pos.getCurrentPosition().y, width, height);
        ofSetColor(255,255);
        
    }
}

void FunkyRect::moveTo(ofPoint target){
    pos.animateTo(target);
}

void FunkyRect::rotate(float angleRad){
    isRotating = true;
    angle = angleRad;
}

void FunkyRect::colorTo(ofColor targetColor){
    color.animateTo(targetColor);
}

void FunkyRect::setToStateColor(bool onState){
    
    if(onState){
        color.animateTo(ofColor (255,0,0,255));
    } else{
        color.animateTo(ofColor (255,0,0,20));
    }
}