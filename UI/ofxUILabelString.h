//
//  ofxUILabelString.h
//  Created by enrico<nausea>viola on 7/31/14.
//
//

#pragma once
#include "ofxUIWidgetWithLabel.h"

class ofxUILabelString : public ofxUIWidgetWithLabel{
public:
    ofxUILabelString(float x, float y, string _label, string * _val, int _size, int _maxLen=10, bool autoRefresh=false);
    ofxUILabelString(string _label, string * _val, int _size, int _maxLen=10, bool autoRefresh=false);
    void setParent(ofxUIWidget * _parent);
    string makeCurrentLabel();
    void refresh();
    
protected:
    void init(float x, float y, string _name, string * _val, int _size, int _maxLen, bool autoRefresh);
    
    string * val;
    int maxLen;
    bool bAuto;
};