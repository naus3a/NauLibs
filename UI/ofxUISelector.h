//
//  ofxUISelector.h
//
//  Created by nausea on 9/24/14.
//
//

#pragma once
#include "ofxUILabel.h"

class ofxUISelector : public ofxUILabel{
public:
    ofxUISelector();
    ofxUISelector(string _name, vector<string> _items, int _size, int startIdx=0);
    
    void select(int idx);
    void selectPrev();
    void selectNext();
    int getSelectedIdx();
    
    vector<string> sItems;
    int curItem;
};