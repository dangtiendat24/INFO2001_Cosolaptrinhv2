#include <stdio.h>

int main(){
    int i;
    int n;
    printf("nhap n: ");
    scanf("%d", &n); 
    if(n<2){
        printf("%d khong la so nguyen to", n);
        return 0;
    }
    int a=0;
    for (i=2; i<n; i++){
        if(n%i==0){
            a++;
        }
    }
    if(a==0){
            printf("%d la so nguyen to", n);
        }else{
            printf("%d khong la so nguyen to", n);
        }
}