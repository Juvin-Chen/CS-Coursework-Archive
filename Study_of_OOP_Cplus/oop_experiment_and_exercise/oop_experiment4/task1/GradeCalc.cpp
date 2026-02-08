#include<algorithm>
#include<array>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>

#include"GradeCalc.hpp"

GradeCalc::GradeCalc(const std::string &cname):course_name(cname),is_dirty{true}{
    counts.fill(0);
    rates.fill(0);
}

void GradeCalc::input(int n){
    if(n<0){
        std::cerr<<"无效输入！人数不能为负数";
        std::exit(1);
    }
    grades.reserve(n);
    int grade;
    for(int i=0;i<n;){
        std::cin>>grade;
        if(grade<0||grade>100){
            std::cerr<<"无效输入！分数须在[0,100]\n";
            continue;
        }
        grades.push_back(grade);
        ++i;
    }
    is_dirty=true; //设置脏标记，成绩信息有变更
}

void GradeCalc::output() const{
    for(auto grade:grades) std::cout<<grade<<" ";
    std::cout<<std::endl;
}

void GradeCalc::sort(bool ascending){
    if(ascending) std::sort(grades.begin(),grades.end());
    else std::sort(grades.begin(),grades.end(),std::greater<int>());
} 

int GradeCalc::min() const{
    if(grades.empty()) return -1;
    auto it=std::min_element(grades.begin(),grades.end());
    return *it; 
} 

int GradeCalc::max() const{
    if(grades.empty()) return -1;
    auto it=std::max_element(grades.begin(),grades.end());
    return *it;
}

double GradeCalc::average() const{
    if(grades.empty()) return 0.0;
    double avg=std::accumulate(grades.begin(),grades.end(),0.0)/grades.size();
    return avg;
}

void GradeCalc::info(){
    if(is_dirty) compute();
    std::cout<<"课程名称:\t"<<course_name<<std::endl;
    std::cout<<"平均分:\t"<<std::fixed<<std::setprecision(2)<<average()<<std::endl;
    std::cout<<"最高分:\t"<<max()<<std::endl;
    std::cout<<"最低分:\t"<<min()<<std::endl;
    const std::array<std::string,5> grade_range{"[0, 60) ","[60, 70)","[70, 80)","[80, 90)","[90, 100]"};
    for(int i=grade_range.size()-1;i>=0;i--){
        std::cout<<grade_range[i]<<"\t:"<<counts[i]<<"人\t"<<std::fixed<<std::setprecision(2)<<rates[i]*100<<"%\n";
    }
}

void GradeCalc::compute(){  
    if(grades.empty()) return;
    counts.fill(0);
    rates.fill(0.0);
    //统计各分数段人数
    for(auto grade:grades){
        if(grade<60){
            ++counts[0];
        }else if(grade<70){
            ++counts[1];
        }else if(grade<80){
            ++counts[2];
        }else if(grade<90){
            ++counts[3];
        }else{
            ++counts[4];
        }
    }
    for(int i=0;i<rates.size();++i)
        rates[i]=counts[i]*1.0/grades.size();
    is_dirty=false;  //更新脏标记
}
