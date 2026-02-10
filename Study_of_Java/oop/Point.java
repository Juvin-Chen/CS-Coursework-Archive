/**
 * 创建一个位置坐标的类，有构造方法，定义一个可以计算点与点之间的距离的方法
 */
public class Point {
    double x,y;

    Point(double x_,double y_){
        x=x_; //等价于this.x=x_;
        y=y_;
    }

    public double getdistance(Point a){
        return Math.sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));
    }

    public static void main(String[] args) {
        Point a=new Point(3.0,4.0); //如果直接写括号就会有一个默认的构造方法
        Point b=new Point(0.0,0.0);
        System.out.println(a.getdistance(b));
    }
}