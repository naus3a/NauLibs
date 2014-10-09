//
//  ofxUILabelIntRange.h
//
//  Created by nausea on 9/26/14.
//
//

#pragma once
#include "ofxUIWidgetWithLabel.h"

class ofxUILabelIntRange : public ofxUIWidgetWithLabel{
public:
    ofxUILabelIntRange();
    ofxUILabelIntRange(string _label, int * _idx, int _max, int _size);
    void setParent(ofxUIWidget * _parent);
    void refresh();
    string makeCurrentLabel();
    void setMax(int _max);
    
protected:
    void init(float x, float y, float w, float h, string _name, string _label, int * _idx, int _max, int _size);
    
    string txt;
    int * curVal;
    int maxVal;
};