/*
任务描述： 假设有一个字符串 string data = "User:Tom_ID:1001_Level:5";。 
你会发现它不是用空格分隔的，而是用下划线 _。 请你编写代码，把下划线全部替换成空格，然后用 istringstream 把名字、ID 和等级提取出来并打印。
*/
#include<string>
#include<iostream>
#include<sstream>

using namespace std;
int main(){
    string str= "User:Tom_ID:1001_Level:5";
    for(char &c:str){
        if(c='_') c=' ';
    }
    string label1, name, label2, label3;
    int id, level;
    // 请在这里补充代码：使用 >> 提取数据
    istringstream iss(str);
    iss>>label1;//......
    // 注意：User:Tom 这种连在一起的会被当做一个字符串，
    // 所以你可能需要一点技巧，或者简单的提取字符串即可。
    
    // 简化版任务：
    // 假设数据已经是 "Tom 1001 5"
    string cleanData = "Tom 1001 5";
    istringstream iss2(cleanData);
    
    iss2 >> name >> id >> level;

    cout << "名字: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "等级: " << level << endl;
    return 0;
}

//结合getline用法好！
/*
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
    
    修改前：
    while(is>>seq>>t) v.push_back(t); //这里is>>会根据读到的内容和读取变量
    
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
*/