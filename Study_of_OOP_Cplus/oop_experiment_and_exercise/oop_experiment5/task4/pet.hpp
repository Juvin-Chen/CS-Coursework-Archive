#include<iostream>
#include<string>

//抽象类MachinePet
class MachinePet{
public:
    MachinePet(const std::string &name):nickname{name}{};
    const std::string& get_nickname() const{ return nickname; };
    virtual std::string talk() const=0;
    virtual ~MachinePet()=default;
private:
    std::string nickname; //昵称
};

class PetCat:public MachinePet{
public:
    PetCat(const std::string& name):MachinePet(name){}
    std::string  talk() const override{
        return "miao wu~";
    }
};

class PetDog:public MachinePet{
public:
    PetDog(const std::string& name):MachinePet(name){}
    std::string talk() const override{
        return "wang wang~";
    } 
};

