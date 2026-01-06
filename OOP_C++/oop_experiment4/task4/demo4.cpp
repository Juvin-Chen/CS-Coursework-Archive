#include<iostream>
#include"Toy.hpp"
#include"ToyFactory.hpp"

int main(){
    ToyFactory t;
    t.add("Bear");
    t.add("Music_box");
    t.add("Remote_car"); 
    t.add("Frog");
    t.info();
}