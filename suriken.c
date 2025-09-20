#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

double cross_product(Point p, Point q, Point r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

int on_segment(Point p, Point q, Point r) {
    if (q.x <= fmax(p.x, r.x) && q.x >= fmin(p.x, r.x) &&
        q.y <= fmax(p.y, r.y) && q.y >= fmin(p.y, r.y)) {
        return 1;
    }
    return 0;
}

int main() {
    Point p1, q1, p2, q2;

    scanf("%lf %lf", &p1.x, &p1.y);
    scanf("%lf %lf", &q1.x, &q1.y);
    scanf("%lf %lf", &p2.x, &p2.y);
    scanf("%lf %lf", &q2.x, &q2.y);

    double o1 = cross_product(p1, q1, p2);
    double o2 = cross_product(p1, q1, q2);
    double o3 = cross_product(p2, q2, p1);
    double o4 = cross_product(p2, q2, q1);

    if (o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0) {
        if (((o1 > 0 && o2 < 0) || (o1 < 0 && o2 > 0)) &&
            ((o3 > 0 && o4 < 0) || (o3 < 0 && o4 > 0))) {
            
            double A1 = q1.y - p1.y;
            double B1 = p1.x - q1.x;
            double C1 = A1 * p1.x + B1 * p1.y;

            double A2 = q2.y - p2.y;
            double B2 = p2.x - q2.x;
            double C2 = A2 * p2.x + B2 * p2.y;

            double det = A1 * B2 - A2 * B1;

            double x = (B2 * C1 - B1 * C2) / det;
            double y = (A1 * C2 - A2 * C1) / det;

            printf("BERPOTONGAN: %.2lf, %.2lf\n", x, y);
        } else {
            printf("HMMMM NOTHING\n");
        }
    } else {
        if (o1 == 0 && on_segment(p1, p2, q1)) {
            printf("BERSENTUHAN DIUJUNG\n");
        } else if (o2 == 0 && on_segment(p1, q2, q1)) {
            printf("BERSENTUHAN DIUJUNG\n");
        } else if (o3 == 0 && on_segment(p2, p1, q2)) {
            printf("BERSENTUHAN DIUJUNG\n");
        } else if (o4 == 0 && on_segment(p2, q1, q2)) {
            printf("BERSENTUHAN DIUJUNG\n");
        } else if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
            double min_x1 = fmin(p1.x, q1.x);
            double max_x1 = fmax(p1.x, q1.x);
            double min_y1 = fmin(p1.y, q1.y);
            double max_y1 = fmax(p1.y, q1.y);

            double min_x2 = fmin(p2.x, q2.x);
            double max_x2 = fmax(p2.x, q2.x);
            double min_y2 = fmin(p2.y, q2.y);
            double max_y2 = fmax(p2.y, q2.y);

            if (fmax(min_x1, min_x2) <= fmin(max_x1, max_x2) && fmax(min_y1, min_y2) <= fmin(max_y1, max_y2)) {
                if ((fabs(p1.x-p2.x) < 1e-9 && fabs(p1.y-p2.y) < 1e-9) ||
                    (fabs(p1.x-q2.x) < 1e-9 && fabs(p1.y-q2.y) < 1e-9) ||
                    (fabs(q1.x-p2.x) < 1e-9 && fabs(q1.y-p2.y) < 1e-9) ||
                    (fabs(q1.x-q2.x) < 1e-9 && fabs(q1.y-q2.y) < 1e-9)) {
                    printf("BERSENTUHAN DIUJUNG\n");
                } else {
                    printf("MENUMPUK DISATU JALUR YANG SAMA\n");
                }
            } else {
                printf("SEJAJAR\n");
            }
        } else {
            printf("SEJAJAR\n");
        }
    }

    return 0;
}
