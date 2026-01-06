#include <string>
#include "Graph.hpp"
void test() {
    Canvas canvas;
    canvas.add("circle");
    canvas.add("triangle");
    canvas.add("rectangle");
    canvas.paint();
}
int main() {
    test();
}