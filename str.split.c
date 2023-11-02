#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

 struct FITNESS_DATA {
    char record[21] ;
    char date[11];
    char time[6];
    char steps[10];  // Large enough to hold a typical step count as a string

    //int stepsint;

};


int main() {
    char record, date[11], time[6], steps[10];
    int stepsint ,count =3;

    struct FITNESS_DATA fitness_datas= {{"2023-09-01,07:30,300"}, 
                                        {"2023-09-01,07:45,400"},
                                        {"2023-09-01,08:00,600"},};
    ;
    
    tokeniseRecord(fitness_datas.record, ",", date, time, steps);
    stepsint = atoi(steps);
    
    
    printf("%s/%s/%d\n", date, time, stepsint);
    

    // Convert the steps string to an integer
    
    //printf("Steps as an integer: %d\n", stepsint);
    
    return 0;
}