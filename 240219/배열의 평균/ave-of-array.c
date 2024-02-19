#include <stdio.h>

int main() {
    float arr[2][4]={0};
    float sum=0;

    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            scanf("%f ", &arr[i][j]);
            sum+=arr[i][j];
        }
        printf("%.1f ",sum/4);
        sum=0;
    }
    printf("\n");

    for(int j=0;j<4;j++){
        for(int i=0;i<2;i++){
            sum+=arr[i][j];
        }
        printf("%.1f ",sum/2);
        sum=0;
    }
    printf("\n");

    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
    }
    printf("%.1f ",sum/8);


    return 0;
}