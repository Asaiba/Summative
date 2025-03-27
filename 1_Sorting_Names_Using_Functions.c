#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

void sortNames(char names[][50], int size, int (*compare)(const char *, const char *));
int ascending(const char *a, const char *b);
int descending(const char *a, const char *b);
int countNames(char names[][50], int size);
void executeSorting();
void executeCounting();


char studentNames[MAX_STUDENTS][50] = {
    "Alice Johnson", "Bob Smith", "Charlie Brown", "David Wilson", "Eve Adams"
};
int studentCount = 5;

int main() {
    // Array of function pointers
    void (*functions[2])() = {executeSorting, executeCounting};

    int choice;
    printf("Choose an option:\n");
    printf("1. Sort student names\n");
    printf("2. Count student names\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        functions[choice - 1]();
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

// Task 1: Sorting function with a callback
void sortNames(char names[][50], int size, int (*compare)(const char *, const char *)) {
    char temp[50];
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (compare(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

// Comparison functions for sorting
int ascending(const char *a, const char *b) {
    return strcmp(a, b);
}

int descending(const char *a, const char *b) {
    return strcmp(b, a);
}

// Function to execute sorting logic
void executeSorting() {
    char order[10];
    printf("Enter sorting order (asc for ascending, desc for descending): ");
    scanf("%s", order);

    if (strcmp(order, "asc") == 0) {
        sortNames(studentNames, studentCount, ascending);
    } else if (strcmp(order, "desc") == 0) {
        sortNames(studentNames, studentCount, descending);
    } else {
        printf("Invalid sorting order!\n");
        return;
    }

    printf("\nSorted student names:\n \n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\n", studentNames[i]);
    }
}

// Task 2: Counting function
int countNames(char names[][50], int size) {
    return size;
}

// Function to execute counting logic
void executeCounting() {
    printf("Total number of students: %d\n", countNames(studentNames, studentCount));
}
