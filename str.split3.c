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

 typedef struct {
    char record[21] ;
    char date[11];
    char time[6];
    char steps[10];  // Large enough to hold a typical step count as a string
} FITNESS_DATA;


int main() {
    char record, date[11], time[6], steps[10];
    int stepsint ,count =3, line_count=0;
    int buffer_size=256;
    char buffer[buffer_size];

    FILE *file= fopen("FitnessData_2023.csv", "r");
        while(fgets(buffer, buffer_size, file)!= NULL) {
            line_count++;
        }
    printf("Number of records in file: %d", line_count);


    while (fgets(buffer, buffer_size, file) != NULL) {
        for (int i=0; i <line_count; i++) { //for every line in csv file
        FITNESS_DATA fitness_data[line_count]; //declaring struct array and length
        char record = buffer; //assigning buffer value to char
        tokeniseRecord(record, ",", date, time, steps); //splitting into date, time and steps

        fitness_data[i] = "%s %s %s", date, time, steps;
    }
    }

    /*FITNESS_DATA fitness_datas[]= {{"2023-09-01,07:30,300"}, 
                                        {"2023-09-01,07:45,400"},
                                        {"2023-09-01,08:00,600"},};
    ;*/
    
    for (int i=0; i < count; i++) {
    //stepsint = atoi(steps);
    printf("\n%s/%s/%s\n", date, time, steps);
    };

    // Convert the steps string to an integer
    
    //printf("Steps as an integer: %d\n", stepsint);
    
    return 0;
}