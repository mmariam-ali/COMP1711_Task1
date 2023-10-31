#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef unsigned long long int buffer_array;

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
    char buffer[buffer_size];


    

    /*read the csv file.  sort out buffer? */
    FILE *file = fopen("FitnessData_2023.csv", "r");
        if (file == NULL) {
            perror("File is empty\n");
            return 1;
        };
    
        while (fgets(buffer, buffer_size, file) != NULL) {          
            i =0;
            //buffer_array[b]= buffer;
            //printf("%s", buffer_array[b]);

            //strcpy(fitness_data, buffer);
            printf( "%s", buffer);
            //printf("%s %s %d", buffer.date, buffer.)
            printf("break");
            // strcpy(fitness_data[i], buffer);
        
            line_count++;
    
        };

    FITNESS_DATA fitness_data[line_count];

        while (fgets(buffer, buffer_size, file)!= NULL) {
            char *date [line_count]= {"%s", buffer.date};
            for (i =0; i< line_count +1; i++ ) {
            strcpy(fitness_data[i].date, date);
            strcpy(fitness_data[i].time, );
            strcpy(fitness_data[i].steps, );
            }
            i++;
        };

        // while (fgets(buffer, buffer_size, file) != NULL) {
        //     buffer_array[b]= itoa(buffer);
        //     b++;
        // }

        // for (b=0; b <line_count; b++) {
        //     printf("%s", itoa(buffer_array[b]));
        // }
    

        //number of records in file DONE
        printf("Number of records in file: %d", line_count);
        printf("\n");




//  while (fgets(buffer, buffer_size, file) != NULL) {
//             //printf( "%s", buffer);

            //
//         }



        // FITNESS_DATA fitness_data [] = {
        //     // {"%s", buffer}
        //     {"2023-09-01","07:30",300},
        //     {"2023-09-01","07:45",400},
        //     {"2023-09-01","08:00",600},
        // };

        
        





        
        // for ( int i =0; i < line_count; i++) {
        //         FITNESS_DATA fitness_data[] = {
        //             {"%s", buffer},
        //         //{"%s,%s,%d", fitness_data[i].date, fitness_data[i].time, fitness_data[i].steps},
        // };
        // }
        

        // for (i= 0; i <3; i++) {
        //     printf("%s/%s/%d", fitness_data[i].date, fitness_data[i].time, fitness_data[i].steps );
        //     printf("\n");
        // }

    
    

    


    fclose(file);
    return 0;

}

    
