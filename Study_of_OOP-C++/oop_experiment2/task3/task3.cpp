#include"PlayerControl.h"
#include<iostream>

void test(){
    PlayerControl controller;
    std::string control_str;
    std::cout<<"Enter Control:(play/pause/next/prev/stop/quit):\n";

    while(std::cin >> control_str) {
        if(control_str == "quit") break;
        ControlType cmd = controller.parse(control_str);
        controller.execute(cmd);
        std::cout << "Current Player control: " << PlayerControl::get_cnt() << "\n\n";
    }
}

int main(){ test(); }
