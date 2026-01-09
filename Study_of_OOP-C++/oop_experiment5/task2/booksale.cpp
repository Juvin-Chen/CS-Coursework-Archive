#include<iomanip>
#include<iostream>
#include<string>
#include"booksale.hpp"

//图书销售记录类 Booksales实现
BookSale::BookSale(const Book &rb_,double sales_price_,int sales_amount_): rb{rb_}, sales_price{sales_price_},sales_amount{sales_amount_} {}

int BookSale::get_amount() const{
    return sales_amount;
}

double BookSale::get_revenue() const{
    return sales_amount * sales_price;
}


std::ostream& operator<<(std::ostream &out,const BookSale&item){
    using std::left;
    using std::setw;

    out<<left;
    out << item.rb << '\n'
        << setw(15) << "售价:" << item.sales_price << '\n'
        << setw(15) << "销售数量:" << item.sales_amount << '\n'
        << setw(15) << "营收:" << item.get_revenue();
    return out;
}
