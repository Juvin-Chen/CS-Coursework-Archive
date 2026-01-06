#include <algorithm>
#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include "GradeCalc.hpp"

GradeCalc::GradeCalc(const std::string &cname): course_name{cname}, is_dirty{true}{
    counts.fill(0);
    rates.fill(0);
}

void GradeCalc::input(int n){
    if(n<0){
        std::cerr<<"无效输入! 人数不能为负数\n";
        return;
    }
    this->reserve(n);
    int grade;
    for(int i=0;i<n;){
        std::cin >> grade;
        if(grade < 0 || grade > 100) {
            std::cerr << "无效输入! 分数须在[0,100]\n";
            continue;
        }
        this->push_back(grade);
        ++i;
    }
    is_dirty=true;
}

void GradeCalc::output() const{
    for(auto g:*this)
        std::cout<<g<<' ';
    std::cout<<std::endl;
}

void GradeCalc::sort(bool ascending){
    if(ascending) std::sort(this->begin(),this->end());
    else std::sort(this->begin(),this->end(),std::greater<int>());
}

int GradeCalc::min() const{
    if(this->empty())
        return -1;
    return *std::min_element(this->begin(), this->end());
}

int GradeCalc::max() const{
    if(this->empty())
        return -1;
    return *std::max_element(this->begin(), this->end());
}

double GradeCalc::average() const {
    if(this->empty())
        return 0.0;
    double avg = std::accumulate(this->begin(), this->end(), 0.0) / this->size();
    return avg;
}
void GradeCalc::info() {
    if(is_dirty) compute();
    std::cout << "课程名称:\t" << course_name << std::endl;
    std::cout << "平均分:\t" << std::fixed << std::setprecision(2) << average() <<
    std::endl;
    std::cout << "最高分:\t" << max() << std::endl;
    std::cout << "最低分:\t" << min() << std::endl;
    const std::array<std::string, 5> grade_range{"[0, 60) ",
    "[60, 70)",
    "[70, 80)",
    "[80, 90)",
    "[90, 100]"};
    for(int i = grade_range.size()-1; i >= 0; --i)
        std::cout << grade_range[i] << "\t: " << counts[i] << "人\t"<< std::fixed << std::setprecision(2) << rates[i]*100 << "%\n";
}

void GradeCalc::compute() {
    if(this->empty())
        return;
    counts.fill(0);
    rates.fill(0);
    // 统计各分数段人数
    for(int grade: *this) {
        if(grade < 60)
            ++counts[0]; // [0, 60)
        else if (grade < 70)
            ++counts[1]; // [60, 70)
        else if (grade < 80)
            ++counts[2]; // [70, 80)
        else if (grade < 90)
            ++counts[3]; // [80, 90)
        else
            ++counts[4]; // [90, 100]
    }
    // 统计各分数段比例
    for(int i = 0; i < rates.size(); ++i)
        rates[i] = counts[i] * 1.0 / this->size();
    is_dirty = false;
}