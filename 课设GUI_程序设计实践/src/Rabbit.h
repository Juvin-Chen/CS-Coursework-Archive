#pragma once
#include <cmath>
#include "graphics.h"

struct Vec {
    float x, y;
    Vec(float f1, float f2) :x(f1), y(f2) {}
    Vec abc() {
        float len = sqrt(x * x + y * y);
        if (len > 0) {
            x /= len; y /= len;
        }
        return *this;
    }
};

class Rabbit {
public:
    float x, y;
    int drinks = 0;
    bool alive = true;
    Vec dir;

    Rabbit(float f1, float f2) : x(f1), y(f2), dir(1, 0) {}

    int radius() {
        return (drinks >= 20 ? 50 / 2 : 50 / 3);
    }
    int speed() {
        return (drinks >= 20 ? 8 : 6);
    }
    bool canUseSkill() {
        return drinks >= 30;
    }
};

inline void drawRabbit(Rabbit& r) {
    setfillcolor(RGB(255, 255, 255));
    fillcircle((int)r.x, (int)r.y, r.radius());
    setfillcolor(RGB(255, 200, 200));
    int erx = r.radius() / 2, ery = r.radius();
    fillellipse((int)r.x - erx, (int)r.y - r.radius() - ery / 2, (int)r.x - erx / 2, (int)r.y - r.radius() + ery / 2);
    fillellipse((int)r.x + erx / 2, (int)r.y - r.radius() - ery / 2, (int)r.x + erx, (int)r.y - r.radius() + ery / 2);
}
