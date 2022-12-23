#include <stdio.h>

struct student{
    char name[20];
    int rollno;
    int marks[5];
    int total;
    char grade;
};

int main(){
    struct student stu[3];
    struct student temp;
    int i, j;

    printf("Enter data of 3 students:\n");
    for (i=0; i<3; i++){
        printf("Student %d:\n", i+1);
        printf("Enter Name: ");
        if (i!=0)
            getchar();
        gets(stu[i].name);
        printf("Enter rollno: ");
        scanf("%d", &stu[i].rollno);
        printf("Enter marks in 5 subjects: ");
        
        stu[i].total = 0;
        for (j=0; j<5; j++){
            scanf("%d", &stu[i].marks[j]);
            stu[i].total += stu[i].marks[j];
        }
        
        if (stu[i].total/5 >= 90)
            stu[i].grade = 'O';
        else if (stu[i].total/5 >= 80)
            stu[i].grade = 'E';
        else if (stu[i].total/5 >= 70)
            stu[i].grade = 'A';
        else if (stu[i].total/5 >= 60)
            stu[i].grade = 'B';
        else if (stu[i].total/5 >= 50)
            stu[i].grade = 'C';
        else if (stu[i].total/5 >= 40)
            stu[i].grade = 'D';
        else   
            stu[i].grade = 'F';
        
        printf("\n");
    }

    for (i=0; i<3; i++){
        for (j=0; j<3-i-1; j++){
            if (stu[j].total > stu[j+1].total){
                temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    }

    printf("\nStudents have been sorted by total marks\n");
    for (i=0; i<3; i++){
        printf("\n");
        printf("Name: %s\n", stu[i].name);
        printf("Roll Number: %d\n", stu[i].rollno);
        printf("Marks: %d, %d, %d, %d, %d\n", stu[i].marks[0], stu[i].marks[1], stu[i].marks[2], stu[i].marks[3], stu[i].marks[4]);
        printf("Total Marks: %d\n", stu[i].total);
        printf("Grade: %c\n", stu[i].grade);
    }

    return 0;
}