//
//  NauTimer.cpp
//
//  Created by enrico<nausea>viola on 3/13/14.
//
//

#include "NauTimer.h"

NauTimer::NauTimer(){
    someoneListening=false;
}

void NauTimer::setup(float _tick, int _rounds){
    tick=_tick;
    rounds=_rounds;
    reset();
}

void NauTimer::reset(){
    bRunning=false;
    curRound=0;
}

void NauTimer::start(){
    if(!bRunning){
        bRunning=true;
        startTime = ofGetElapsedTimef();
        endTime = startTime + tick;
        cout << "Timer started" << endl;
    }
}

void NauTimer::stop(){
    if(bRunning){
        bRunning=false;
        cout << "Timer stopped" << endl;
    }
}

void NauTimer::update(){
    if(bRunning){
        float curTime = ofGetElapsedTimef();
        
        if(curTime>=endTime){
            curRound++;
            endTime = endTime + tick;
            onTick();
        }
        
        if(curRound>=rounds){
            stop();
        }
    }
}

void NauTimer::onTick(){
    ofNotifyEvent(tickEvent,curRound);
    cout << "Timer tick" << endl;
}