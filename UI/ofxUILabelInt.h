//
//  ofxUILabelInt.h
//
//  Created by enrico<nausea>viola on 7/31/14.
//
//

#pragma once
#include "ofxUIWidgetWithLabel.h"

class ofxUILabelInt : public ofxUIWidgetWithLabel{
public:
    ofxUILabelInt(float x, float y, string _label, int * _val, int _size, bool autoRefresh=false);
    ofxUILabelInt(string _label, int * _val, int _size, bool autoRefresh=false);
    ofxUILabelInt(float x, float y, string _label, int _val, int _size);
    ofxUILabelInt(string _label, int _val, int _size);
    ~ofxUILabelInt();
    void setParent(ofxUIWidget * _parent);
    string makeCurrentLabel();
    void refresh();
    void setValue(int _val);

protected:
    void init(float x, float y, string _name, int _size, bool autoRefresh);

    int * rVal;
    int val;
    bool bAuto;
    bool bUsingRef;
};