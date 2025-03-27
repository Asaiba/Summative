#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // <-- Include this for strchr()

#define MAX_STUDENTS 100
#define COURSE_COUNT 5
#define FILE_NAME "students_grades.txt"

// Define structure for student
typedef struct {
    char fullName[100];
    int grades[COURSE_COUNT];
} Student;

const char* courses[COURSE_COUNT] = {
    "Data Structures in C",
    "Mobile Application Development",
    "Programming in C#",
    "Machine Learning Techniques",
    "Introduction to Blockchain Development"
};

void saveToFile(Student students[], int n) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write header
    fprintf(file, "Full Name, Data Structures in C, Mobile App Dev, Programming in C#, Machine Learning, Blockchain\n");

    // Write student data
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s", students[i].fullName);
        for (int j = 0; j < COURSE_COUNT; j++) {
            fprintf(file, ", %d", students[i].grades[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Data successfully saved to %s\n", FILE_NAME);
}

int main() {
    int n;
    
    // Get number of students
    do {
        printf("Enter number of students (6-99): ");
        scanf("%d", &n);
        if (n <= 5 || n >= 100) {
            printf("Invalid number! Please enter between 6 and 99.\n");
        }
    } while (n <= 5 || n >= 100);
    
    Student students[MAX_STUDENTS];

    // Get student details
    for (int i = 0; i < n; i++) {
        printf("\nEnter full name of student %d: ", i + 1);
        getchar(); // To clear newline from previous input
        fgets(students[i].fullName, sizeof(students[i].fullName), stdin);
        
        // Remove newline character if present
        char *pos;
        if ((pos = strchr(students[i].fullName, '\n')) != NULL) {
            *pos = '\0';
        }

        // Get grades for each course
        for (int j = 0; j < COURSE_COUNT; j++) {
            do {
                printf("Enter grade for %s (0-100): ", courses[j]);
                scanf("%d", &students[i].grades[j]);

                if (students[i].grades[j] < 0 || students[i].grades[j] > 100) {
                    printf("Invalid grade! Must be between 0 and 100.\n");
                }
            } while (students[i].grades[j] < 0 || students[i].grades[j] > 100);
        }
    }

    // Save data to file
    saveToFile(students, n);

    return 0;
}
