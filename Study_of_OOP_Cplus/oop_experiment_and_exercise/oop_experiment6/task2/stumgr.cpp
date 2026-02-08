#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<sstream>
#include"student.hpp"
#include"stumgr.hpp"
void StuMgr::load(const std::string& file){
    std::ifstream is(file);
    if(!is){
        throw std::runtime_error("fail to open"+file);
    }
    std::string str;
    std::getline(is,str); //先读取第一行标题
    /*
    Student s;
    while(is>>s) students.push_back(s);
    */
    /*
    上面注释部分是未进行数据校验的写法，下面是更安全的做法
    
    题目：如希望加载文件时提供异常处理，包括对字段缺失、成绩值不在有效范围内内做校验，使得代码更健壮：有字段缺失
    或异常值不会参与计算，如何完善代码，使其预期效果如下：报告错误行信息，同时并不影响其它有效数据计算。
    */
    std::string line;
    int num=1; //记录此时所在的行数
    while(std::getline(is,line)){
        num++;
        if(line.empty()) continue;
        std::istringstream iss(line);
        int id,grade;
        std::string name,major;
        if(!(iss>>id>>name>>major>>grade)){
            std::cout<<"[Warning] line"<<num<<" format error,skipped:"<<line+"\n";
            continue;
        }else if(grade<0||grade>100){
            std::cout<<"[Warning] line"<<num<<" grade invalid,skipped:"<<line+"\n";
            continue;
        }
        Student s;
        std::istringstream new_iss(line);
        new_iss>>s;
        students.push_back(s);
    }
}

void StuMgr::sort(){
    std::sort(students.begin(),students.end(),[](const Student& s1,const Student& s2){
        return s1.get_major()!=s2.get_major()?s1.get_major()<s2.get_major():s1.get_grade()>s2.get_grade();
    });
}

void StuMgr::print() const{ //打印到屏幕
    write(std::cout);
}
 
void StuMgr::save(const std::string& file) const{ //保存到文件
    std::ofstream os(file);
    if(!os){
        throw std::runtime_error("fail to open"+file);
    }
    write(os);
}

void StuMgr::write(std::ostream &os) const{ //把数据写到任意输出流
    for(auto s:students){
        os<<s<<"\n";
    }
}