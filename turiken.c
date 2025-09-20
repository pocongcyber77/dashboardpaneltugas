#include <stdio.h>

int min(int a,int b){ return a<b?a:b; }
int max(int a,int b){ return a>b?a:b; }

int main() {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

    long long dx1 = x2-x1, dy1 = y2-y1;
    long long dx2 = x4-x3, dy2 = y4-y3;

    long long o1 = dx1*(y3-y1) - dy1*(x3-x1);
    long long o2 = dx1*(y4-y1) - dy1*(x4-x1);
    long long o3 = dx2*(y1-y3) - dy2*(x1-x3);
    long long o4 = dx2*(y2-y3) - dy2*(x2-x3);

    long long det = dx1*dy2 - dy1*dx2;

    int minx1=min(x1,x2), maxx1=max(x1,x2);
    int miny1=min(y1,y2), maxy1=max(y1,y2);
    int minx2=min(x3,x4), maxx2=max(x3,x4);
    int miny2=min(y3,y4), maxy2=max(y3,y4);

    /* Cek colinear */
    if(o1==0 && o2==0 && o3==0 && o4==0){
        int overlapX = max(minx1,minx2) <= min(maxx1,maxx2);
        int overlapY = max(miny1,miny2) <= min(maxy1,maxy2);
        if(overlapX && overlapY){
            if( (x1==x3&&y1==y3) || (x1==x4&&y1==y4) ||
                (x2==x3&&y2==y3) || (x2==x4&&y2==y4) ){
                printf("BERSENTUHAN DIUJUNG\n");
            } else {
                printf("MENUMPUK DISATU JALUR YANG SAMA\n");
            }
        } else {
            printf("SEJAJAR\n");
        }
        return 0;
    }

    /* Proper intersection */
    if(((o1>0&&o2<0)||(o1<0&&o2>0)) && ((o3>0&&o4<0)||(o3<0&&o4>0))){
        double A1=y2-y1, B1=x1-x2, C1=A1*x1+B1*y1;
        double A2=y4-y3, B2=x3-x4, C2=A2*x3+B2*y3;
        double ix=(B2*C1-B1*C2)/(A1*B2-A2*B1);
        double iy=(A1*C2-A2*C1)/(A1*B2-A2*B1);
        printf("BERPOTONGAN: %.2f, %.2f\n",ix,iy);
        return 0;
    }

    /* Endpoint touch */
    if(o1==0 && x3>=minx1&&x3<=maxx1&&y3>=miny1&&y3<=maxy1){ printf("BERSENTUHAN DIUJUNG\n"); return 0; }
    if(o2==0 && x4>=minx1&&x4<=maxx1&&y4>=miny1&&y4<=maxy1){ printf("BERSENTUHAN DIUJUNG\n"); return 0; }
    if(o3==0 && x1>=minx2&&x1<=maxx2&&y1>=miny2&&y1<=maxy2){ printf("BERSENTUHAN DIUJUNG\n"); return 0; }
    if(o4==0 && x2>=minx2&&x2<=maxx2&&y2>=miny2&&y2<=maxy2){ printf("BERSENTUHAN DIUJUNG\n"); return 0; }

    /* Sejajar tapi tidak colinear */
    if(det==0){ printf("SEJAJAR\n"); return 0; }

    /* Tidak berhubungan */
    printf("HMMMM NOTHING\n");
    return 0;
}