#pragma

#include<string>

class T{
public:
    T(int x=0,int y=0);
    T(const T &t);
    T(T &&t);
    ~T();

    void adjust(int ratio);  //按系数成倍地调整数据
    void display() const;  //以（m1,m2）形式调整数据

private:
    int m1,m2;  //坐标

//类属性及方法
public:
    static int get_cnt();  //显示当前类T对象总数
public:
    static const std::string doc;  //类T的描述信息
    static const int max_cnt;  //类T对象上限

private:
    static int cnt;  //显示T类对象总数
    
    friend void func(); //需要两种声明，这里是friend访问权限的声明
};

//这个是函数本身的声明
void func();

