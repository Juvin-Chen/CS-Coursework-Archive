// 备用代码1

#include <iostream>
#include <string>
#include <fstream>

//把一组数据写到磁盘上
void test1() {
    int n = 42;
    std::string s{"cosmos"};
    std::ofstream fout; //文件流的输出
    fout.open("d:/1.txt");
    if(!fout){ std::cerr<<"fail to open file to write"; return;}
    fout<<n<<" "<<s;
}

void test2(){
    //定义两个变量用来存放这个数据
    int n;
    std::string s;
    //从文件当中读数据,其实就是对应cin/cout
    std::ifstream fin;
    fin.open("d:/1.txt");
    if(!fin) { std::cerr<<"fail to open file to read"; return; }
    fin>>n>>s;
    std::cout<<n<<" "<<s;
}

int main() {
    test1();
    test2();
}