#include <stdio.h>

struct Student{
    int ID;
    char Name[30];
    int age;
    float GPA;
};

void arrangeGPA(struct Student std[],int n ){
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(std[i].GPA < std[j].GPA){
                struct Student A = std[i];
                std[i] = std[j];
                std[j] = A;
            }
        }
    }
}

int findStudent(struct Student std[], int n, int id){
    for(int i=0;i<n;i++){
        if(std[i].ID==id){
            printf("%d %s %d %f", std[i].ID, std[i].Name, std[i].age, std[i].GPA);
            return 1;
        }
    }
    printf("khong tim thay sinh vien nao co ma nhu tren !\n");
    return 0;
    
}

void printStudent(struct Student std[], int n){
    for(int i=0;i<n;i++){
        printf("\n");
        printf("thong tin sv thu %d la:\n",i+1);
        printf("%d %s %d %f", std[i].ID, std[i].Name, std[i].age, std[i].GPA ); 
        printf("\n");
    }
    printf("\n------------------------------------\n");
}

int main(){
    int n, id;
    printf("nhap so sinh vien: ");
    scanf("%d", &n);
    struct Student std[n];

    for(int i=0;i<n;i++){
        printf("nhap thong tin sv thu %d \n", i+1);
        printf("ma sinh vien: ");
        scanf("%d", &std[i].ID);
        getchar();
        printf("Ho va ten sinh vien: ");
        fgets(std[i].Name, 30, stdin);
        printf("tuoi: ");
        scanf("%d", &std[i].age);
        printf("GPA:");
        scanf("%f", &std[i].GPA);
    }
    printf("danh sach sv truoc khi sap xep la: ");
    printStudent(std,n);
    arrangeGPA(std,n);
    printf("danh sach sv sau khi sap xep theo GPA la: ");
    printStudent(std,n);
    printf("nhap ma sinh vien can tim: ");
    scanf("%d", &id);
    if(findStudent(std,n,id) == 0){
        printf("khong tim thay sinh vien nao co ma nhu tren !\n");
    }
    return 0;
}

