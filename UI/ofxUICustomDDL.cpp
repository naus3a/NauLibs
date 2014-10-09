//
//  ofxUICustomDDL.cpp
//  MTSandbox
//
//  Created by nausea on 8/1/14.
//
//

#include "ofxUICustomDDL.h"

ofxUICustomDDL::ofxUICustomDDL(string _name, vector<string> items, float w, float x, float y, int _size) : ofxUIDropDownList(_name, items, w, x, y, _size){
    //init(_name, items, w, x, y, _size);
}

void ofxUICustomDDL::makeSingleFixed(){
    setAllowMultiple(false);
    setAutoClose(false);
    open();
}

void ofxUICustomDDL::customClear(){
    clearToggles();
    fullNames.clear();
    realIdx.clear();
}

void ofxUICustomDDL::customAddToggle(string fullName, int _idx, int _maxLen){
    fullNames.push_back(fullName);
    realIdx.push_back(_idx);
    if(fullName.length()>_maxLen){
        fullName.resize(_maxLen);
        fullName+="...";
    }
    addToggle(fullName);
}

void ofxUICustomDDL::selectByRealIdx(int _idx){
    for(int i=0;i<realIdx.size();i++){
        if(realIdx[i]==_idx){
            activateToggle(getToggles()[i]->getName());
            i=realIdx.size()+2;
        }
    }
}

int ofxUICustomDDL::getSelectedRealIdx(){
    int ii = -1;
    vector<int> si = getSelectedIndeces();
    if(si.size()>0){
        ii = realIdx[si[0]];
    }
    return ii;
}

