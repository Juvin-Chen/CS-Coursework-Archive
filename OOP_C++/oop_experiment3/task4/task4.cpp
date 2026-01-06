#include <iostream>
#include <cstdlib>
#include "matrix.hpp"

void test1();
void test2();
void output(const Matrix &m, int row_index);

int main() {
    std::cout << "测试1: \n";
    test1();

    std::cout << "\n测试2: \n";
    test2();
}

void test1() {
    double x[1000] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n, m;
    std::cout << "Enter n and m: ";
    std::cin >> n >> m;

    Matrix m1(n, m);    // 创建矩阵对象m1, 大小n×m
    m1.set(x, n*m);     // 用一维数组x的值按行为矩阵m1赋值

    Matrix m2(m, n);    // 创建矩阵对象m2, 大小m×n
    m2.set(x, m*n);     // 用一维数组x的值按行为矩阵m1赋值

    Matrix m3(n);       // 创建一个n×n方阵对象
    m3.set(x, n*n);     // 用一维数组x的值按行为矩阵m3赋值

    std::cout << "矩阵对象m1: \n";   m1.print();
    std::cout << "矩阵对象m2: \n";   m2.print();
    std::cout << "矩阵对象m3: \n";   m3.print();
}

void test2() {
    Matrix m1(2, 3, -1);
    const Matrix m2(m1);
    
    std::cout << "矩阵对象m1: \n";   m1.print();
    std::cout << "矩阵对象m2: \n";   m2.print();

    m1.clear();
    m1.at(0, 0) = 1;

    std::cout << "m1更新后: \n";
    std::cout << "矩阵对象m1第0行 "; output(m1, 0);
    std::cout << "矩阵对象m2第0行: "; output(m2, 0);
}

// 输出矩阵对象row_index行所有元素
void output(const Matrix &m, int row_index) {
    if(row_index < 0 || row_index >= m.rows()) {
        std::cerr << "IndexError: row index out of range\n";
        exit(1);
    }

    std::cout << m.at(row_index, 0);
    for(int j = 1; j < m.cols(); ++j)
        std::cout << ", " << m.at(row_index, j);
    std::cout << '\n';
}