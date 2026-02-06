#include<graphics.h>    
#include<conio.h>       
#include<windows.h>     
#include<vector>        
#include<cmath>        
#include<ctime>         
#include<fstream>
#include"Rabbit.h"
#include"Skill.h"
using namespace std;

constexpr int WIDTH = 900, HEIGHT = 900;
constexpr int drinks_sum = 120;
constexpr int R = 50;
constexpr int skill_time = 15;

struct L {   //location
    int x, y;
    L(int a, int b) :x(a), y(b) {}
};

IMAGE imgBackground, imgWin1, imgWin2;
void loadImages() {
    loadimage(&imgBackground, _T("../img/background.png"), WIDTH, HEIGHT);
    loadimage(&imgWin1, _T("../img/1win.png"), WIDTH, HEIGHT);
    loadimage(&imgWin2, _T("../img/2win.png"), WIDTH, HEIGHT);
}

void move(Vec& dir, Rabbit& r) {
    if (dir.x || dir.y) {
        dir.abc();
        r.x += dir.x * r.speed();
        r.y += dir.y * r.speed();
        r.dir = dir;
    }
}

int main() {
    srand((unsigned)time(NULL));
    initgraph(WIDTH, HEIGHT);
    loadImages();
    BeginBatchDraw();

    auto fun = [](int x, int y) {
        return x + rand() % (y - x + 1);
        };
    vector<L> drinks;
    for (int i = 0;i < drinks_sum;i++)
        drinks.push_back({ fun(20,WIDTH - 20), fun(20, HEIGHT - 20) });

    Rabbit r1(100, 100), r2(800, 800);
    Skill skill1, skill2;

    int framecount = 0;

    while (r1.alive && r2.alive) {
        framecount++;

        Vec d1(0, 0);
        if (GetAsyncKeyState(VK_LEFT))  d1.x = -1;
        if (GetAsyncKeyState(VK_RIGHT)) d1.x = 1;
        if (GetAsyncKeyState(VK_UP))    d1.y = -1;
        if (GetAsyncKeyState(VK_DOWN))  d1.y = 1;
        Vec d2(0, 0);
        if (GetAsyncKeyState('A')) d2.x = -1;
        if (GetAsyncKeyState('D')) d2.x = 1;
        if (GetAsyncKeyState('W')) d2.y = -1;
        if (GetAsyncKeyState('S')) d2.y = 1;

        move(d1, r1);
        move(d2, r2);
        trigger(r1, skill1, VK_RETURN);
        trigger(r2, skill2, 'F');

        for (int i = (int)drinks.size() - 1;i >= 0;i--) {
            L& f = drinks[i];
            if (hypot(r1.x - f.x, r1.y - f.y) < r1.radius() + 12) {
                r1.drinks++;
                drinks.erase(drinks.begin() + i);
            }
            else if (hypot(r2.x - f.x, r2.y - f.y) < r2.radius() + 12) {
                r2.drinks++;
                drinks.erase(drinks.begin() + i);
            }
        }

        auto limit = [&](Rabbit& r) {
            r.x = min(max(r.x, (float)r.radius()), WIDTH - r.radius());
            r.y = min(max(r.y, (float)r.radius()), HEIGHT - r.radius());
            };
        limit(r1); limit(r2);

        cleardevice();
        putimage(0, 0, &imgBackground);

        skilleff(r1, r2, skill1);
        skilleff(r2, r1, skill2);

        for (auto& f : drinks) {
            setfillcolor(RGB(144, 238, 144));
            int drink[8] = { f.x - 8, f.y - 5, f.x + 8, f.y - 5, f.x + 5, f.y + 15, f.x - 5, f.y + 15 };
            fillpoly(4, drink);
            setfillcolor(RGB(139, 69, 19));
            fillrectangle(f.x - 2, f.y - 15, f.x + 2, f.y - 5);
        }

        drawRabbit(r1);
        drawRabbit(r2);

        FlushBatchDraw();
        Sleep(30);
        if (_kbhit() && _getch() == 27) break;
    }

    cleardevice();
    if (!r2.alive) putimage(0, 0, &imgWin1);
    else if (!r1.alive) putimage(0, 0, &imgWin2);
    FlushBatchDraw();


    ofstream file("best_kos.txt", ios::app);
    file << "This game used " << framecount << " frames.\n";
    file.close();

    while (!_kbhit()) Sleep(100);
    _getch();
    closegraph();
    return 0;
}