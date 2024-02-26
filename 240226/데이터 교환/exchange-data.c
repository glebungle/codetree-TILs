#include <stdio.h>

int main() {
    int a=5, b=6,c=7, temp=0;
    temp=a;
    a=c;
    printf("%d\n",a);
    a=temp;
    temp=b;
    b=a;
    printf("%d\n",b);
    b=temp;
    c=b;
    printf("%d",c);
    return 0;
}