//
//  ofxUILabelString.cpp
//  Created by enrico<nausea>viola on 7/31/14.
//
//

#include "ofxUILabelString.h"
#include "ofxUI.h"

ofxUILabelString::ofxUILabelString(float x, float y, string _label, string * _val, int _size, int _maxLen, bool autoRefresh) : ofxUIWidgetWithLabel(){
    init(x, y, _label, _val, _size, _maxLen, autoRefresh);
}

ofxUILabelString::ofxUILabelString(string _label, string * _val, int _size, int _maxLen, bool autoRefresh) : ofxUIWidgetWithLabel(){
    init(0, 0, _label, _val, _size, _maxLen, autoRefresh);
}

void ofxUILabelString::init(float x, float y, string _name, string *_val, int _size, int _maxLen, bool autoRefresh){
    bAuto = autoRefresh;
    val = _val;
    maxLen = _maxLen;
    
    initRect(x,y,0,0);
    name = string(_name);
    kind = OFX_UI_WIDGET_LABEL;
    
    string s = "M";
    for(int i=2;i<maxLen;i++){
        s+="M";
    }
    label = new ofxUILabel(0,0,(name+" LABEL"), (name+": "+s), _size);
    addEmbeddedWidget(label);
    
    draw_back = OFX_UI_LABEL_DRAW_BACK;
    draw_fill = false;
    draw_back = false;
}

void ofxUILabelString::setParent(ofxUIWidget *_parent){
    parent = _parent;
    rect->setHeight(label->getRect()->getHeight());
    rect->setWidth(label->getRect()->getWidth());
    calculatePaddingRect();
    
    refresh();
}

string ofxUILabelString::makeCurrentLabel(){
    string s = *val;
    if(s.length()>maxLen){
        s.resize(maxLen);
    }
    return (name+": "+s);
}

void ofxUILabelString::refresh(){
    label->setLabel(makeCurrentLabel());
}