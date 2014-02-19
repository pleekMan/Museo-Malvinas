//
//  ContentHolder.cpp
//  animatableTest
//
//  Created by Wanda on 10/02/14.
//
//

#include "ContentHolder.h"
#include "ofMain.h"


void ContentHolder::setup(string path, ofPoint pos){

    float thumbHalfSize = 35;
    for(int i=0; ofDirectory::doesDirectoryExist(path + "/Image_" + ofToString(i)); i++){
        thumbs.push_back(ofxAnimatableObject<ofImage>());
        images.push_back(ofxAnimatableImageMasked());
    }
    
    for(int i=0; ofDirectory::doesDirectoryExist(path + "/Text_" + ofToString(i)); i++){
        texts.push_back(ofxAnimatableImageMasked());
    }

    
    for(int i=0; i<thumbs.size(); i++){
        thumbs[i].loadImage(path + "/Image_" + ofToString(i) + "/thumb.png");
    }
    for(int i=thumbs.size() - 1; i >= 0; i--){
        thumbs[i].setPosition(pos.x + 560 - ((thumbs.size() - 1 -i) * 45) + thumbHalfSize,pos.y + 530);
        thumbs[i].setAnchorPercent(0.5, 0.5);
        thumbs[i].setSize(0.0);
        thumbs[i].size.setDuration(0.5);
        thumbs[i].size.setRepeatType(PLAY_ONCE);
        thumbs[i].size.setCurve(TANH);
        thumbs[i].setColor(255,200);
        thumbs[i].color.setDuration(0.5);
        thumbs[i].color.setRepeatType(PLAY_ONCE);
        thumbs[i].color.setCurve(EASE_IN);
    }
    
    for(int i=0; i<images.size(); i++){
        images[i].loadImage(path + "/Image_" + ofToString(i) + "/image.png");
        images[i].setAnchorPercent(0.,0.);  
        //images[i].setPosition(pos.x,pos.y);
        images[i].setPosition(pos.x + 265,pos.y + 10);
        images[i].setMaskType(DIAGONAL);
        images[i].setMask(1);
        images[i].mask.setDuration(.7);
        images[i].mask.setRepeatType(PLAY_ONCE);
        images[i].setColor(ofColor(255,0));
        images[i].color.setDuration(.5);
    }
    for(int i=0; i<texts.size(); i++){
        texts[i].loadImage(path + "/Text_" + ofToString(i) + "/text.png");
        texts[i].setAnchorPercent(0.,0.);
        texts[i].setPosition(pos.x,pos.y);
        texts[i].setMaskType(HORIZONTAL);
        texts[i].setMask(0.);
        texts[i].mask.setDuration(0.5);
        texts[i].mask.setRepeatType(PLAY_ONCE);
        texts[i].setColor(ofColor(255,0));
        texts[i].color.setDuration(.5);
        
    }
    
    textBack.loadImage(path + "/textBack.png");
    textBack.setAnchorPercent(0.,0.);
    textBack.setPosition(pos.x,pos.y);
    textBack.setMaskType(HORIZONTAL);
    textBack.setMask(0.);
    textBack.mask.setDuration(0.5);
    textBack.mask.setRepeatType(PLAY_ONCE);
    textBack.setColor(ofColor(255,0));
    textBack.color.setDuration(.5);
    
    imageBack.loadImage(path + "/../imageBack.png");
    imageBack.setAnchorPercent(0.,0.);
    imageBack.setPosition(pos.x + 255,pos.y);
    imageBack.setMaskType(HORIZONTAL);
    imageBack.setMask(0.);
    imageBack.mask.setDuration(0.5);
    imageBack.mask.setRepeatType(PLAY_ONCE);
    imageBack.setColor(ofColor(255,0));
    imageBack.color.setDuration(.5);
    
    dottedLine.loadImage(path + "/../dottedLine.png");
    dottedLine.setAnchorPercent(0.,0.);
    dottedLine.setPosition(pos.x + 255,pos.y);
    dottedLine.setMaskType(HORIZONTAL);
    dottedLine.setMask(0.);
    dottedLine.mask.setDuration(0.5);
    dottedLine.mask.setRepeatType(PLAY_ONCE);
    dottedLine.setColor(ofColor(255,0));
    dottedLine.color.setDuration(.5);

    currentThumb = nextThumb = 0;

    currentText = nextText = 0;
    
    
}
void ContentHolder::appear(float delay){

    reset();
    
    images[currentThumb].setColor(255,255);
    images[currentThumb].setMask(0.);
    images[currentThumb].mask.animateToAfterDelay(1.0, delay);
    
    texts[currentText].setColor(255,255);
    texts[currentText].setMask(0.);
    texts[currentText].mask.animateToAfterDelay(1.0, delay + 0.4);
    
    textBack.setColor(255,255);
    textBack.setMask(0.);
    textBack.mask.animateToAfterDelay(1.0, delay + 0.4);
    
    imageBack.setColor(255,255);
    imageBack.setMask(0.);
    imageBack.mask.animateToAfterDelay(1.0, delay + 0.4);
    
    dottedLine.setColor(255,255);
    dottedLine.setMask(0.);
    dottedLine.mask.animateToAfterDelay(1.0, delay + 0.4);

    delay += 0.5;

    for(int i=0; i<thumbs.size(); i++){
        thumbs[i].size.animateToAfterDelay(1.0, delay + i*0.2);
    }
    thumbs[currentThumb].color.animateToAfterDelay(ofColor(255,255),delay + currentThumb*0.2);
}

