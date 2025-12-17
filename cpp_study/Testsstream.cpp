/*
任务描述： 假设有一个字符串 string data = "User:Tom_ID:1001_Level:5";。 
你会发现它不是用空格分隔的，而是用下划线 _。 请你编写代码，把下划线全部替换成空格，然后用 istringstream 把名字、ID 和等级提取出来并打印。
*/
#include<string>
#include<iostream>
#include<sstream>
int main(){
    std::string str= "User:Tom_ID:1001_Level:5";
    for(char &c:str){
        if(c='_') c=' ';
    }
    std::string name;
    std::string ID;
    int Level;
    std::istringstream is(str);
 
    return 0;
}