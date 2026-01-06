#pragma once
#include<string>
#include<vector>
#include<utility>

#include"Toy.hpp"

class ToyFactory{
public:
    void info() const;
    void play() const;
    void add(const std::string &type);
    ~ToyFactory();

private:
    std::vector<Toy*> toys;
    std::vector<std::pair<std::string, std::string>> toy_categories={
        {"动物类玩具", "模拟动物形态/行为"},
        {"发声类玩具", "能播放音乐/模拟声音"},
        {"动作类玩具", "能完成特定动作"},
        {"遥控类玩具", "远程操控移动/动作"}
    }; //玩具工厂所包含的玩具类型以及对应的功能
};
