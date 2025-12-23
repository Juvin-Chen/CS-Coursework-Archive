#include<iostream>
#include<string>
int main(){
    int num;
    std::cin>>num;
    std::string s=""; 
    while(num){
        char c=num%2+'0';
        s=c+s;
        num/=2;
    }
    std::cout<<s;
    return 0;
}