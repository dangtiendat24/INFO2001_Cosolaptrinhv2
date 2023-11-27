#include <stdio.h>

struct Student{
    int ID;
    char Name[30];
    int age;
    float GPA;
};

int findStudent(struct Student std[], int n, int id){
    for(int i=0;i<n;i++){
        if(std[i].ID==id){
            return i;
        }
    }
    return -1;
}
  
int editStudent(struct Student std[], int n){
    int id, edit;
    printf("nhap ma sinh vien can sua : " );
    scanf("%d", &id);
    edit = findStudent (std, n, id);
    if(edit == -1){
        printf("khong co sinh vien co ma so nhu tren\n");
    }else{
        printf("SUA THONG TIN SINH VIEN CO MA SO %d\n", id);
        printf("ho va ten: ");
        getchar();
        fgets(std[edit].Name, 30, stdin);
        printf("tuoi: ");
        scanf("%d", &std[edit].age);
        printf("GPA: ");
        scanf("%f", &std[edit].GPA);
        printf("Da sua thong tin sinh vien co ma so %d\n", id);
    }
    return 0;
}

void printStudent(struct Student std[], int n){
    for(int i=0;i<n;i++){
        printf("\n");
        printf("thong tin sv thu %d la:\n",i+1);
        printf("ma sinh vien: %d\n", std[i].ID);
        printf("ho va ten: %s", std[i].Name);
        printf("tuoi:%d\n", std[i].age);
        printf("GPA:%f", std[i].GPA);
        printf("\n");
    }
    printf("\n------------------------------------\n");
}

int main(){
    int n;
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

    printf("----------------------------------------\n");
    printStudent(std,n);
    int choice = 0;
    do{
        printf("BAN CO MUON SUA THONG TIN SINH VIEN KHONG? (1:co, 2:khong): ");
        scanf("%d", &choice);
        if(choice==1){
            editStudent (std, n);
        }
    }while(choice==1);

    return 0;
}

