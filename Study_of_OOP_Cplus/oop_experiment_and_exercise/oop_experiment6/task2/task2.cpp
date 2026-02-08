#include<iostream>
#include<limits>
#include<string>
#include"stumgr.hpp"

const std::string in_file="./data_bad.txt";
const std::string out_file="./ans.txt";

void menu(){
    //这里出现的多引号连续放置编译器会自动拼接"+"为一个字符串，所以这里并没有加<<
    std::cout<<"\n**********简易应用**********\n"
                "1. 加载文件\n"
                "2. 排序\n"
                "3. 打印到屏幕\n"
                "4. 保存到文件\n"
                "5. 退出\n"
                "请选择：";
}

void app(){
    StuMgr mgr;
    while(true){
        menu();
        int choice;
        std::cin>>choice;
        try{
            switch(choice){
                case 1:mgr.load(in_file);
                    std::cout<<"加载成功\n"; break;
                case 2:mgr.sort();
                    std::cout<<"排序已完成\n"; break;
                case 3:mgr.print();
                    std::cout << "打印已完成\n"; break;
                case 4:mgr.save(out_file);
                    std::cout << "导出成功\n"; break;
                case 5: return;
                default: std::cout<<"不合法输入\n";
            }
        }catch(const std::exception& e){
            std::cout<<"Error:"<<e.what()<<'\n';
        }
    }
}

int main(){
    app();
}