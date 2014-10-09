//
//  ofxUIButtonArgLabel.h
//
//  Created by enrico<nausea>viola on 9/12/14.
//
//

#pragma once
#include "ofxUIButton.h"
#include "ofxUILabel.h"

class ofxUIButtonArgLabel : public ofxUIButton{
public:
    ofxUIButtonArgLabel();
    ofxUIButtonArgLabel(int _idx, string _name, string _txt, int _size=OFX_UI_FONT_MEDIUM, float w=0, float h=0, float x=0, float y=0);
    ofxUIButtonArgLabel(string _name, string _txt, int _size=OFX_UI_FONT_MEDIUM, float w=0, float h=0, float x=0, float y=0);
    void init(string _name, string _txt, bool *_value, float w, float h, float x, float y, int _size);
    
    void setArgNull();
    void setArgText(string _txt, string _fullTxt="");
    
    bool isArgNull();
    string getArgText();
    string getArgFull();
    
    int getIndex();
    
    ofxUILabel * lab1;
    string nullText;
    string txt;
    string fullTxt;
    int customIdx;
};