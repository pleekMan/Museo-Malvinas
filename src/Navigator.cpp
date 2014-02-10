//
//  Navigator.cpp
//  animatableTest
//
//  Created by Wanda on 07/02/14.
//
//

#include "Navigator.h"

void Navigator::setup(ofPoint initPos){
    
    x = initPos.x;
    y = initPos.y;
    width = height = 700;
    
    
    fbo.allocate(width, height);
    
    
    titulo.loadImage("Navigator_0/titulo.png");
    titulo.setAnchorPercent(0, 0);
    titulo.setPosition(ofPoint(0, 0));
    titulo.setColor(255,0);
    titulo.color.setDuration(0.3);
    titulo.color.setRepeatType(PLAY_ONCE);
    titulo.color.setCurve(BLINK_AND_FADE_3);
    
    // BOTONES
    boton01.loadImage("Navigator_0/buttons/button_0.png");
    boton01.setAnchorPercent(0, 0);
    boton01.setPosition(ofPoint(0, 70));
    boton01.setRotation(ofPoint(0,90,0));
    boton01.rotation.setDuration(1.0);
    boton01.rotation.setRepeatType(PLAY_ONCE);
    boton01.rotation.setCurve(TANH);
    //
    boton01.setColor(255,0);
    boton01.color.setDuration(1.0);
    
    boton02.loadImage("Navigator_0/buttons/button_1.png");
    boton02.setAnchorPercent(0, 0);
    boton02.setPosition(ofPoint(0, 115));
    boton02.setRotation(ofPoint(0,90,0));
    boton02.rotation.setDuration(1.0);
    boton02.rotation.setRepeatType(PLAY_ONCE);
    boton02.rotation.setCurve(TANH);
    //
    boton02.setColor(255,0);
    boton02.color.setDuration(1.0);
    
    boton03.loadImage("Navigator_0/buttons/button_2.png");
    boton02.setAnchorPercent(0, 0);
    boton03.setPosition(ofPoint(0, 160));
    boton03.setRotation(ofPoint(0,90,0));
    boton03.rotation.setDuration(1.0);
    boton03.rotation.setRepeatType(PLAY_ONCE);
    boton03.rotation.setCurve(TANH);
    //
    boton03.setColor(255,0);
    boton03.color.setDuration(1.0);
    
    
    imagen01.loadImage("Navigator_0/Content_0/images/image_0.png");
    imagen01.setAnchorPercent(0.,0.);
    imagen01.setPosition(0,260);
    imagen01.setMaskType(DIAGONAL);
    imagen01.setMask(0.);
    imagen01.mask.setDuration(.5);
    imagen01.mask.setRepeatType(PLAY_ONCE);
    
    imagen02.loadImage("Navigator_0/Content_0/images/image_1.png");
    imagen02.setAnchorPercent(0.,0.);
    imagen02.setPosition(0,260);
    imagen02.setMaskType(DIAGONAL);
    imagen02.setMask(0.);
    imagen02.mask.setDuration(.5);
    imagen02.mask.setRepeatType(PLAY_ONCE);
    
    texto01.loadImage("Navigator_0/Content_0/texts/text_0.png");
    texto01.setAnchorPercent(0.,0.);
    texto01.setPosition(385,260);
    texto01.setMaskType(DIAGONAL);
    texto01.setMask(0.);
    texto01.mask.setDuration(0.5);
    texto01.mask.setRepeatType(PLAY_ONCE);
    
    texto02.loadImage("Navigator_0/Content_0/texts/text_1.png");
    texto02.setAnchorPercent(0.,0.);
    texto02.setPosition(385,260);
    texto02.setMaskType(DIAGONAL);
    texto02.setMask(0.);
    texto02.mask.setDuration(0.5);
    texto02.mask.setRepeatType(PLAY_ONCE);
    
    // THUMBS
    
    float thumbHalfSize = 35;
    
    thumb01.loadImage("Navigator_0/Content_0/thumbs/th_0.png");
    thumb01.setAnchorPercent(0.5, 0.5);
    thumb01.setPosition(ofPoint(0 + thumbHalfSize, 630));
    thumb01.setSize(0.0);
    thumb01.size.setDuration(0.5);
    thumb01.size.setRepeatType(PLAY_ONCE);
    thumb01.size.setCurve(TANH);
    
    thumb02.loadImage("Navigator_0/Content_0/thumbs/th_1.png");
    thumb02.setAnchorPercent(0.5, 0.5);
    thumb02.setPosition(ofPoint(70 + thumbHalfSize, 630));
    thumb02.setSize(0.0);
    thumb02.size.setDuration(0.5);
    thumb02.size.setRepeatType(PLAY_ONCE);
    thumb02.size.setCurve(TANH);
    
    thumb03.loadImage("Navigator_0/Content_0/thumbs/th_2.png");
    thumb03.setAnchorPercent(0.5, 0.5);
    thumb03.setPosition(ofPoint(140 + thumbHalfSize, 630));
    thumb03.setSize(0.0);
    thumb03.size.setDuration(0.5);
    thumb03.size.setRepeatType(PLAY_ONCE);
    thumb03.size.setCurve(TANH);
    
    
}

void Navigator::initialize(){
    
    titulo.color.animateToAlpha(255);
    
    ofPoint rotateTo = ofPoint(0,0,0);
    boton01.rotation.animateTo(ofPoint(rotateTo));
    boton01.color.animateToAlpha(255);
    boton02.rotation.animateToAfterDelay(ofPoint(rotateTo), 0.2);
    boton02.color.animateToAlpha(255);
    boton03.rotation.animateToAfterDelay(ofPoint(rotateTo), 0.4);
    boton03.color.animateToAlpha(255);

    
    imagen01.mask.animateToAfterDelay(1.0, 1.0);
    texto01.mask.animateToAfterDelay(1.0, 1.3);
    
    thumb01.size.animateToAfterDelay(1.0, 2);
    thumb02.size.animateToAfterDelay(1.0, 2.2);
    thumb03.size.animateToAfterDelay(1.0, 2.4);
}

void Navigator::update(float time){
    
  
    titulo.update(time);
    
    boton01.update(time);
    boton02.update(time);
    boton03.update(time);
    
    imagen01.update(time);
    texto01.update(time);
    
    thumb01.update(time);
    thumb02.update(time);
    thumb03.update(time);
    
    
    // DRAW INTO FBO
    fbo.begin();
    
    ofClear(0,0);
    
    titulo.draw();
    
    boton01.draw(); 
    boton02.draw();
    boton03.draw();
    
    imagen01.draw();
    texto01.draw();
    
    thumb01.draw();
    thumb02.draw();
    thumb03.draw();
    
    ofNoFill();
    ofRect(0, 0, fbo.getWidth(), fbo.getHeight());
    
    ofLine(ofPoint(100,100), boton02.position.getCurrentPosition());
    
    fbo.end();
}

void Navigator::draw(){
    
    fbo.ofFbo::draw(x, y);
    
}

void Navigator::checkClick(int mx, int my){
    
    // CHECK IF MOUSE IS INSIDE NAVIGATOR BEFORE CONTINUING
    if(mx > x && mx < x + fbo.getHeight() && my > y && y + fbo.getHeight()){
       
        
        if (boton01.inside(ofPoint(mx - x, my - y))) {
            cout << "Boton 01 - Pressed" << endl;
            optionPressed("MENU", 0);
        } else if (boton02.inside(ofPoint(mx - x, my - y))){
            cout << "Boton 02 - Pressed" << endl;
            optionPressed("MENU", 1);
        } else {
            
        }
        
    }
    
}

void Navigator::optionPressed(string optionType, int selection){
    
}
