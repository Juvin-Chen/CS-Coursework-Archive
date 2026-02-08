//多态2
/*
下面的实例中，我们通过多态实现了一个通用的 Shape 基类和两个派生类 Rectangle 和 Triangle。
通过基类指针调用不同的派生类方法，展示了多态的动态绑定特性。
*/

#include<iostream>
using namespace std;

class Shape{
protected:
    int width,height;
public:
    Shape(int a=0,int b=0):width(a),height(b){}
    virtual int area(){
        cout<<"Shape S:"<<endl;
        return 0;
    }
};

class Rectangle:public Shape{
public:
    //构造函数，使用基类构造函数初始化width height
    Rectangle(int a=0,int b=0):Shape(a,b){}
    //重写area（）
    int area() override{
        cout<<"Rectangle class area:"<<endl;
        return width*height;
    }
};

// 派生类 Triangle，表示三角形
class Triangle : public Shape {
   public:
      // 构造函数，使用基类构造函数初始化 width 和 height
      Triangle(int a = 0, int b = 0) : Shape(a, b) { }
 
      // 重写 area 函数，计算三角形面积
      int area() override { 
         cout << "Triangle class area: " << endl;
         return (width * height / 2); 
      }
};

int main(){
    Shape *shape;
    Rectangle rec(10,7);
    Triangle tri(10,5);
    shape=&rec;
    cout<<"Rectangle Area:"<<shape->area()<<endl;
    shape=&tri;
    cout<<"Triangle Area:"<<shape->area()<<endl;
}