#include <stdio.h>
#include <string.h>

struct date{
    int day;
    int month;
    int year;
};

struct employee{
    char name[20];
    struct date dob;
    struct date doj;
    int salary;
};

int main(){
    void swap(struct employee *, struct employee *);
    void sortByName(struct employee emp[], int);
    void sortByDOB(struct employee emp[], int);
    void sortByDOJ(struct employee emp[], int);
    void sortBySalary(struct employee emp[], int);
    struct employee emp[3];
    char temp[15];
    int i, userInput;
    char continueInput = 'y';

    printf("Please enter employee details:\n");
    for (i=0; i<3; i++){
        printf("Employee %d:\n", i+1);
        printf("Enter name: ");
        if (i!=0)
            getchar();
        gets(emp[i].name);

        printf("Enter DOB (dd.mm.yy): ");
        gets(temp);
        emp[i].dob.day = (temp[0] - '0')*10 + (temp[1] - '0');
        emp[i].dob.month = (temp[3] - '0')*10 + (temp[4] - '0');
        emp[i].dob.year = (temp[6] - '0')*10 + (temp[7] - '0');

        printf("Enter DOJ (dd.mm.yy): ");
        gets(temp);
        emp[i].doj.day = (temp[0] - '0')*10 + (temp[1] - '0');
        emp[i].doj.month = (temp[3] - '0')*10 + (temp[4] - '0');
        emp[i].doj.year = (temp[6] - '0')*10 + (temp[7] - '0');

        printf("Enter salary: ");
        scanf("%d", &emp[i].salary);
        printf("\n");
    }

    while ((continueInput == 'y') || (continueInput == "Y")){
        printf("Enter 1 for sort by name\n");
        printf("Enter 2 for sort by DOB\n");
        printf("Enter 3 for sort by DOJ\n");
        printf("Enter 4 for sort by salary\n");
        printf("Your input: ");
        scanf("%d", &userInput);

        if (userInput == 1)
            sortByName(emp, 3);
        else if (userInput == 2)
            sortByDOB(emp, 3);
        else if (userInput == 3)
            sortByDOJ(emp, 3);
        else if (userInput == 4)
            sortBySalary(emp, 3);

        printf("The sorted records are as follows:\n\n");
        for (i=0; i<3; i++){
            printf("Name of employee: %s\n", emp[i].name);
            printf("DOB: %d/%d/%d\n", emp[i].dob.day, emp[i].dob.month, emp[i].dob.year);
            printf("DOJ: %d/%d/%d\n", emp[i].doj.day, emp[i].doj.month, emp[i].doj.year);
            printf("Salary: %d\n\n", emp[i].salary);
        }

        printf("Would you like to continue (y/n): ");
        scanf("%c", &continueInput);
        printf("\n");
    }
    return 0;
}

void swap(struct employee *emp1, struct employee *emp2){
    struct employee temp;
    temp = *emp1;
    *emp1 = *emp2;
    *emp2 = temp;
}


//i)
void sortByName(struct employee emp[], int n){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n-i-1; j++){
            if (strcmp(emp[j].name, emp[j+1].name) > 0)
                swap(&emp[j], &emp[j+1]);
        }
    }
    printf("The records have been sorted by name.\n");
}


//ii)
void sortByDOB(struct employee emp[], int n){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n-i-1; j++){
            if (emp[j].dob.year > emp[j+1].dob.year)
                swap(&emp[j], &emp[j+1]);

            else if (emp[j].dob.year == emp[j+1].dob.year){
                if (emp[j].dob.month > emp[j+1].dob.month)
                    swap(&emp[j], &emp[j+1]);

                else if (emp[j].dob.month == emp[j+1].dob.month){
                    if (emp[j].dob.day > emp[j+1].dob.day)
                        swap(&emp[j], &emp[j+1]);
                }
            }
        }
    }
    printf("The records have been sorted by DOB");
}


//iii)
void sortByDOJ(struct employee emp[], int n){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n-i-1; j++){
            if (emp[j].doj.year > emp[j+1].doj.year)
                swap(&emp[j], &emp[j+1]);

            else if (emp[j].doj.year == emp[j+1].doj.year){
                if (emp[j].doj.month > emp[j+1].doj.month)
                    swap(&emp[j], &emp[j+1]);

                else if (emp[j].doj.month == emp[j+1].doj.month){
                    if (emp[j].doj.day > emp[j+1].doj.day)
                        swap(&emp[j], &emp[j+1]);
                }
            }
        }
    }
    printf("The records have been sorted by DOJ");
}


//iv)
void sortBySalary(struct employee emp[], int n){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n-i-1; j++){
            if (emp[j].salary > emp[j+1].salary)
                swap(&emp[j], &emp[j+1]);
        }
    }
    printf("The records have been sorted by salary.\n");
}