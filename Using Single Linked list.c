#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student record
struct Student {
    char name[50];
    int rollNo;
    char course[20];
    int marks;
    struct Student *next;
};

struct Student *head = NULL; // Global head pointer

// Function to create a new student node
struct Student *createStudent(char name[], int rollNo, char course[], int marks) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newStudent->name, name);
    newStudent->rollNo = rollNo;
    strcpy(newStudent->course, course);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student record at the front of the list
void insertFront(char name[], int rollNo, char course[], int marks) {
    struct Student *newStudent = createStudent(name, rollNo, course, marks);
    if (head == NULL) {
        head = newStudent;
    } else {
        newStudent->next = head;
        head = newStudent;
    }
    printf("Record inserted at the front of the list.\n");
}

// Function to delete the last node of the list
void deleteLastNode() {
    if (head == NULL) {
        printf("List is empty. No record to delete.\n");
        return;
    }

    struct Student *current = head;
    struct Student *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        head = NULL;
    }

    free(current);
    printf("Last node deleted from the list.\n");
}

// Function to display the first student record
void showFirstRecord() {
    if (head == NULL) {
        printf("List is empty. No records to display.\n");
        return;
    }

    printf("First Student Record:\n");
    printf("Name: %s, Roll No.: %d, Course: %s, Marks: %d\n", head->name, head->rollNo, head->course, head->marks);
}

// Function to display all student records
void displayRecords() {
    if (head == NULL) {
        printf("List is empty. No records to display.\n");
        return;
    }

    struct Student *temp = head;
    printf("Student Records:\n");
    while (temp != NULL) {
        printf("Name: %s, Roll No.: %d, Course: %s, Marks: %d\n", temp->name, temp->rollNo, temp->course, temp->marks);
        temp = temp->next;
    }
}

// Function to search for a record at a specific position
void searchRecordAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. No records to search.\n");
        return;
    }

    struct Student *temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        printf("Record at position %d:\n", position);
        printf("Name: %s, Roll No.: %d, Course: %s, Marks: %d\n", temp->name, temp->rollNo, temp->course, temp->marks);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

// Function to update a record at a specific position
void updateRecord(int position, char name[], int rollNo, char course[], int marks) {
    if (head == NULL) {
        printf("List is empty. No records to update.\n");
        return;
    }

    struct Student *temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        strcpy(temp->name, name);
        temp->rollNo = rollNo;
        strcpy(temp->course, course);
        temp->marks = marks;
        printf("Record at position %d updated successfully.\n", position);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

int main() {
    int choice, rollNo, marks, position;
    char name[50], course[20];

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Insert record\n");
        printf("2. Delete record\n");
        printf("3. Show first record\n");
        printf("4. Search record\n");
        printf("5. Update record\n");
        printf("6. Display record\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter roll no.: ");
                scanf("%d", &rollNo);
                printf("Enter course (CSE, AIML, DS, IT, ECE): ");
                scanf("%s", course);
                printf("Enter marks: ");
                scanf("%d", &marks);
                insertFront(name, rollNo, course, marks);
                break;
            case 2:
                deleteLastNode();
                break;
            case 3:
                showFirstRecord();
                break;
            case 4:
                printf("Enter position to search: ");
                scanf("%d", &position);
                searchRecordAtPosition(position);
                break;
            case 5:
                printf("Enter position to update: ");
                scanf("%d", &position);
                printf("Enter new name: ");
                scanf("%s", name);
                printf("Enter new roll no.: ");
                scanf("%d", &rollNo);
                printf("Enter new course (CSE/AIML/DS/IT/ECE): ");
                scanf("%s", course);
                printf("Enter new marks: ");
                scanf("%d", &marks);
                updateRecord(position, name, rollNo, course, marks);
                break;
            case 6:
                displayRecords();
                break;
            case 7:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}
