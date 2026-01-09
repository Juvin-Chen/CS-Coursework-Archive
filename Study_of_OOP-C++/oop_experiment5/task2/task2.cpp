#include "booksale.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//按图书销售数额比较
bool compare_by_amount(const BookSale &x1, const BookSale &x2) {
    return x1.get_amount() > x2.get_amount();
}
void test() {
    using namespace std;
    vector<BookSale> sales_lst; // 存放图书销售记录
    int books_number;
    cout << "录入图书数量: ";
    cin >> books_number;
    cout << "录入图书销售记录" << endl;
    for(int i = 0; i < books_number; ++i) {
        string name, author, translator, isbn;
        float price;
        cout << string(20, '-') << "第" << i+1 << "本图书信息录入" << string(20, '-') <<endl;
        cout << "录入书名: "; cin >> name;
        cout << "录入作者: "; cin >> author;
        cout << "录入译者: "; cin >> translator;
        cout << "录入isbn: "; cin >> isbn;
        cout << "录入定价: "; cin >> price;
        Book book(name, author, translator, isbn, price);
        float sales_price;
        int sales_amount;
        cout << "录入售价: "; cin >> sales_price;
        cout << "录入销售数量: "; cin >> sales_amount;
        BookSale record(book, sales_price, sales_amount);
        sales_lst.push_back(record);
    }
    // 按销售册数排序
    sort(sales_lst.begin(), sales_lst.end(), compare_by_amount);
    // 按销售册数降序输出图书销售信息
    cout << string(20, '=') << "图书销售统计" << string(20, '=') << endl;
    for(auto &t: sales_lst) {
        cout << t << endl;
        cout << string(40, '-') << endl;
    }
}
int main() {
    test();
}