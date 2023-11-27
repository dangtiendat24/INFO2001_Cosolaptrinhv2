#include <stdio.h>

int array(float a[]){
    int n;
    printf("nhap so hoc sinh trong lop: ");
    scanf("%d", &n);
    float sum = 0;
    for(int i = 0; i < n; i++){
        printf("nhap diem hoc sinh thu %d: ", i + 1);
        scanf("%f", &a[i]);
        sum += a[i];
    }
    float average = sum / n;
    printf("diem trung binh cua lop la: %f", average);
    return n;
}

void listOfGrade(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%.2f", a[i]);
    }printf("\n");
}

int main(){
    int a[100], n, x, average;
    n = array(a);
}