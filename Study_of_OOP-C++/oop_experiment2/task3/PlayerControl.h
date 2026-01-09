#pragma
#include<string>

enum class ControlType{Play,Pause,Next,Prev,Stop,Unknown};

class PlayerControl{
private:
    static int total_cnt;
public:
    static int get_cnt();

public:
    PlayerControl();
    ControlType parse(const std::string& control_str); //实现std::string向ControlType转换
    void execute(ControlType cmd) const; //执行控制操作（以打印输出模拟）
};

