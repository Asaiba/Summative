#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "employees.txt"
#define EMPLOYEE_COUNT 5

// Function to validate email (checks if '@' exists)
int isValidEmail(const char *email) {
    return (strchr(email, '@') != NULL);
}

// Function to validate age (18 to 65)
int isValidAge(int age) {
    return (age >= 18 && age <= 65);
}

// Function to validate salary (must be positive)
int isValidSalary(float salary) {
    return (salary > 0);
}

int main() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter details for %d employees:\n", EMPLOYEE_COUNT);

    for (int i = 0; i < EMPLOYEE_COUNT; i++) {
        char email[100];
        int age;
        float salary;

        // Input email with validation
        do {
            printf("Enter email for Employee %d: ", i + 1);
            scanf("%s", email);
            if (!isValidEmail(email)) {
                printf("Invalid email format! Try again.\n");
            }
        } while (!isValidEmail(email));

        // Input age with validation
        do {
            printf("Enter age for Employee %d (18-65): ", i + 1);
            scanf("%d", &age);
            if (!isValidAge(age)) {
                printf("Invalid age! Must be between 18 and 65.\n");
            }
        } while (!isValidAge(age));

        // Input salary with validation
        do {
            printf("Enter salary for Employee %d: ", i + 1);
            scanf("%f", &salary);
            if (!isValidSalary(salary)) {
                printf("Invalid salary! Must be a positive number.\n");
            }
        } while (!isValidSalary(salary));

        // Write data to file
        fprintf(file, "%s, %d, %.2f\n", email, age, salary);
    }

    fclose(file);
    printf("Employee details successfully saved to %s\n", FILE_NAME);
    return 0;
}
