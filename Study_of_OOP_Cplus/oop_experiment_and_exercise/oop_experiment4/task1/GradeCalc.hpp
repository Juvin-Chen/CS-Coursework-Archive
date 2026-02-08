#pragma once

#include<vector>
#include<array>
#include<string>

class GradeCalc{
public:
    GradeCalc(const std::string &cname);
    void input(int n); // 录入n个成绩
    void output() const; // 输出成绩
    void sort(bool ascending = false); // 排序 (默认降序)
    int min() const; // 返回最低分（如成绩未录入，返回-1)
    int max() const; // 返回最高分 （如成绩未录入，返回-1)
    double average() const; // 返回平均分 （如成绩未录入，返回0.0)
    void info(); // 输出课程成绩信息

private:
    void compute();  //成绩统计

private:
    std::string course_name; // 课程名
    std::vector<int> grades; // 课程成绩
    std::array<int, 5> counts; // 保存各分数段人数（[0, 60), [60, 70), [70, 80), [80,90), [90, 100]
    std::array<double, 5> rates; // 保存各分数段人数占比
    bool is_dirty; // 脏标记，记录是否成绩信息有变更
};
