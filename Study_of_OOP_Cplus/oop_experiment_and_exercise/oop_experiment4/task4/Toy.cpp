#include<iostream>
#include<string>
#include<algorithm>

#include"Toy.hpp"

Toy::Toy(const std::string& name,const std::string &type,const std::string skill):toy_name(name),toy_type(type),toy_skill(skill){}
Bear::Bear(const std::string& name):Toy(name,"动物类玩具","跳舞"){}
void Bear::dance_a(){ std::cout<<"小熊开始跳舞蹈A...\n"; }
void Bear::dance_b(){ std::cout<<"小熊开始跳舞蹈B...\n"; }
void Bear::play_skill(){
    dance_a();
    dance_b();
}

Remote_car::Remote_car(const std::string& name,int r):Toy(name,"遥控类玩具","移动"),rate{r}{}
void Remote_car::move(bool dir){ //dir为true时前进，反之后退
    if(stop) return;
    if(dir) std::cout<<"小车正在以"<<rate<<"m/s"<<"的速度向前移动\n";
    else std::cout<<"小车正在以"<<rate<<"m/s"<<"的速度向后移动\n";
}
void Remote_car::play_skill(){
    stop=false;
    move(true);
    move(false);
    stop=false;
    std::cout<<"小车停止移动...\n";
}

Music_box::Music_box(const std::string& name,int num):Toy(name,"发声类玩具","放音乐"),song_num{num}{}
void Music_box::play_skill(){
    std::cout<<"音乐盒共有"<<song_num<<"首歌，开始播放歌曲...\n";
    for(int i=1;i<=song_num;i++){
        std::cout<<"正在播放歌曲"<<i<<"\n";
    }
}

Frog::Frog(const std::string& name):Toy(name,"动作类玩具","弹跳"){}
void Frog::jump(bool dir){ //dir为true向前跳，反之向后跳
    if(stop) return;
    if(dir) std::cout<<"小青蛙向前跳\n";
    else std::cout<<"小青蛙向后跳\n";
}
void Frog::play_skill(){
    stop=false;
    jump(true);
    jump(false);
    stop=false;
    std::cout<<"小青蛙停止跳跃...";
}

//将string->enum
Toys_name str_to_enum(const std::string& s){   
    std::string t=s;
    std::transform(s.begin(),s.end(),t.begin(),[](unsigned char c){ return std::tolower(c); });
    if(t=="bear") return Toys_name::Bear;
    if(t=="music_box") return Toys_name::Music_box;
    if(t=="frog") return Toys_name::Frog;
    if(t=="remote_car") return Toys_name::Remote_car;
    return Toys_name::Unknown; //缺省返回
}

Toy* make_toys(const std::string& s){
    switch(str_to_enum(s)){
        case Toys_name::Bear: return new Bear("毛绒小熊"); 
        case Toys_name::Remote_car: return new Remote_car("毛绒遥控小车", 5); 
        case Toys_name::Music_box: return new Music_box("毛绒音乐盒", 3); 
        case Toys_name::Frog: return new Frog("毛绒小青蛙"); 
        case Toys_name::Unknown:
        default:
            std::cout << "错误：无法根据枚举值创建玩具。" << std::endl;
            return nullptr;
    }
}
