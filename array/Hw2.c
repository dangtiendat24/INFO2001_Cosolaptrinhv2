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

int linearSearch(int a[], int n, int x){
    for (int i = 0; i < n; i++){
        if(a[i] == x){
            return 1;
        }
    }return -1;
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

int binarySearch(int a[], int n, int x){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == x){
            return 1;
        }else if(a[mid] < x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}

void listOfNumbers(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%7d", a[i]);
    }
    printf("\n");
}

int main(){
    int a[1000], n, x;
    n = array(a);
    clock_t start, end;
    printf("day so ban vua nhap la : ");
    listOfNumbers(a,n);
    printf("nhap phan tu x ban muon tim: ");
    scanf("%d", &x);

    start = clock();
    if(linearSearch(a,n,x) == 1){
        printf("ton tai phan tu x trong mang\n");
    }else{
        printf("khong ton tai phan tu x trong mang\n");
    }
    end = clock();
    double time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("thoi gian thuc thi linearSearch la: %f\n", time1);

    bublleSort(a,n);
    start = clock();
    if(binarySearch(a,n,x) == 1){
        printf("ton tai phan tu x trong mang\n");
    }else{
        printf("khong ton tai phan tu x trong mang\n");
    }
    end = clock();
    double time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("thoi gian thuc thi binarySearch la: %f\n", time2);
    return 0;
}