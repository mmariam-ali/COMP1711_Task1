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

    int count = 0;
    char first_line;
    
    /*read the csv file.  sort out buffer? */
    FILE *file = fopen("FitnessData_2023.csv", "r");
        if (file ==NULL) {
            perror("File is empty ");
            return 1;
        }
    
        int buffer_size = 100;
        char buffer[buffer_size];
        while (fgets(buffer, buffer_size, file) != NULL) {
            printf( "%s", buffer);
            count++;
        }


        



        //number of records in file DONE
        printf("Number of records in file: %d", count);

// typedef struct {
// 	char date[11];
// 	char time[6];
// 	int steps;
// } FITNESS_DATA;


    /*store it in a suitable sized and structured array
    and type def data structure*/

    //

    first_line = fscanf(file, "\n", buffer);
    https://stackoverflow.com/questions/8917550/difference-between-fgets-and-fscanf
    printf("%s", first_line);
    //printf("%s", tokeniseRecord());






    fclose(file);




    return 0;


}
