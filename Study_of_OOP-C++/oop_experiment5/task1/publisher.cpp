#include<iostream>
#include<string>
#include"publisher.hpp"

//Publisher
Publisher::Publisher(const std::string &name_):name{name_}{}

//Book
Book::Book(const std::string &name_,const std::string &author_):Publisher{name_},author{author_}{}
void Book::publish() const{
    std::cout<<"Publishing book <<"<<name<<">> by"<<author<<"\n";
}
void Book::use() const{
    std::cout<<"Reading book <<"<<name<<">> by"<<author<<"\n";
}

//Film
Film::Film(const std::string &name_,const std::string &director_):Publisher(name_),director{director_}{}
void Film::publish() const{
    std::cout<<"Publishing film <"<<name<<"> directed by"<<director<<'\n';
}
void Film::use() const{
    std::cout<<"Watching film <"<<name<<"> directed by"<<director<<'\n';
}

//Music
Music::Music(const std::string &name_, const std::string &artist_):Publisher{name_},artist{artist_}{}
void Music::publish() const{
    std::cout << "Publishing music <" << name << "> by " << artist << '\n';
}
void Music::use() const{
    std::cout << "Listening to music <" << name << "> by " << artist << '\n';
}

