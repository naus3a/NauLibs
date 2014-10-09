//
//  ofxUILabelMonitor.h
//
//  Created by enrico<nausea>viola on 9/12/14.
//
//

#pragma once
#include "ofxUILabel.h"

class ofxUILabelMonitor : public ofxUILabel{
public:
    ofxUILabelMonitor();
    ofxUILabelMonitor(string _name, string _textON, string _textOFF, ofColor _colON, ofColor _colOFF, bool * _val, int _size, float x=0, float y=0);
    
    void switchON();
    void switchOFF();
    void checkValue();
    
    ofColor colON;
    ofColor colOFF;
    string textON;
    string textOFF;
    bool * val;
};