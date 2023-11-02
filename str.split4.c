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
    //char record[21] ;
    char date[11];
    char time[6];
    char steps[10];  
} FITNESS_DATA;






int main() {
    char record, date[11], time[6], steps[10];
    int intsteps, line_count=0, i;
    int buffer_size=256;
    char buffer[buffer_size];

    FILE *file= fopen("FitnessData_2023.csv", "r");
        if (file ==NULL) {
            perror("Error opening file\n");
            return 1;
        }

    FITNESS_DATA fitness_data[9999];

        while (fgets(buffer, buffer_size, file)!= NULL) {
            //printf("%s", buffer);
            line_count++;

            tokeniseRecord(buffer, ",", date, time, steps);
            //printf("%s/%s/%s\n", date, time, steps);

            strcpy(fitness_data[i].date, date);
            strcpy(fitness_data[i].time, time);
            //intsteps= atoi(steps);
            strcpy(fitness_data[i].steps, steps);
            i++;
            }
        
    printf("Number of records in file: %d\n", line_count);

        for (int i =0; i <3; i++) {
            printf("%s/%s/%d\n", fitness_data[i].date,
                         fitness_data[i].time,
                         atoi(fitness_data[i].steps));
    }

    fclose(file);
    return 0;
}