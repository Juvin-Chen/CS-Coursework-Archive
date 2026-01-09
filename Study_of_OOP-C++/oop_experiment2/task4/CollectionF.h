#pragma

//工具类
class CollectionF{
public:
    static Fraction fun(Fraction f); //化简
    static void output(Fraction f);
    static Fraction add(const Fraction &f1,const Fraction &f2);
    static Fraction sub(const Fraction &f1,const Fraction &f2);
    static Fraction mul(const Fraction &f1,const Fraction &f2);
    static Fraction div(const Fraction &f1,const Fraction &f2);
};

int gcd(int a,int b);