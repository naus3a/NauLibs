//
//  ofxUILabelIntRange.cpp
//
//  Created by nausea on 9/26/14.
//
//

#include "ofxUILabelIntRange.h"
#include "ofxUILabel.h"

ofxUILabelIntRange::ofxUILabelIntRange() : ofxUIWidgetWithLabel(){}

ofxUILabelIntRange::ofxUILabelIntRange(string _label, int * idx, int max, int _size){
    init(0, 0, 0, 0, _label, _label, idx, max, _size);
}

void ofxUILabelIntRange::init(float x, float y, float w, float h, string _name, string _label, int *_idx, int _max, int _size){
    initRect(x,y,w,h);
    name=string(_name);
    kind = OFX_UI_WIDGET_LABEL;
    
    txt = _label;
    curVal = _idx;
    maxVal = _max;
    
    label = new ofxUILabel((name+" LABEL"),(txt+": 000 of 000"),_size);
    addEmbeddedWidget(label);
    
    draw_back = OFX_UI_LABEL_DRAW_BACK;
    draw_fill = false;
    draw_back = false;
}

void ofxUILabelIntRange::setParent(ofxUIWidget *_parent){
    parent = _parent;
    rect->setHeight(label->getRect()->getHeight());
    rect->setWidth(label->getRect()->getWidth());
    calculatePaddingRect();
    
    refresh();
}

void ofxUILabelIntRange::refresh(){
    label->setLabel(makeCurrentLabel());
}

string ofxUILabelIntRange::makeCurrentLabel(){
    return (txt+": "+ofToString(*curVal)+" of "+ofToString(maxVal));
}

void ofxUILabelIntRange::setMax(int _max){
    maxVal = _max;
    refresh();
}

