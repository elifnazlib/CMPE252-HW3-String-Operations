#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void removeDupWithoutSort(char names[][40], float duration[][1], int n);
void lastFirst(char name[][40], int n);
char* string_toupper(char *str);
int string_greater(const char *str1, const char *str2);
void selectionSort(char arr[][40], int n, float duration[][1]);


int main() {

    printf("Enter the input file name: \n");
    char fileName[20];
    scanf("%s", fileName);
    FILE *fptr1;            // for getting the count of lines in the file.
    FILE *fptr2;            // for reading the file.
    int lineCount = 0;      // number of lines (except the first line) in a file.
    char ch;                // char used to find the number of lines.

    char temp1[100];
    char temp2[100];

    // number of lines in the file (except the first line).

    fptr1 = fopen(fileName, "r");
    fgets(temp1, 100, fptr1);

    for (ch = getc(fptr1); ch != EOF; ch = getc(fptr1))
        // Increment count if this character is newline
        if (ch == '\n')
            lineCount = lineCount + 1;

    fclose(fptr1);

    // ------------------------------------

    char *arr1, *arr2, *arr3, *arr4, *arr5;
    fptr2 = fopen(fileName, "r");

    // first line
    if (fgets(temp2, 100, fptr2) != NULL) {
        arr1 = strtok(temp2, ",");
        arr2 = strtok(NULL, ",");
        arr3 = strtok(NULL, ",");
        arr4 = strtok(NULL, ",");
        arr5 = strtok(NULL, ",");
    }

    // 2D arrays for storing each property
    char joinTimes [lineCount][20];
    char leaveTimes [lineCount][20];
    float durations [lineCount][1];
    char names [lineCount][40];
    char emails [lineCount][40];

    char lastName[40];
    char firstName[40];

    char *tempArr;
    char tempCpy[100];

    // storing each property in 2D arrays, line by line
    for (int i = 0; i < lineCount; i++) {
        if (fgets(temp2, 100, fptr2) != NULL) {
            tempArr = strtok(temp2, ",");
            strcpy(tempCpy, tempArr);
            for (int k = 0; k < strlen(tempCpy); k++) {
                joinTimes[i][k] = tempCpy[k];
            }
            joinTimes[i][strlen(tempCpy)] = '\0';

            // ------------------------------------

            tempArr = strtok(NULL, ",");
            strcpy(tempCpy, tempArr);
            for (int k = 0; k < strlen(tempCpy); k++) {
                leaveTimes[i][k] = tempCpy[k];
            }
            leaveTimes[i][strlen(tempCpy)] = '\0';

            // ------------------------------------

            tempArr = strtok(NULL, ",");
            strcpy(tempCpy, tempArr);
            durations[i][0] = atof(tempCpy);

            // ------------------------------------

            tempArr = strtok(NULL, ",");
            strcpy(tempCpy, tempArr);
            for (int k = 0; k < strlen(tempCpy); k++) {
                names[i][k] = tempCpy[k];
            }
            names[i][strlen(tempCpy)] = '\0';

            // ------------------------------------

            tempArr = strtok(NULL, ",");
            strcpy(tempCpy, tempArr);
            for (int k = 0; k < strlen(tempCpy); k++) {
                emails[i][k] = tempCpy[k];
            }
            emails[i][strlen(tempCpy)] = '\0';

            // ------------------------------------
        }
    }

    fclose(fptr2);

    char answer[5];
    printf("Sort the results? (yes/no): \n");
    scanf ("%s", answer);

    lastFirst(names, lineCount);

    if (strcmp(answer, "yes") == 0) {
        selectionSort(names, lineCount, durations);
        removeDupWithoutSort(names, durations, lineCount);

    }
    else if (strcmp(answer, "no") == 0) {

        removeDupWithoutSort(names, durations, lineCount);

    }

    return 0;
}

void removeDupWithoutSort(char names[][40], float duration[][1], int n) {

    int found[n][1];
    for (int i = 0; i < n; i++) {
        found[i][0] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (found[i][0] == 1) {
            // Skip already printed students
            continue;
        }

        float totalTime = duration[i][0];
        for (int j = i+1; j < n; j++) {
            if (string_greater(names[i], names[j]) == 0) {
                totalTime = totalTime + duration[j][0];
                found[j][0] = 1;
            }
        }
        printf("%s %.2f\n", names[i], totalTime);
    }


}




void lastFirst(char name[][40], int n) {

    for (int i = 0; i < n; i++) {
        char lastName[40] = "";
        char firstName[40] = "";
        int count = 0;

        for (int j = 0; j < strlen(name[i]); j++) {
            if(isspace(name[i][j])) {
                count++;
            }

        }

        char *temp1;                    // for last name
        char *temp2;                    // for first names
        char tempName[40] = "";         // for first names
        temp2 = strtok(name[i], " ");   // for first names

        strcat(firstName,temp2);
        strcat(firstName," ");

        for (int k = 0; k < count-1; k++) {
            temp2 = strtok(NULL, " ");
            strcat(firstName,temp2);
            strcat(firstName," ");
        }

        firstName[strlen(firstName)-1] = '\0';
        temp1 = strtok(NULL, " ");     // for last name
        strcpy(lastName,temp1);


        strcat(tempName,lastName);
        strcat(tempName," ");
        strcat(tempName,firstName);

        strcpy(name[i],tempName);
    }
}

char* string_toupper(char *str) {
    int i;
    for (i = 0; i < strlen(str); ++i)
        if(islower(str[i]))
            str[i] = toupper(str[i]);

    return (str);
}

int string_greater(const char *str1, const char *str2) {
    char s1[40], s2[40];

    strcpy(s1, str1);
    strcpy(s2, str2);

    return (strcmp(string_toupper(s1), string_toupper(s2)));
}

void selectionSort(char arr[][40], int n, float duration[][1]) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    char minStr[40];
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        strcpy(minStr, arr[i]);
        for (j = i+1; j < n; j++)
        {
            // If min is greater than arr[j]
            if (string_greater(minStr, arr[j]) > 0)
            {
                // Make arr[j] as minStr and update min_idx
                strcpy(minStr, arr[j]);
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            char temp[40];
            strcpy(temp, arr[i]);           //swap item[pos] and item[i]
            strcpy(arr[i], arr[min_idx]);
            strcpy(arr[min_idx], temp);

            float tempDur;
            tempDur = duration[i][0];
            duration[i][0] = duration[min_idx][0];
            duration[min_idx][0] = tempDur;

        }
    }
}


