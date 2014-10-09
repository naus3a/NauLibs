//
//  NauMisc.h
//
//  Created by nausea on 6/24/14.
//
//

#pragma once
#include "ofMain.h"

namespace NauMisc {
    //line equation
    float getSlope(ofVec2f p1, ofVec2f p2);
    float getYintercept(ofVec2f p, float m);
    float getVDistFromLine(ofVec2f p, float m, float q);
    //---
    
    //file system
    vector<ofFile> getFilesInDir(string dir, string ext);
    void space2underscore(string * s);
    string int2stringSeq(int idx, int digits);
    bool isFileFormatSupported(string fileName, vector<string> * ext);
    bool isProperFilename(string fileName);
    string insertEveryNChars(string origin, string what, int n);
    string extractSource(string pth);
    ofFileDialogResult customSaveDialog(string defaultName, string messageName, string defaultPath="");
    void getFocus();
    //---
}
