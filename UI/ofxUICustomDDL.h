//
//  ofxUICustomDDL.h
//  MTSandbox
//
//  Created by nausea on 8/1/14.
//
//

#pragma once
#include "ofxUIDropDownList.h"

class ofxUICustomDDL : public ofxUIDropDownList{
public:
    ofxUICustomDDL(string _name, vector<string> items, float w = 0, float x = 0, float y = 0, int _size = OFX_UI_FONT_MEDIUM);
    void makeSingleFixed();
    void customClear();
    void customAddToggle(string fullName, int _idx, int _maxLen=10);
    void selectByRealIdx(int _idx);
    int getSelectedRealIdx();
    
    vector<string>fullNames;
    vector<int>realIdx;
};