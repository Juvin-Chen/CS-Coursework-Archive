#pragma once

#include<string>

class Book{
public:
    Book(const std::string &name_,const std::string &author_,const std::string &translator_,const std::string &isbn_,double price);
    
    friend std::ostream& operator<<(std::ostream &out,const Book &book); 

private:
    std::string name; //book name
    std::string author; 
    std::string translator; //译者
    std::string isbn; //isbn号
    double price; //定价
};



