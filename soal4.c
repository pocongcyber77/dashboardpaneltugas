#include <stdio.h>

int main() {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    if (scanf("%d %d %d %d %d %d %d %d", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4) != 8) return 0;

    long long dx1 = (long long)x2 - x1;
    long long dy1 = (long long)y2 - y1;
    long long dx2 = (long long)x4 - x3;
    long long dy2 = (long long)y4 - y3;

    long long o1 = dx1 * ((long long)y3 - y1) - dy1 * ((long long)x3 - x1);
    long long o2 = dx1 * ((long long)y4 - y1) - dy1 * ((long long)x4 - x1);
    long long o3 = dx2 * ((long long)y1 - y3) - dy2 * ((long long)x1 - x3);
    long long o4 = dx2 * ((long long)y2 - y3) - dy2 * ((long long)x2 - x3);

    long long det = dx1 * dy2 - dy1 * dx2;

    int minx1 = x1 < x2 ? x1 : x2;
    int maxx1 = x1 > x2 ? x1 : x2;
    int miny1 = y1 < y2 ? y1 : y2;
    int maxy1 = y1 > y2 ? y1 : y2;

    int minx2 = x3 < x4 ? x3 : x4;
    int maxx2 = x3 > x4 ? x3 : x4;
    int miny2 = y3 < y4 ? y3 : y4;
    int maxy2 = y3 > y4 ? y3 : y4;

    if (det == 0) {
        if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
            if (dx1 != 0) {
                int low = (minx1 > minx2) ? minx1 : minx2;
                int high = (maxx1 < maxx2) ? maxx1 : maxx2;
                if (high < low) { printf("HMMMM NOTHING\n"); return 0; }
                if (high == low) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }
                printf("MENUMPUK DISATU JALUR YANG SAMA\n");
                return 0;
            } else {
                int low = (miny1 > miny2) ? miny1 : miny2;
                int high = (maxy1 < maxy2) ? maxy1 : maxy2;
                if (high < low) { printf("HMMMM NOTHING\n"); return 0; }
                if (high == low) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }
                printf("MENUMPUK DISATU JALUR YANG SAMA\n");
                return 0;
            }
        } else {
            printf("SEJAJAR\n");
            return 0;
        }
    } else {
        if (o1 == 0 && x3 >= minx1 && x3 <= maxx1 && y3 >= miny1 && y3 <= maxy1) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }
        if (o2 == 0 && x4 >= minx1 && x4 <= maxx1 && y4 >= miny1 && y4 <= maxy1) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }
        if (o3 == 0 && x1 >= minx2 && x1 <= maxx2 && y1 >= miny2 && y1 <= maxy2) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }
        if (o4 == 0 && x2 >= minx2 && x2 <= maxx2 && y2 >= miny2 && y2 <= maxy2) { printf("BERSENTUHAN DIUJUNG\n"); return 0; }

        if (((o1 > 0 && o2 < 0) || (o1 < 0 && o2 > 0)) &&
            ((o3 > 0 && o4 < 0) || (o3 < 0 && o4 > 0))) {
            double A1 = (double)(y2 - y1);
            double B1 = (double)(x1 - x2);
            double C1 = A1 * x1 + B1 * y1;
            double A2 = (double)(y4 - y3);
            double B2 = (double)(x3 - x4);
            double C2 = A2 * x3 + B2 * y3;
            double ddet = A1 * B2 - A2 * B1;
            double ix = (B2 * C1 - B1 * C2) / ddet;
            double iy = (A1 * C2 - A2 * C1) / ddet;
            printf("BERPOTONGAN: %.2f, %.2f\n", ix, iy);
            return 0;
        } else {
            printf("HMMMM NOTHING\n");
            return 0;
        }
    }
    return 0;
}