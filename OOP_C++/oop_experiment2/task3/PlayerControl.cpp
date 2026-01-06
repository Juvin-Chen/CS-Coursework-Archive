#include"PlayerControl.h"
#include<string>
#include<iostream>
#include<algorithm>

int PlayerControl::total_cnt=0;

PlayerControl::PlayerControl(){};

ControlType PlayerControl::parse(const std::string &control_str){
    std::string str="";
    total_cnt++;
    str.resize(control_str.size());  //transform（）需要给str提前预留足够空间  / string str(control_str.size(),' ')
    std::transform(control_str.begin(),control_str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
    if(str=="play"){
        return ControlType::Play;
    }else if(str=="pause"){
        return ControlType::Pause;
    }else if(str == "next"){
        return ControlType::Next;
    }else if(str == "prev"){
        return ControlType::Prev;
    }else if(str == "stop"){
        return ControlType::Stop;
    }else{
        return ControlType::Unknown;
    }
}

void PlayerControl::execute(ControlType cmd) const{
    switch (cmd) {
        case ControlType::Play: std::cout << "🎵 [play] Playing music...\n"; break;
        case ControlType::Pause: std::cout << "[Pause] Music paused\n"; break;
        case ControlType::Next: std::cout << "⏭️ [Next] Skipping to next track\n"; break;
        case ControlType::Prev: std::cout << "⏮️ [Prev] Back to previous track\n"; break;
        case ControlType::Stop: std::cout << "⏹️ [Stop] Music stopped\n"; break;
        default: std::cout << "[Error] unknown control\n"; break;
    }
}

int PlayerControl::get_cnt(){ return total_cnt; }

