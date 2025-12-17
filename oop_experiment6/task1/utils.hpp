#pragma once

#include<fstream>
#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
#include"contestant.hpp"
#include<sstream> //加一个功能，见task1.txt的最后一问

//ACM排序规则：先按解题数降序，再按罚时升序
inline bool cmp_by_solve(const Contestant& a,const Contestant& b){
    return a.solved!=b.solved?a.solved>b.solved:a.penalty<b.penalty;
}

//将结果写至任意输出流
inline void write(std::ostream& os,const std::vector<Contestant>& v){
    for(const auto& x:v)
        os<<x<<"\n";
}

//将结果打印到屏幕,其实就相当于调用了write函数只不过函数参数传递是cout就变成了将结果打印到屏幕上了
inline void print(const std::vector<Contestant>& v){
    write(std::cout,v);
}

//将结果保存到文件
inline void save(const std::string& filename,const std::vector<Contestant>& v){
    std::ofstream os(filename);
    if(!os){
        throw std::runtime_error("fail to open"+filename);
    }
    write(os,v);
}

//从文件读取信息（跳过标题行）
inline std::vector<Contestant> load(const std::string& filename){
    std::ifstream is(filename); 
    if(!is){
        throw std::runtime_error("fail to open"+filename);
    }
    std::string line;
    std::getline(is,line); //跳过标题，这里getline的第一个参数只是需要一个输入流对象

    std::vector<Contestant> v;
    Contestant t;
    int seq;
    /*
    修改前：
    while(is>>seq>>t) v.push_back(t); //这里is>>会根据读到的内容和读取变量
    */
    //修改后对每行数据进行了安全检查
    int num=1;
    while(std::getline(is,line)){
        if(line.empty()){
            std::cerr<<"ERROR! 行号为:"<<num<<"\n";
            continue;
        }
        std::istringstream iss(line);
        if(iss>>seq>>t) v.push_back(t);
        else std::cerr<<"ERROR! 行号为:"<<num<<"\n";
        num++;
    }
    return v; 
}