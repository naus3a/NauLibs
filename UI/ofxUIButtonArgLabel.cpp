//
//  ofxUIButtonArgLabel.cpp
//
//  Created by enrico<nausea>viola on 9/12/14.
//
//

#include "ofxUIButtonArgLabel.h"
#include "ofxUI.h"

ofxUIButtonArgLabel::ofxUIButtonArgLabel() : ofxUIButton(){
    
}

ofxUIButtonArgLabel::ofxUIButtonArgLabel(int _idx, string _name, string _txt, int _size, float w, float h, float x, float y){
    customIdx=_idx;
    useReference=false;
    bool b = false;
    nullText = "-none-";
    init(_name, _txt, &b, w, h, x, y, _size);
}

ofxUIButtonArgLabel::ofxUIButtonArgLabel(string _name, string _txt, int _size, float w, float h, float x, float y){
    useReference=false;
    bool b = false;
    nullText = "-none-";
    customIdx=0;
    init(_name, _txt, &b, w, h, x, y, _size);
}

void ofxUIButtonArgLabel::init(string _name, string _txt, bool *_value, float w, float h, float x, float y, int _size){
    initRect(x,y,w,h);
    
    name = _name;
    txt = _txt;
    fullTxt =  txt;
    kind = OFX_UI_WIDGET_BUTTON;
    
    label = new ofxUILabel((name+" LABEL"),txt,_size);
    addEmbeddedWidget(label);
    
    lab1 = new ofxUILabel(5,3,name+" LABEL1",name,_size);
    addEmbeddedWidget(lab1);
    
    bLabelRight = true;
    
    if(useReference)
    {
        value = _value;
    }
    else
    {
        value = new bool();
        *value = *_value;
    }
    
    setValue(*_value);
}

void ofxUIButtonArgLabel::setArgNull(){
    txt = nullText;
    fullTxt = "";
    label->setLabel(txt);
}

void ofxUIButtonArgLabel::setArgText(string _txt, string _fullTxt){
    txt = _txt;
    fullTxt = _fullTxt;
    label->setLabel(txt);
}

bool ofxUIButtonArgLabel::isArgNull(){
    return (txt==nullText);
}

string ofxUIButtonArgLabel::getArgText(){
    return txt;
}

string ofxUIButtonArgLabel::getArgFull(){
    return fullTxt;
}

int ofxUIButtonArgLabel::getIndex(){
    return customIdx;
}