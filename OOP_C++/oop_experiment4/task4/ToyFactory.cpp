#include<vector>

#include"ToyFactory.hpp"
#include"Toy.hpp"

void ToyFactory::add(const std::string &type){
    Toy *t=make_toys(type);
    if(t) toys.push_back(t);
}

void ToyFactory::play() const{
    for(Toy *t:toys){
        std::cout<<"玩具名称:"<<t->get_name()<<"  玩具类型:"<<t->get_type()<<"  玩具技能:"<<t->get_skill();
        std::cout<<"\nshow skill: \n";
        t->play_skill();
        std::cout<<"\n";
    }
}

void ToyFactory::info() const{
    std::cout<<"玩具工厂生产的四种玩具极其特点："<<"\n";
    for(int i=0;i<toy_categories.size();i++){
        std::cout<<i+1<<" "<<toy_categories[i].first<<":"<<toy_categories[i].second<<std::endl;
    }
    std::cout<<"\n";
    std::cout<<"展示玩具技能："<<"\n";
    play();
}

ToyFactory::~ToyFactory(){
    for(auto t:toys) delete t;
}