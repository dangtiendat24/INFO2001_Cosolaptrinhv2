#include <stdio.h>

int main(){
    float a;
    int i;
    int sum= 0;
    printf("nhap a: ", a);
    scanf("%f", &a);
    for ( i=1; i<=a; i++ ){
        if ( i%2 != 0){
             sum += i;
        }
    }
    printf("tong cac so le nho hon %f la %d:", a, sum );
}