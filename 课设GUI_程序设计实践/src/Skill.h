#pragma once
#include <cmath>
#include "graphics.h"
#include "Rabbit.h"

struct Skill {
    int x1, y1, x2, y2;
    int timer = 15;
    bool active = false;
};

inline void trigger(Rabbit& rabbit, Skill& skill, int vkKey) {
    if (rabbit.canUseSkill() && (GetAsyncKeyState(vkKey) & 0x8000)) {
        skill.active = true;
        skill.timer = 15;
        skill.x1 = (int)rabbit.x;
        skill.y1 = (int)rabbit.y;
        skill.x2 = (int)(rabbit.x + rabbit.dir.x * 900);
        skill.y2 = (int)(rabbit.y + rabbit.dir.y * 900);
    }
}

inline void skilleff(const Rabbit& a, Rabbit& b, Skill& skill) {
    if (!skill.active) return;
    setlinecolor(RGB(255, 255, 0));
    setlinestyle(PS_SOLID, 2);
    line(skill.x1, skill.y1, skill.x2, skill.y2);
    float A = skill.y2 - skill.y1;  //AX+BY+C=0
    float B = skill.x1 - skill.x2;
    float C = skill.x2 * skill.y1 - skill.x1 * skill.y2;
    float d = fabs(A * b.x + B * b.y + C) / sqrt(A * A + B * B);
    float judge = (b.x - a.x) * a.dir.x + (b.y - a.y) * a.dir.y;
    if (d < b.radius() && judge>0) b.alive = false;
    if (--skill.timer <= 0) skill.active = false;
}