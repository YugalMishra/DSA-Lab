#include <stdio.h>

struct ArrivalTime{
    int hours;
    int minutes;
};

struct TrainDetails{
    char name[50];
    char time_12[10];
    struct ArrivalTime time;
};

int main(){
    struct TrainDetails train[5];
    int i;

    printf("Enter train details: \n");
    for (i=0; i<5; i++){
        printf("Train %d\n", i+1);
        printf("Enter name of train: ");
        if (i!=0)
            getchar();    
        gets(train[i].name);
        printf("Enter arrival time (in hh:mm AM/PM format): ");
        gets(train[i].time_12);

        train[i].time.hours = (train[i].time_12[0] - '0')*10 + (train[i].time_12[1] - '0');
        train[i].time.minutes = (train[i].time_12[3] - '0')*10 + (train[i].time_12[4] - '0');
        
        if (train[i].time_12[6] == 'P'){
            if (train[i].time.hours != 12)
                train[i].time.hours += 12;
        }

        else{
            if (train[i].time.hours == 12)
                train[i].time.hours = 0;
        }
        printf("\n");
    }

    printf("\nOutput Details:\n");
    for (i=0; i<5; i++){
        printf("Name of train: %s\n", train[i].name);
        printf("Time of arrival: %d:%d Hrs\n\n", train[i].time.hours, train[i].time.minutes);
    }

    return 0;
}