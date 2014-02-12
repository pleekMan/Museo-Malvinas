//
//  ContentHolder.cpp
//  animatableTest
//
//  Created by Wanda on 10/02/14.
//
//

#include "ContentHolder.h"
#include "ofMain.h"


void ContentHolder::setup(string path){

    float thumbHalfSize = 35;
    for(int i=0; ofDirectory::doesDirectoryExist(path + "/Thumb_" + ofToString(i)); i++){
        ofxAnimatableObject<ofImage> thumb;
        thumb.loadImage(path + "/Thumb_" + ofToString(i) + "/thumb.png");
        
        thumb.setPosition(ofPoint(i*70 + thumbHalfSize, 610));
        thumb.setAnchorPercent(0.5, 0.5);
        thumb.setSize(0.0);
        thumb.size.setDuration(0.5);
        thumb.size.setRepeatType(PLAY_ONCE);
        thumb.size.setCurve(TANH);
        thumb.setColor(255,200);
        thumb.color.setDuration(0.5);
        thumb.color.setRepeatType(PLAY_ONCE);
        thumb.color.setCurve(EASE_IN);
        //
        thumbs.push_back(thumb);

        ofxAnimatableImageMasked image;
        image.loadImage(path + "/Thumb_" + ofToString(i) + "/image.png");
        image.setAnchorPercent(0.,0.);
        image.setPosition(0,260);
        image.setMaskType(DIAGONAL);
        image.setMask(1);
        image.mask.setDuration(.7);
        image.mask.setRepeatType(PLAY_ONCE);
        image.color.setAlphaOnly(0);
        image.color.setDuration(.5);
        //
        images.push_back(image);

        vector<ofxAnimatableImageMasked> textsSet;
        for(int j=0; ofFile::doesFileExist(path + "/Thumb_" + ofToString(i) + "/text" + ofToString(j) + ".png"); j++){
            ofxAnimatableImageMasked text;
            text.loadImage(path + "/Thumb_" + ofToString(i) + "/text" + ofToString(j) + ".png");
            text.setAnchorPercent(0.,0.);
            text.setPosition(385,260);
            text.setMaskType(DIAGONAL);
            text.setMask(0.);
            text.mask.setDuration(0.5);
            text.mask.setRepeatType(PLAY_ONCE);
            //
            textsSet.push_back(text);
        }
        texts.push_back(textsSet);

        /*ofxAnimatableObject<ofImage> currentImage;
        currentImage.loadImage("Navigator_0/Content_0/" + ofToString(i) + "/image.png");
        images.push_back(currentImage);

        ofxAnimatableObject<ofImage> currentThumb;
        currentThumb.loadImage("Navigator_0/Content_0/" + ofToString(i) + "/thumb.png");
        thumbs.push_back(currentThumb);

        ofxAnimatableObject<ofImage> currentText;
        currentText.loadImage("Navigator_0/Content_0/" + ofToString(i) + "/text.png");
        texts.push_back(currentText);*/
    }
    

    currentThumb = nextThumb = 0;

    currentText = nextText = 0;
    
    
}
void ContentHolder::appear(float delay){

    reset();
    
    images[0].color.setAlphaOnly(255);
    images[0].setMask(0);
    images[0].mask.animateTo(1);
    
    //images[currentThumb].setColor(255,255);
    images[currentThumb].mask.animateToAfterDelay(1.0, delay);
    texts[currentThumb][currentText].mask.animateToAfterDelay(1.0, delay + 0.4);

    delay += 0.5;

    for(int i=0; i<thumbs.size(); i++){
        thumbs[i].size.animateToAfterDelay(1.0, delay + i*0.2);
    }
    thumbs[currentThumb].color.animateToAfterDelay(ofColor(255,255),delay + currentThumb*0.2);
}

void ContentHolder::disappear(){

    //images[currentThumb].mask.animateTo(0.0);
    cout << "Disappearing" << endl;
    images[currentThumb].color.animateToAlpha(0);
    texts[currentThumb][currentText].mask.animateTo(0.0);

    for(int i=0; i<thumbs.size(); i++){
        thumbs[i].size.animateTo(0.0);
        thumbs[i].color.animateTo(ofColor(255,200));
    }

    nextThumb = currentThumb;
}

void ContentHolder::update(float time){

    if(currentThumb != nextThumb){
        if( !images[currentThumb].isOrWillBeAnimating() && !texts[currentThumb][currentText].isOrWillBeAnimating() ){
            currentThumb = nextThumb;
            currentText = nextText = 0;
            //images[currentThumb].mask.animateToAfterDelay(1.0,0.0);
            //texts[currentThumb][currentText].mask.animateToAfterDelay(1.0,0.3);
            
        }
        
        images[nextThumb].update(time);
        texts[nextThumb][nextText].update(time);
    }

    images[currentThumb].update(time);
    texts[currentThumb][currentText].update(time);
    
    //cout << "Current " + ofToString(currentThumb) + ": " + ofToString(images[currentThumb].color.getCurrentColor());
    //cout << " // Next " + ofToString(nextThumb) + ": " + ofToString(images[nextThumb].color.getCurrentColor()) << endl;

    for(int i=0; i<thumbs.size(); i++){
        thumbs[i].update(time);
    }
}

void ContentHolder::draw(){

    if( currentThumb != nextThumb){
        
        images[currentThumb].draw();
        texts[currentThumb][currentText].draw();
    }
    
    images[nextThumb].draw();
    texts[nextThumb][nextText].draw();

     for(int i=0; i<thumbs.size(); i++){
        thumbs[i].draw();
       // ofLine(ofPoint(thumbs[i].anchor.x,thumbs[i].anchor.y), ofPoint(ofGetAppPtr() -> mouseX, ofGetAppPtr() -> mouseY));
        
        //ofRect(thumbs[i].position.getCurrentPosition(), thumbs[i].getWidth(), thumbs[i].getHeight());
    }
     
}

void ContentHolder::thumbPressed(int selection){
    if(selection == currentThumb || selection == nextThumb){
        return;
    }
    else{
        images[currentThumb].color.animateToAlpha(0);
        //images[currentThumb].mask.animateTo(0.0);
        texts[currentThumb][currentText].mask.animateTo(0.0);
        
        
        nextThumb = selection;
        
        cout << ofToString(images[nextThumb].color.getCurrentColor()) << endl;
        
        //images[nextThumb].color.animateToAlpha(255);
        images[nextThumb].color.setAlphaOnly(255);
        images[nextThumb].setMask(0);
        images[nextThumb].mask.animateTo(1.0);
        texts[nextThumb][nextText].mask.animateToAfterDelay(1.0,0.3);

        thumbs[currentThumb].color.animateTo(ofColor(255,200));
        thumbs[nextThumb].color.animateTo(ofColor(255,255));
    }
}

bool ContentHolder::isOrWillBeAnimating(){

    bool iowba = false;
    iowba |= images[currentThumb].isOrWillBeAnimating();
    iowba |= texts[currentThumb][currentText].isOrWillBeAnimating();

    for(int i=0; i<thumbs.size(); i++){
        iowba |= thumbs[i].isOrWillBeAnimating();
    }

    return iowba;
}

void ContentHolder::reset(){
    
    currentThumb = nextThumb = 0;
    
    currentText = nextText = 0;
    
    cout << images.size() << endl;
    
    //images[0].setMask(0);
    //images[0].color.setAlphaOnly(0);
    
   
     for (int i=0; i < images.size(); i++) {
        images[i].setMask(0);
        images[i].color.setAlphaOnly(0);
    }
    
    
}
