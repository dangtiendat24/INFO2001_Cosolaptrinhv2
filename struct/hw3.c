#include <stdio.h>

struct Employee {
    int ID;
    char Name[30];
    char Position[30];
    double Salary;
};

int findEmployee(struct Employee epy[], int n, int id){
    for(int i = 0; i < n; i++){
        if(epy[i].ID == id){
        return i;
        }
    }
    return -1;
}

void printInfomation(struct Employee epy[], int n){
    for(int i = 0; i < n; i++){
        printf("\n");
        printf("thong tin nhan vien thu %d la: ", i + 1);
        printf("%d %s %s %.2lf", epy[i].ID, epy[i].Name, epy[i].Position, epy[i].Salary);
        printf("\n");
    }
}

void arrangeSalary(struct Employee epy[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = n -1; j > i; j--){
            if(epy[j].Salary < epy[i].Salary){
                int A = epy[i].Salary;
                epy[i].Salary = epy[j].Salary;
                epy[j].Salary = A;
            }
        }
    }
}


int deleteEmployee(struct Employee epy[], int n, int id){
    int found = 0;
    int delete = findEmployee(epy,n,id);
    if(delete != -1){
        for(int i = delete; i < n; i++){
            epy[i] = epy[i + 1];
        }
        found = 1;
    }return found;
}   

int main(){
    int n;
    printf("nhap so nhan vien: ");
    scanf("%d", &n);
    struct Employee epy[n];

    for(int i = 0; i < n; i++){
        printf("nhap thong tin nhan vien thu %d:\n", i + 1);
        printf("nhap ma nhan vien: ");
        scanf("%d", &epy[i].ID);
        getchar();
        printf("nhap ten nhan vien: ");
        fgets(epy[i].Name, 30, stdin);
        printf("nhap chuc vu cua nhan vien: ");
        fgets(epy[i].Position, 30, stdin);
        printf("nhap luong cua nhan vien: ");
        scanf("%lf", &epy[i].Salary);
    }
    printf("-------------------------------------------\n");
    printf("danh sach nhan vien truoc khi sap xep la: ");
    printInfomation(epy,n);
    printf("-------------------------------------------\n");
    printf("danh sach nhan vien sau khi sap xep theo luong la: ");
    arrangeSalary(epy,n);
    printInfomation(epy,n);

    int choice = 0;
    do{
        printf("BAN CO MUON SUA XOA NHAN VIEN KHONG? (1:co, 2:khong): ");
        scanf("%d", &choice);
        if(choice==1){
            int id;
            printf("nhap ma nhan vien can xoa: ");
            scanf("%d", &id);
            if(!deleteEmployee(epy,n,id)){
                printf("khong co nhan vien co ma nhu tren\n");
            }else{
                n--;
                printf("danh sach nhan vien sau khi xoa la:\n");
                printInfomation(epy,n);
            }
        }
        printf("\n");
    }while(choice==1);
    return 0;
}