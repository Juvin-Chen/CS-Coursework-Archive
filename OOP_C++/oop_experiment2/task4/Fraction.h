#pragma

#include<string>

class Fraction{
    friend class CollectionF;
public:
    static std::string doc;

private:
    int up,down;
public:
    Fraction(int up,int down=1);
    int get_up() const;
    int get_down() const;
    Fraction negative() const;  //用于求负
    Fraction operator-() const;
};

inline std::string Fraction::doc="Fraction类 v 0.01版.\n目前仅支持分数对象的构造、输出、加/减/乘/除运算.";





