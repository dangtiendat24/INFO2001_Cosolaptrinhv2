#include <stdio.h>
#include <math.h>

int main(){
    int n;
    int sum;
    printf("nhap n: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        sum += pow(i,2);
    }
    printf("tong binh phuong cac so tu 1 den %d la %d", n, sum);
}