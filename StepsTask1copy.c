#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct

typedef struct {
	char date[11];
	char time[6];
	int steps;
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
int main() {

    int line_count = 0, i=0;
    int buffer_size = 256;
    char buffer [buffer_size];
    


    /*read the csv file.  sort out buffer? */
    FILE *file = fopen("FitnessData_2023.csv", "r");
        if (file == NULL) {
            perror("File is empty\n");
            return 1;
        };
    
        while (fgets(buffer, buffer_size, file) != NULL) {       
            line_count++;
        };
        printf("Number of records in file: %d", line_count);


    FITNESS_DATA fitness_data[line_count];

    while (fgets(buffer, buffer_size, file) != NULL) {
        fscanf(file, "%s,%s,%d",&fitness_data[i].date,
                                &fitness_data[i].time,
                                &fitness_data[i].steps); 
    }


    for (i =0; i< line_count +1; i++ ) {
            printf ("%s/%s/%d\n", fitness_data[i].date,
                                fitness_data[i].time,
                                fitness_data[i].steps);
            }
            

    //FITNESS_DATA fitness_data[line_count];


    // int read = 0;
    // int records = 0;

    // do {
    //     read = fscanf(file, "%s,%s,%d", &fitness_data[records].date,
    //                                     &fitness_data[records].time,
    //                                     &fitness_data[records].steps);

    // if (read ==3)  records ++;

    // if(read !=3 && !feof(file)) {
    //     printf("File format incorrect");
    //     return 1;
    // }

    // if (ferror(file)) {
    //     printf("Error\n");
    //     return 1;
    // }

    //  }  while (!feof(file));

fclose(file);

        // printf("\n%d records read.\n",records);

        //     for (i =0; i< records +1; i++ ) {
        //     printf ("%s %s %d\n", fitness_data[i].date,
        //                         fitness_data[i].time,
        //                         fitness_data[i].steps);
        //     }
            


        // return 0;

        };

       
       






    
