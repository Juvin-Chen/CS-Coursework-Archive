#include<algorithm>
#include<iostream>
#include<stdexcept>
#include<vector>
#include"contestant.hpp"
#include"utils.hpp"

const std::string in_file="./data_bad.txt";
const std::string out_file="./ans.txt";

void app(){
    std::vector<Contestant> contestants;
    try{
        contestants=load(in_file);
        std::sort(contestants.begin(),contestants.end(),cmp_by_solve);
        print(contestants);
        save(out_file,contestants);
    }catch(const std::exception& e){
        std::cerr<<e.what()<<'\n';
        return;
    }
}

int main(){
    app();
}