#include <stdio.h>

struct PersonDetails{
    char name[100];
    int age;
    char city[50];
};

int main(){
    struct PersonDetails people[5];
    int i, reqIndex, maxAge = 0;
    printf("Enter the details of 5 people:\n");
    for (i=0; i<5; i++){
        printf("Person %d:\n", i+1);
        printf("Enter name: ");
        getchar();
        scanf("%[^\n]s", &people[i].name);
        printf("Enter age: ");
        scanf("%d", &people[i].age);
        printf("Enter city: ");
        getchar();
        scanf("%[^\n]s", &people[i].city);
        printf("\n");

        if (people[i].age > maxAge){
            maxAge = people[i].age;
            reqIndex = i;
        }
    }

    printf("Required Person details:\n");
    printf("Name: %s\n", people[reqIndex].name);
    printf("City: %s\n", people[reqIndex].city);

    return 0;
}