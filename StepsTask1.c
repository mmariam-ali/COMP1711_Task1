#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct

typedef struct {
	char date[11];
	char time[6];
	char steps[10];
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
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



// Complete the main function
//I used the strsplit.c code on minerva to help how 

int main() {
    char record, date[11], time[6], steps[10]; 
    int intsteps, line_count=0, i;
    int buffer_size=256;    //creating the size of the buffer
    char buffer[buffer_size];   //creating buffer and its size

    FILE *file= fopen("FitnessData_2023.csv", "r");   //open file in read mode and check it isn't empty
        if (file ==NULL) {
            perror("Error opening file\n");
            return 1;
        }

    FITNESS_DATA fitness_data[9999];   //create struct array 

        while (fgets(buffer, buffer_size, file)!= NULL) {   //while the line is not empty
            line_count++;   //counting the number of lines in the file

            tokeniseRecord(buffer, ",", date, time, steps);    //splitting the line into date, time, steps
            strcpy(fitness_data[i].date, date);                //assigning date, time and steps to data struct 
            strcpy(fitness_data[i].time, time);
            strcpy(fitness_data[i].steps, steps);
            i++;                                               //does this for every i; every line in the file
        }
        
    printf("Number of records in file: %d\n", line_count);     //printing line count

        for (int i =0; i <3; i++) {                            //prints out date, time and steps of first 3 records.
            printf("%s/%s/%d\n", fitness_data[i].date,
                         fitness_data[i].time,
                         atoi(fitness_data[i].steps));
                            }

    fclose(file);
    return 0;
}
    
