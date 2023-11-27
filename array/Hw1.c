#include <stdio.h>
#include <time.h>

int array(int a[]) {
    int n;
    printf("Nhap so phan tu mang : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d] = ", i + 1);
        scanf("%d", &a[i]);
    }
    return n;
}

void bublleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[i]) {
                int A = a[i];
                a[i] = a[j];
                a[j] = A;
            }
        }
    }
}

void selectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
                int A = a[min];               
                a[min] = a[i];
                a[i] = A;
            }
        }
    }
}

void listOfNumber(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

int main() {
    int n, a[1000];
    n = array(a); 
    clock_t start, end;
    printf("day so vua nhap la : ");
    listOfNumber(a,n);

    start = clock();
    bublleSort(a,n);
    end = clock();
    printf("day so sau khi sap xep bang bublerSort la : ");
    listOfNumber(a,n);
    double time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("thoi gian thuc thi thuat toan cua bubleSort la : %f\n", time1);

    start = clock();
    selectionSort(a,n);
    end = clock();
    printf("day so sau khi sap xep bang selectionSort la : ");
    listOfNumber(a,n);
    double time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("thoi gian thuc thi thuat toan cua selectionSort la : %f", time2); 
}
