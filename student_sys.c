#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // For isalpha() function

// Student structt
struct Student {
    char name[50];
    char id[8];
    char gender;
    int academicYear;
    float gpa;
};

// Functionsss
void addStudent(struct Student students[], int *numStudents);
void removeStudent(struct Student students[], int *numStudents);
void retrieveStudentData(struct Student students[], int numStudents);
void updateStudentData(struct Student students[], int numStudents);

int main() {
    struct Student students[100];  // Assuming a maximum of 100 students
    int numStudents = 0;
    int choice;
//menuu
    do {
        printf("                                       <<<<<<<<<<Student Management System>>>>>>>>>>\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Retrieve Student's Data\n");
        printf("4. Update Student's Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {printf("Invalid input. Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                removeStudent(students, &numStudents);
                break;
            case 3:
                retrieveStudentData(students, numStudents);
                break;
            case 4:
                updateStudentData(students, numStudents);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
//add student function
void addStudent(struct Student students[], int *numStudents) {
    struct Student newStudent;

    // Input student name
    printf("Enter Student Name (First Last): ");
    if (scanf("%s", newStudent.name) != 1 || !isalpha(newStudent.name[0])) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Input student ID
    printf("Enter Student ID (7-digit unique number): ");
    if (scanf("%s", newStudent.id) != 1 || strlen(newStudent.id) != 7) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Input student gender
    printf("Enter Student Gender (M/F): ");
    if (scanf(" %c", &newStudent.gender) != 1 || (newStudent.gender != 'M' && newStudent.gender != 'F')) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Input academic year
    printf("Enter Academic Year (1-5): ");
    if (scanf("%d", &newStudent.academicYear) != 1 || newStudent.academicYear < 1 || newStudent.academicYear > 5) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Input GPA
    printf("Enter GPA (0.0-4.0): ");
    if (scanf("%f", &newStudent.gpa) != 1 || newStudent.gpa < 0.0 || newStudent.gpa > 4.0) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Add the new student to the array
    students[*numStudents] = newStudent;
    (*numStudents)++;

    printf("Student added successfully!\n");
}
//remove studen8t function
void removeStudent(struct Student students[], int *numStudents) {
    char removeID[8];
    int found = 0;

    // Input student ID to remove
    printf("Enter Student ID to remove: ");
    if (scanf("%s", removeID) != 1) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Search for the student with the given ID
    for (int i = 0; i < *numStudents; i++) {
        if (strcmp(students[i].id, removeID) == 0) {
            // Student found, remove from the array
            for (int j = i; j < *numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            (*numStudents)--;
            found = 1;
            printf("Operation Successful. Student removed.\n");
            break;
        }
    }

    if (!found) {
        printf("ID not found. No changes made.\n");
    }
}

void retrieveStudentData(struct Student students[], int numStudents) {
    int choice;

    printf("Choose retrieval option:\n");
    printf("1. Search by Name\n");
    printf("2. Search by ID\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    switch (choice) {
        case 1: {
    // Search by Name
    char searchName[50];
    int found = 0;

    // Input student name to search
    printf("Enter Student Name to retrieve: ");
    if (scanf("%s", searchName) != 1) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Convert the search name to lowercase for case-insensitive comparison
    for (int i = 0; searchName[i]; i++) {
        searchName[i] = tolower(searchName[i]);
    }

    // Search for the student with the given name
    for (int i = 0; i < numStudents; i++) {
        char lowercaseName[50];
        strcpy(lowercaseName, students[i].name);

        // Convert the student's name to lowercase for case-insensitive comparison
        for (int j = 0; lowercaseName[j]; j++) {
            lowercaseName[j] = tolower(lowercaseName[j]);
        }

        if (strcmp(lowercaseName, searchName) == 0) {
            // Student found, display data
            printf("Operation Successful. Student Data:\n");
            printf("Name: %s\n", students[i].name);
            printf("ID: %s\n", students[i].id);
            printf("Gender: %c\n", students[i].gender);
            printf("Academic Year: %d\n", students[i].academicYear);
            printf("GPA: %.2f\n", students[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid Name, Please Try Again!.\n");
    }
    break;
}

        case 2: {
            // Search by ID
            char searchID[8];
            int found = 0;

            // Input student ID to search
            printf("Enter Student ID to retrieve: ");
            if (scanf("%s", searchID) != 1) {
                printf("Invalid input. Please try again.\n");
                while (getchar() != '\n'); // Clear input buffer
                return;
            }

            // Search for the student with the given ID
            for (int i = 0; i < numStudents; i++) {
                if (strcmp(students[i].id, searchID) == 0) {
                    // Student found, display data
                    printf("Operation Successful. Student Data:\n");
                    printf("Name: %s\n", students[i].name);
                    printf("ID: %s\n", students[i].id);
                    printf("Gender: %c\n", students[i].gender);
                    printf("Academic Year: %d\n", students[i].academicYear);
                    printf("GPA: %.2f\n", students[i].gpa);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Invalid ID, Please Try Again!.\n");
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
    }
}

void updateStudentData(struct Student students[], int numStudents) {
    char updateID[8];
    int found = 0;

    // Input student ID to update
    printf("Enter Student ID to update: ");
    if (scanf("%s", updateID) != 1) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Search for the student with the given ID
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, updateID) == 0) {
            // Student found, provide update options
            int updateChoice;

            printf("Choose update option:\n");
            printf("1. Update Academic Year\n");
            printf("2. Update GPA\n");
            printf("Enter your choice: ");
            if (scanf("%d", &updateChoice) != 1) {
                printf("Invalid input. Please try again.\n");
                while (getchar() != '\n'); // Clear input buffer
                return;
            }

            switch (updateChoice) {
                case 1:
                    // Update Academic Year
                    printf("Enter new Academic Year: ");
                    if (scanf("%d", &students[i].academicYear) != 1) {
                        printf("Invalid input. Please try again.\n");
                        while (getchar() != '\n'); // Clear input buffer
                        return;
                    }
                    printf("Academic Year updated successfully!\n");
                    break;
                case 2:
                    // Update GPA
                    printf("Enter new GPA: ");
                    if (scanf("%f", &students[i].gpa) != 1) {
                        printf("Invalid input. Please try again.\n");
                        while (getchar() != '\n'); // Clear input buffer
                        return;
                    }
                    printf("GPA updated successfully!\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("ID not found. No changes made.\n");
}
}