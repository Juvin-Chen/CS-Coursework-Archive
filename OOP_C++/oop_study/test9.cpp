// 备用代码2

#include <iostream>
#include <string>

void test1() {
    using namespace std;

    string s1;
    cout << "Enter s1:  \n";
    while(getline(cin >> ws, s1))
        cout << s1 << endl;
    
    //因为上面用的是循环读入，最后会有一个终止符，会对整个程序造成影响
    cin.clear();  //清除了错误标记位
    string s2;
    cout << "Enter s2: \n";
    cin >> s2;
    cout << s2;
}

void test2() {
    using namespace std;

    int n;
    cin >> n;
    cout << "n = " << n << '\n';

    //输完之后会留一个回车键在缓冲区里面
    
    cin.ignore(256,'\n'); //跳过缓冲区余下内容...

    string cmd;
    getline(cin, cmd); 
    cout << "cmd = " << cmd << '\n';
}

int main() {
    test2();
}