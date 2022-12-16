#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

void printPoint(Point p) {
    printf("%f %f\n", p.x, p.y);
}

void koch(int n, Point p1, Point p2) {
    if (n == 0) return;

    Point s = { (p1.x * 2 + p2.x) / 3, (p1.y * 2 + p2.y) / 3 };
    Point t = { (p1.x + p2.x * 2) / 3, (p1.y + p2.y * 2) / 3 };
    // ベクトルstをpi/3回転させたベクトルと、sとの和がuになる
    Point delta;
    // 回転行列で演算
    delta.x = (t.x - s.x) * cos(M_PI / 3) - (t.y - s.y) * sin(M_PI / 3);
    delta.y = (t.x - s.x) * sin(M_PI / 3) + (t.y - s.y) * cos(M_PI / 3);
    Point u = { s.x + delta.x, s.y + delta.y };

    koch(n-1, p1, s);
    printPoint(s);
    koch(n-1, s, u);
    printPoint(u);
    koch(n-1, u, t);
    printPoint(t);
    koch(n-1, t, p2);
}

int main() {
    int n;
    Point p1 = { 0, 0 };
    Point p2 = { 100, 0 };

    scanf("%d", &n);

    printPoint(p1);
    koch(n, p1, p2);
    printPoint(p2);

    return 0;
}
