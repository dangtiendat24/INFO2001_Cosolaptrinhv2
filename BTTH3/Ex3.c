#include <stdio.h>

int main(){
    int month, year;
    printf("nhap thang nam: ");
    scanf("%d %d", &month, &year);
    if(month<1 || month >12 || year<1){
        printf("INVALID");
    }
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30");
            break;
    }
    if(year%400==0 || year%4==0 && year%100!=0){
        switch(month){
            case 2:
               printf("29");
               break;
        }
        }else{
            switch(month){
                case 2:
                   printf("28");
                   break;
            }
        }
}
