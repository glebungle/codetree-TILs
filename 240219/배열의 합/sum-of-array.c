#include <stdio.h>

int main() {
    int sum=0;
    int arr[4]={0};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &arr[j]);
            sum+=arr[j];
        }
        printf("%d", sum);
        sum=0;
        printf("\n");
    }


    return 0;
}