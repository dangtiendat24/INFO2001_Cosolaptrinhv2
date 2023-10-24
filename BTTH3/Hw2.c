#include <stdio.h>

int main(){
    int a;
    printf("nhap a ", a);
    scanf("%d", &a);
    if ( a >= 9 && a <= 10){
        printf("xuat sac");
    }else if( a < 9 && a >= 8 ){
        printf("gioi");
    }else if ( a < 8 && a >= 6.5){
        printf("kha");
    }else if ( a < 6.5 && a >= 5){
        printf("trung binh");
    }else{
        printf("yeu");
    }
}