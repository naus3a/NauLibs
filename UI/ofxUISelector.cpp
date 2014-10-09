//
//  ofxUISelector.cpp
//
//  Created by nausea on 9/24/14.
//
//

#include "ofxUISelector.h"

ofxUISelector::ofxUISelector() : ofxUILabel(){}

ofxUISelector::ofxUISelector(string _name, vector<string> _items, int _size, int startIdx){
    sItems=_items;
    curItem=0;
    if(startIdx<sItems.size()){
        curItem=startIdx;
    }
    init(0,0,0,0,_name,sItems[curItem],_size);
}

void ofxUISelector::selectPrev(){
    int idx = curItem-1;
    if(idx<0){
        idx = sItems.size()-1;
    }
    select(idx);
}

void ofxUISelector::selectNext(){
    int idx = curItem+1;
    if(idx>(sItems.size()-1)){
        idx = 0;
    }
    select(idx);
}

void ofxUISelector::select(int idx){
    if(idx>=0 && idx<sItems.size()){
        curItem=idx;
        setLabel(sItems[curItem]);
    }
}

int ofxUISelector::getSelectedIdx(){
    return curItem;
}
