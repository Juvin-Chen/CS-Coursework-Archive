#pragma once 
#include<string>
#include<vector>
#include"student.hpp"

class StuMgr{
public:
    void load(const std::string& file); //加载数据文件（空格分隔）
    void sort(); //排序：按专业字典序升序，同专业分数降序
    void print() const; //打印到屏幕
    void save(const std::string &file ) const; //保存到文件

private:
    void write(std::ostream &os) const;  //把数据写到任意输出流

    std::vector<Student> students;
};