void ContentHolder::disappear(){

    images[currentThumb].color.animateTo(ofColor(255,0));
    images[currentThumb].mask.animateTo(0.);
    
    texts[currentText].color.animateTo(ofColor(255,0));
    texts[currentText].mask.animateTo(0.);
    
    textBack.color.animateTo(ofColor(255,0));
    textBack.mask.animateTo(0.);
    
    imageBack.color.animateTo(ofColor(255,0));
    imageBack.mask.animateTo(0.);
    
    dottedLine.color.animateTo(ofColor(255,0));
    dottedLine.mask.animateTo(0.);

    for(int i=0; i<thumbs.size(); i++){
        thumbs[i].size.animateTo(0.0);
        thumbs[i].color.animateTo(ofColor(255,200));
    }

    nextThumb = currentThumb;
}

void ContentHolder::update(float time){
    
    images[currentThumb].update(time);
    texts[currentText].update(time);

    if( currentThumb != nextThumb ){
        images[nextThumb].update(time);
        if( !images[currentThumb].isOrWillBeAnimating() ){
            currentThumb = nextThumb;
        }
    }
    
    if( currentText != nextText ){
        texts[nextText].update(time);
        if( !texts[currentText].isOrWillBeAnimating() ){
            currentText = nextText;
        }
    }
    
    textBack.update(time);
    imageBack.update(time);
    dottedLine.update(time);
    //cout << "Current " + ofToString(currentThumb) + ": " + ofToString(images[currentThumb].color.getCurrentColor());
    //cout << " // Next " + ofToString(nextThumb) + ": " + ofToString(images[nextThumb].color.getCurrentColor()) << endl;

    for(int i=0; i<thumbs.size(); i++){
        thumbs[i].update(time);
    }
}

void ContentHolder::draw(){
    textBack.draw();
    imageBack.draw();
    dottedLine.draw();
    
    //ofRect(imageBack.position.getCurrentPosition(), 2, 2);
    
    images[currentThumb].draw();
    texts[currentText].draw();

    if( currentThumb != nextThumb){
        images[nextThumb].draw();
    }
    
    if( currentText != nextText ){
        texts[nextText].draw();
    }

     for(int i=0; i<thumbs.size(); i++){
        thumbs[i].draw();
        //ofLine(ofPoint(thumbs[i].anchor.x,thumbs[i].anchor.y), ofPoint(ofGetAppPtr() -> mouseX, ofGetAppPtr() -> mouseY));
        
        //ofRect(thumbs[i].position.getCurrentPosition(), thumbs[i].getWidth(), thumbs[i].getHeight());
    }
     
}

void ContentHolder::thumbPressed(int selection){
    if(selection == currentThumb || selection == nextThumb){
        return;
    }
    else{
        if(currentThumb != nextThumb){
           thumbs[nextThumb].color.animateTo(ofColor(255,200));
        }
        images[currentThumb].color.animateToAlpha(0);
        images[currentThumb].mask.animateTo(0.);
        //texts[currentText].color.animateTo(0.);
        //texts[currentText].mask.animateTo(0.);
        
        
        nextThumb = selection;
        nextText = 0;
        
        //cout << ofToString(images[nextThumb].color.getCurrentColor()) << endl;
        
        //images[nextThumb].color.animateToAlpha(255);
        images[nextThumb].setColor(ofColor(255,255));
        images[nextThumb].setMask(0);
        images[nextThumb].mask.animateTo(1.0);
        
        //texts[nextThumb][nextText].setColor(ofColor(255,255));
        //texts[nextThumb][nextText].setMask(0);
        //texts[nextThumb][nextText].mask.animateToAfterDelay(1.0,0.3);

        thumbs[currentThumb].color.animateTo(ofColor(255,200));
        thumbs[nextThumb].color.animateTo(ofColor(255,255));
    }
}

void ContentHolder::textPressed(bool forwardDirection){
    if(forwardDirection){
        if((currentText+1)<texts.size()){
            texts[currentText].mask.animateTo(2.);
            nextText=currentText+1;
            texts[nextText].setColor(ofColor(255,255));
            texts[nextText].mask.animateTo(1.);
        }
    }
    else{
        if((currentText-1)>=0){
            texts[currentText].mask.animateTo(0.);
            nextText=currentText-1;
            texts[nextText].setColor(ofColor(255,255));
            texts[nextText].mask.animateTo(1.);
        }
    }
}

bool ContentHolder::isOrWillBeAnimating(){

    bool iowba = false;
    iowba |= images[currentThumb].isOrWillBeAnimating();
    iowba |= texts[currentText].isOrWillBeAnimating();
    
    if( currentThumb != nextThumb ){
        iowba |= images[nextThumb].isOrWillBeAnimating();
    }
    
    if( currentText != nextText ){
        iowba |= texts[nextText].isOrWillBeAnimating();
    }

    for(int i=0; i<thumbs.size(); i++){
        iowba |= thumbs[i].isOrWillBeAnimating();
    }

    return iowba;
}

void ContentHolder::reset(){
    
    currentThumb = nextThumb = 0;
    
    currentText = nextText = 0;
 
   
    for (int i=0; i < images.size(); i++) {
        images[i].setMask(0);
        images[i].setColor(ofColor(255,0));
    }
    
    for (int i=0; i<texts.size(); i++) {
        texts[i].setMask(0);
        texts[i].setColor(ofColor(255,0));
    }
    
    
}
