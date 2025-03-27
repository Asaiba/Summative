#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "employees.txt"

 int main() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading. Ensure data is stored first.\n");
        return 1;
    }

    printf("Employee Records:\n");
    printf("--------------------------------------------------\n");

    char email[100];
    int age;
    float salary;

    while (fscanf(file, "%[^,], %d, %f\n", email, &age, &salary) != EOF) {
        printf("Email: %s | Age: %d | Salary: %.2f\n", email, age, salary);
    }

    fclose(file);
    return 0;
}
