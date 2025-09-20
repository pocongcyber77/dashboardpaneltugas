#include <stdio.h>
#include <math.h>

#define EPS 1e-9

typedef struct {
    double x, y;
} Point;

double orient(Point p, Point q, Point r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

int between(double a, double b, double c) {
    return fmin(a, b) - EPS <= c && c <= fmax(a, b) + EPS;
}

int on_segment(Point p, Point q, Point r) {
    return between(p.x, r.x, q.x) && between(p.y, r.y, q.y);
}

int same_point(Point a, Point b) {
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}

int main() {
    Point p1, q1, p2, q2;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
          &p1.x, &p1.y, &q1.x, &q1.y, &p2.x, &p2.y, &q2.x, &q2.y);

    double o1 = orient(p1, q1, p2);
    double o2 = orient(p1, q1, q2);
    double o3 = orient(p2, q2, p1);
    double o4 = orient(p2, q2, q1);

    double A1 = q1.y - p1.y;
    double B1 = p1.x - q1.x;
    double C1 = A1 * p1.x + B1 * p1.y;

    double A2 = q2.y - p2.y;
    double B2 = p2.x - q2.x;
    double C2 = A2 * p2.x + B2 * p2.y;

    double det = A1 * B2 - A2 * B1;

    if (((o1 > EPS && o2 < -EPS) || (o1 < -EPS && o2 > EPS)) &&
        ((o3 > EPS && o4 < -EPS) || (o3 < -EPS && o4 > EPS))) {
        double x = (B2 * C1 - B1 * C2) / det;
        double y = (A1 * C2 - A2 * C1) / det;
        Point ip = {x, y};
        if (same_point(ip, p1) || same_point(ip, q1) ||
            same_point(ip, p2) || same_point(ip, q2)) {
            printf("BERSENTUHAN DIUJUNG\n");
        } else {
            printf("BERPOTONGAN: %.2lf %.2lf\n", x, y);
        }
        return 0;
    }

    if (fabs(o1) <= EPS && fabs(o2) <= EPS &&
        fabs(o3) <= EPS && fabs(o4) <= EPS) {
        double minx1 = fmin(p1.x, q1.x), maxx1 = fmax(p1.x, q1.x);
        double minx2 = fmin(p2.x, q2.x), maxx2 = fmax(p2.x, q2.x);
        double miny1 = fmin(p1.y, q1.y), maxy1 = fmax(p1.y, q1.y);
        double miny2 = fmin(p2.y, q2.y), maxy2 = fmax(p2.y, q2.y);

        int overlapX = fmax(minx1, minx2) <= fmin(maxx1, maxx2) + EPS;
        int overlapY = fmax(miny1, miny2) <= fmin(maxy1, maxy2) + EPS;

        if (overlapX && overlapY) {
            if (same_point(p1, p2) || same_point(p1, q2) ||
                same_point(q1, p2) || same_point(q1, q2)) {
                printf("BERSENTUHAN DIUJUNG\n");
            } else {
                printf("MENUMPUK DISATU JALUR YANG SAMA\n");
            }
        } else {
            printf("HMMMM NOTHING\n");
        }
        return 0;
    }

    if (fabs(o1) <= EPS && on_segment(p1, p2, q1)) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }
    if (fabs(o2) <= EPS && on_segment(p1, q2, q1)) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }
    if (fabs(o3) <= EPS && on_segment(p2, p1, q2)) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }
    if (fabs(o4) <= EPS && on_segment(p2, q1, q2)) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }

    if (fabs(det) <= EPS) {
        printf("SEJAJAR\n");
        return 0;
    }

    printf("HMMMM NOTHING\n");
    return 0;
}