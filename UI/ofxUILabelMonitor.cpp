//
//  ofxUILabelMonitor.cpp
//
//  Created by enrico<nausea>viola on 9/12/14.
//
//

#include "ofxUILabelMonitor.h"

ofxUILabelMonitor::ofxUILabelMonitor() : ofxUILabel(){}

ofxUILabelMonitor::ofxUILabelMonitor(string _name, string _textON, string _textOFF, ofColor _colON, ofColor _colOFF,bool * _val, int _size, float x, float y) : ofxUILabel(){
    val = _val;
    textON = _textON;
    textOFF = _textOFF;
    colON = _colON;
    colOFF = _colOFF;
    init(x, y, 0, 0, _name, (*val)?textON:textOFF, _size);
    autoSize = true;
    setColorFill((*val)?colON:colOFF);
}

void ofxUILabelMonitor::switchON(){
    setColorFill(colON);
    setLabel(textON);
}

void ofxUILabelMonitor::switchOFF(){
    setColorFill(colOFF);
    setLabel(textOFF);
}

void ofxUILabelMonitor::checkValue(){
    if(*val){
        switchON();
    }else{
        switchOFF();
    }
}