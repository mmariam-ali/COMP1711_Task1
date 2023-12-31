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
    char steps[10];  
} FITNESS_DATA;


int main() {
    char record[21], date[11], time[6], steps[10];
    int stepsint, line_count=0;
    int buffer_size=256;
    char buffer[buffer_size];

    FILE *file= fopen("FitnessData_2023.csv", "r");
        if (file ==NULL) {
            perror("Error opening file\n");
            return 1;
        }

        while(fgets(buffer, buffer_size, file)!= NULL) {
            //printf("%s\n", buffer);
            line_count++;
        }
    printf("Number of records in file: %d", line_count);

    FITNESS_DATA fitness_data[line_count]; //declaring struct array and length

    while (fgets(buffer, buffer_size, file) != NULL) {
        int i =0;//for (int i=0; i <line_count; i++) { //for every line in csv file
        char record = buffer; //assigning buffer value to char
        printf("%s\n", record);
        //fitness_data[i] = {"%s", record};
        printf("%s\n", fitness_data[i]);
        tokeniseRecord(record, ",", date, time, steps); //splitting into date, time and steps
        i++;
        //fitness_data[i] = "%s %s %s", date, time, steps;
    }


    // for (int i=0; i < count; i++) {
    // //stepsint = atoi(steps);
    // printf("\n%s/%s/%s\n", date, time, steps);
    // };


    fclose(file);
    return 0;
}