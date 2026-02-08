#include<iomanip>
#include<iostream>
#include<string>
#include"book.hpp"

//图书描述类信息Book的实现
Book::Book(const std::string &name_,const std::string &author_,const std::string &translator_,const std::string &isbn_,double price_):name(name_),author(author_),translator(translator_),isbn{isbn_},price{price_}{}

//运算符<<重载实现
std::ostream& operator<<(std::ostream &out,const Book &book){
    using std::left;
    using std::setw;

    out<<left;
    out << setw(15) << "书名:" << book.name << '\n'
        << setw(15) << "作者:" << book.author << '\n'
        << setw(15) << "译者:" << book.translator << '\n'
        << setw(15) << "ISBN:" << book.isbn << '\n'
        << setw(15) << "定价:" << book.price;

    return out;
}

