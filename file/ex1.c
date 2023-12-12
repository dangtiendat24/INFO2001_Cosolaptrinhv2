#include <stdio.h>

typedef struct {
    char Name[50];
    int ID;
    float GPA;
} sv;

void addStudent(FILE *file, sv student){
    fprintf(file, "%s %d %.2f\n", student.Name, student.ID, student.GPA );
}

void updateStudent(FILE *file,int targetID, sv newStudent){
    FILE *tempFile = fopen("temp.txt", "w");
    if(tempFile == NULL){
        printf("cannot open tempFile\n");
    }
    sv currentstudent;
    rewind(file);
    while(fscanf(file, "%s %d %f", currentstudent.Name, &currentstudent.ID, &currentstudent.GPA) ==3);
        if(currentstudent.ID == targetID){
            fprintf(tempFile, "%s %d %.2f\n", newStudent.Name, newStudent.ID, newStudent.GPA);
        }else{
            fprintf(tempFile, "%s %d %.2f\n", currentstudent.Name, currentstudent.ID, currentstudent.GPA);
        }
    fclose(file);
    fclose(tempFile);
    remove("exam.txt");
    rename("temp.txt", "exam.txt");
    file = fopen("exam.txt", "a");
    if(file == NULL){
        printf("cannot open file\n");
    }
}

void deleteStudent(FILE *file, int targetID){
    FILE *tempFile = fopen("temp.txt", "w");
    if(tempFile == NULL){
        printf("cannot open tempfile\n ");
    }
    sv currentstudent;
    rewind(file);
    while(fscanf(file, "%s %d %f", currentstudent.Name, currentstudent.ID, currentstudent.GPA)==3){
        if(currentstudent.ID != targetID){
            fprintf(tempFile, "%s %d %.2f", currentstudent.Name, currentstudent.ID, currentstudent.GPA);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove("exam.txt");
    rename("temp.txt", "exam.txt");
    file = fopen("exam.txt", "a");
    if(file == NULL){
        printf("cannot open file\n");
    }
}

int main(){
    FILE *file = fopen("exam.txt", "a");
    char line[256];
    if(file == NULL){
        printf("cannot open file\n");
        return 1;
    }
    int choice;
    sv student;

    do{
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("0. Exit\n");
        printf("Enter Your Selection: ");
        scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter student name: ");
            getchar();
            fgets(student.Name, 30, stdin);
            printf("Enter student ID: ");
            scanf("%d", &student.ID);
            printf("Enter student GPA: ");
            scanf("%f", &student.GPA);

            addStudent(file, student);
            break;
        case 2:
            int updateID;
            printf("enter the student id that needs updating: ");
            scanf("%d", &updateID);
            printf("enter new student information\n");
            printf("enter student name: ");
            getchar();
            fgets(student.Name, 30, stdin);
            printf("enter student ID: ");
            scanf("%d", &student.ID);
            printf("enter student GPA: ");
            scanf("%f", &student.GPA);
            updateStudent(file, updateID, student);
            break;
        case 3:
            int deleteID;
            printf("enter the student id that needs delete: ");
            scanf("%d", &deleteID);
            deleteStudent(file, deleteID);
            break;
        case 0:
            break;
        default:
            printf("Invalid selection");
        }
    }while(choice != 0);
    fclose(file);
}