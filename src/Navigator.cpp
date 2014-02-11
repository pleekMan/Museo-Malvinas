//
//  Navigator.cpp
//  animatableTest
//
//  Created by Wanda on 07/02/14.
//
//

#include "Navigator.h"

void Navigator::setup(string p,ofPoint initPos){
    path = p;

    x = initPos.x;
    y = initPos.y;
    width = height = 700;


    fbo.allocate(width, height);


    titulo.loadImage(path + "/titulo.png");
    titulo.setAnchorPercent(0, 0);
    titulo.setPosition(ofPoint(0, 0));
    titulo.setColor(255,0);
    titulo.color.setDuration(0.3);
    titulo.color.setRepeatType(PLAY_ONCE);
    titulo.color.setCurve(BLINK_AND_FADE_3);

    // BOTONES y CONTENT HOLDERS
    for(int i=0; ofDirectory::doesDirectoryExist(path + "/Content_" + ofToString(i)); i++){
        ofxAnimatableObject<ofImage> button;
        button.loadImage(path + "/Content_" + ofToString(i) + "/button.png");
        button.setAnchorPercent(0, 0);
        button.setPosition(ofPoint(0, 70 + 45*i));
        button.setRotation(ofPoint(0,90,0));
        button.rotation.setDuration(1.0);
        button.rotation.setRepeatType(PLAY_ONCE);
        button.rotation.setCurve(TANH);
        button.setColor(255,0);
        button.color.setDuration(1.0);
        //
        buttons.push_back(button);

        ContentHolder content;
        content.fill(path + "/Content_" + ofToString(i));
        //
        contents.push_back(content);
    }

    currentContent = nextContent = 1;
    

}

void Navigator::appear(){

    titulo.color.animateToAlpha(255);

    float delay = 0.;

    ofPoint rotateTo = ofPoint(0,0,0);
    for(int i=0;i<buttons.size();i++){
        buttons[i].rotation.animateToAfterDelay(ofPoint(rotateTo), delay + i*0.2);
        buttons[i].color.animateToAlpha(200);
    }
    buttons[currentContent].color.animateToAfterDelay(ofColor(255,255), delay + currentContent*0.2);


    delay += 1.;

    contents[currentContent].appear(delay);}

void Navigator::disappear(){

    titulo.color.animateToAlpha(0);

    ofPoint rotateTo = ofPoint(0,90,0);
    for(int i=0;i<buttons.size();i++){
        buttons[i].rotation.animateTo(ofPoint(rotateTo));
        buttons[i].color.animateToAlpha(0);
    }
    contents[currentContent].disappear();
}

void Navigator::update(float time){

    titulo.update(time);

    if(nextContent != currentContent){
        if( !contents[currentContent].isOrWillBeAnimating() ){
            currentContent = nextContent;
            contents[currentContent].appear(0.0);
        }
    }

    for(int i=0;i<buttons.size();i++){
        buttons[i].update(time);
    }


    contents[currentContent].update(time);


    // DRAW INTO FBO
    fbo.begin();

    ofClear(0,0);

    titulo.draw();

    for(int i=0;i<buttons.size();i++){
        buttons[i].draw();
    }


    contents[currentContent].draw();


    ofNoFill();
    ofRect(0, 0, fbo.getWidth(), fbo.getHeight());


    fbo.end();
}

void Navigator::draw(){

    fbo.ofFbo::draw(x, y);

}

void Navigator::checkClick(int mx, int my){

    // CHECK IF MOUSE IS INSIDE NAVIGATOR BEFORE CONTINUING
    if(mx > x && mx < x + fbo.getHeight() && my > y && y + fbo.getHeight()){

        for(int i=0;i<buttons.size();i++){
            if (buttons[i].inside(ofPoint(mx - x, my - y))) {
                cout << "Boton " << i << " - Pressed" << endl;
                optionPressed(i);
            }
        }


        for(int i=0;i<contents[currentContent].thumbs.size();i++){
            if (contents[currentContent].thumbs[i].inside(ofPoint(mx - x, my - y))) {
                cout << "Thumb " << i << " - Pressed" << endl;
                contents[currentContent].thumbPressed(i);
            }
        }

    }

}

void Navigator::optionPressed(int selection){

    if(selection == currentContent || selection == nextContent){
        return;
    }
    else{
        contents[currentContent].disappear();
        nextContent = selection;

        buttons[currentContent].color.animateTo(ofColor(255,200));
        buttons[nextContent].color.animateTo(ofColor(255,255));
    }
}
