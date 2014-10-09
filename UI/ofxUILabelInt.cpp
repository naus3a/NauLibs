//
//  ofxUILabelInt.cpp
//
//  Created by enrico<nausea>viola on 7/31/14.
//
//

#include "ofxUILabelInt.h"
#include "ofxUI.h"

ofxUILabelInt::ofxUILabelInt(float x, float y, string _label, int * _val, int _size, bool autoRefresh) : ofxUIWidgetWithLabel(){
    bUsingRef=true;
    rVal = _val;
    init(x, y, _label, _size, autoRefresh);
}

ofxUILabelInt::ofxUILabelInt(string _label, int * _val, int _size, bool autoRefresh) : ofxUIWidgetWithLabel(){
    bUsingRef=true;
    rVal = _val;
    init(0, 0, _label, _size, autoRefresh);
}

ofxUILabelInt::ofxUILabelInt(float x, float y, string _label, int _val, int _size) : ofxUIWidgetWithLabel(){
    bUsingRef=false;
    //rVal = &_val;
    rVal = NULL;
    val = _val;
    init(x, y, _label, _size, false);
}

ofxUILabelInt::ofxUILabelInt(string _label, int _val, int _size) : ofxUIWidgetWithLabel(){
    bUsingRef=false;
    //rVal = &_val;
    rVal = NULL;
    val = _val;
    init(0, 0, _label, _size, false);
}

ofxUILabelInt::~ofxUILabelInt(){
    ofxUIWidgetWithLabel::~ofxUIWidgetWithLabel();
    if(!bUsingRef){
        delete rVal;
    }
}

void ofxUILabelInt::init(float x, float y, string _name, int _size, bool autoRefresh){
    
    bAuto = autoRefresh;
    
    initRect(x,y,0,0);
    name = string(_name);
    kind = OFX_UI_WIDGET_LABEL;
    
    label = new ofxUILabel(0,0,(name+" LABEL"), (name+": 000"), _size);
    addEmbeddedWidget(label);
    
    draw_back = OFX_UI_LABEL_DRAW_BACK;
    draw_fill = false;
    draw_back = false;
}

void ofxUILabelInt::setParent(ofxUIWidget *_parent){
    parent = _parent;
    rect->setHeight(label->getRect()->getHeight());
    rect->setWidth(label->getRect()->getWidth());
    calculatePaddingRect();
    
    refresh();
}

string ofxUILabelInt::makeCurrentLabel(){
    if(bUsingRef){
        return (name+": "+ofToString(*rVal));
    }else{
        return (name+": "+ofToString(val));
    }
}

void ofxUILabelInt::refresh(){
    label->setLabel(makeCurrentLabel());
}

void ofxUILabelInt::setValue(int _val){
    val = _val;
    refresh();
}