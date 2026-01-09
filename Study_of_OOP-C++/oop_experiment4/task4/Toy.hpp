#pragma once
#include<iostream>
#include<algorithm>
#include<string>

enum class Toys_name{Bear,Remote_car,Music_box,Frog,Unknown};

class Toy{
public:
    Toy(const std::string& name,const std::string &type,const std::string skill);
    virtual void play_skill(){}
    virtual ~Toy()=default;
    std::string get_name(){ return toy_name; }
    std::string get_type(){ return toy_type; }
    std::string get_skill(){ return toy_skill; }
protected:
    std::string toy_name;
    std::string toy_type;
    std::string toy_skill;
};

//会跳舞的小熊
class Bear:public Toy{
public:
    Bear(const std::string& name);
    void dance_a();
    void dance_b();
    void play_skill();
};

//遥控毛绒小车
class Remote_car:public Toy{
public:
    Remote_car(const std::string& name,int r);
    void move(bool dir);
    void play_skill();
private:
    int rate; //车速
    bool stop=true; //判断小车此时是否为静止状态
};

//毛绒音乐盒
class Music_box:public Toy{
public:
    Music_box(const std::string& name,int num);
    void play_skill();
private:
    int song_num; //歌曲数量
};

//会弹跳的青蛙
class Frog:public Toy{
public:
    Frog(const std::string& name);
    void jump(bool dir);    
    void play_skill();
private:
    bool stop=true;
};

//将string->enum
Toys_name str_to_enum(const std::string& s);

Toy* make_toys(const std::string &s);