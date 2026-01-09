#pragma once

#include<string>
#include"book.hpp"

//图书销售基类BookSales：声明
class BookSale{
public:
    BookSale(const Book &rb_,double sales_price,int sales_amount);
    int get_amount() const; //返回销售数量
    double get_revenue() const; //返回营收

    friend std::ostream& operator<<(std::ostream &out,const BookSale &item); 

private:
    Book rb; 
    double sales_price; //售价  
    int sales_amount; //销售数量
};



