//
//  NauMisc.cpp
//  dar
//
//  Created by nausea on 6/24/14.
//
//

#include "NauMisc.h"

namespace NauMisc {
    //equation
    float getSlope(ofVec2f p1, ofVec2f p2){
        return ((p1.y-p2.y)/(p1.x-p2.x));
    }
    
    float getYintercept(ofVec2f p, float m){
        return  (p.y - (m * p.x));
    }
    
    float getVDistFromLine(ofVec2f p, float m, float q){
        float y = m*p.x + q;
        return abs(p.y-y);
    }
    //---
    
    //file system
    vector<ofFile> getFilesInDir(string dir, string ext){
        vector<ofFile> files;
        ofDirectory theDir(dir);
        if(theDir.exists()){
            theDir.allowExt(ext);
            theDir.listDir();
            files = theDir.getFiles();
        }
        return files;
    }
    
    void space2underscore(string * s){
        for(int i=0;i<s->size();i++){
            if(s->at(i)==' '){
                s->at(i)='_';
            }
        }
    }
    
    string int2stringSeq(int idx, int digits){
        string s = ofToString(idx,0);
        if(s.size()<digits){
            int zeroes = digits - s.size();
            string sz="";
            for(int i=0;i<zeroes;i++){
                sz+="0";
            }
            s = sz + s;
        }else if(s.size()>digits){
            s = s.substr(0,digits);
        }
        return s;
    }
    
    bool isProperFilename(string fileName){
        bool b = false;
        if(fileName.size()>4){
            if(fileName[(fileName.size()-4)]=='.'){
                b = true;
            }
        }
        return b;
    }
    
    bool isFileFormatSupported(string fileName, vector<string> * ext){
        bool b = false;
        if(NauMisc::isProperFilename(fileName)){
            string fileExt = fileName.substr((fileName.size()-3),3);
            for(int i=0;i<ext->size();i++){
                if(fileExt==ext->at(i)){
                    b=true;
                    i=ext->size()+2;
                }
            }
        }
        return b;
    }
    
    string insertEveryNChars(string origin, string what, int n){
        string s = origin;
        vector<int>pos;
        if(s.size()>n){
            int i=0;
            for(i=0;i<s.size();i+=n){
                if(i!=0)pos.push_back(i);
            }
            
            for(i=0;i<pos.size();i++){
                int pp = pos[i] + (i*what.size());
                s.insert(pp, what);
            }
        }   
        
        return s;
    }
    
    string extractSource(string pth){
        ofBuffer buf = ofBufferFromFile(pth);
        return buf.getText();
    }
    
    ofFileDialogResult customSaveDialog(string defaultName, string messageName, string defaultPath){
        ofFileDialogResult dr;
        
        NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
        NSSavePanel * saveDialog = [NSSavePanel savePanel];
        
        [saveDialog setMessage:[NSString stringWithUTF8String:messageName.c_str()]];
        
        if(!defaultPath.empty()){
            NSString * s = [NSString stringWithUTF8String:defaultPath.c_str()];
            s = [[s stringByExpandingTildeInPath] stringByResolvingSymlinksInPath];
            NSURL * defaultPathUrl = [NSURL fileURLWithPath:s];
            [saveDialog setDirectoryURL:defaultPathUrl];
        }
        
        [saveDialog setNameFieldStringValue:[NSString stringWithUTF8String:defaultName.c_str()]];
        
        NSInteger buttonClicked = [saveDialog runModal];
        
        NauMisc::getFocus();
        
        if(buttonClicked==NSFileHandlingPanelOKButton){
            dr.filePath = string([[[saveDialog URL] path] UTF8String]);
        }
        [pool drain];
        
        if( dr.filePath.length() > 0 ){
            dr.bSuccess = true;
            dr.fileName = ofFilePath::getFileName(dr.filePath);
        }
        
        return dr;
    }
    
    void getFocus(){
        NSWindow * appWindow = (NSWindow *)ofGetCocoaWindow();
        if(appWindow) {
            [appWindow makeKeyAndOrderFront:nil];
        }
    }
    //---
}