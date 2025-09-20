#include <stdio.h>

int main() {
    char a,b,c,d,e,f,g,h,i,j,k;
    scanf("%c%c%c%c%c%c%c%c%c%c%c",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k);

    int pasangan=0;
    if(a==k) pasangan++;
    if(b==j) pasangan++;
    if(c==i) pasangan++;
    if(d==h) pasangan++;
    if(e==g) pasangan++;

    int spasi=0;
    if(a==' '||b==' '||c==' '||d==' '||e==' '||f==' '||g==' '||h==' '||i==' '||j==' '||k==' ') spasi=1;

    if(pasangan==5) {
        if(spasi) printf("SP4C3 R3FL3CT10N\n");
        else printf("M1RR0R M4ST3R\n");
    } else if(pasangan>=3) {
        printf("4LM0ST 4 M1RR0R\n");
    } else if(pasangan>=1) {
        printf("N34R M1SS\n");
    } else {
        printf("CH40S D3T3CT3D\n");
    }
    return 0;
}