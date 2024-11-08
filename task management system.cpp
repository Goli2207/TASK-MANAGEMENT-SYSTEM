#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the Task
typedef struct Task {
    int id;                 // Task ID
    char description[100];  // Task Description
    int status;             // Task Status (0 = not completed, 1 = completed)
    int priority;           // Task Priority (1 = High, 2 = Medium, 3 = Low)
    struct Task* next;      // Pointer to the next task in the linked list
} Task;

// Function prototypes
void addTask(Task** head, int id, const char* description, int priority);
void deleteTask(Task** head, int id);
void updateTaskStatus(Task* head, int id, int status);
void displayTasks(Task* head);
void freeTasks(Task* head);

// Main function
int main() {
    Task* head = NULL;
    int choice, id, priority, status;
    char description[100];
    
    while(1) {
        printf("\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Update Task Status\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Add Task
                printf("Enter Task ID: ");
                scanf("%d", &id);
                getchar(); // To consume newline character left by scanf
                printf("Enter Task Description: ");
                fgets(description, 100, stdin);
                description[strcspn(description, "\n")] = '\0';  // Remove trailing newline
                printf("Enter Task Priority (1 = High, 2 = Medium, 3 = Low): ");
                scanf("%d", &priority);
                addTask(&head, id, description, priority);
                break;
                
            case 2:
                // Delete Task
                printf("Enter Task ID to delete: ");
                scanf("%d", &id);
                deleteTask(&head, id);
                break;
                
            case 3:
                // Update Task Status
                printf("Enter Task ID to update: ");
                scanf("%d", &id);
                printf("Enter Task Status (0 = Not Completed, 1 = Completed): ");
                scanf("%d", &status);
                updateTaskStatus(head, id, status);
                break;
                
            case 4:
                // Display all tasks
                displayTasks(head);
                break;
                
            case 5:
                // Exit
                freeTasks(head);
                printf("Exiting the program.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

// Function to add a new task to the linked list
void addTask(Task** head, int id, const char* description, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    if (!newTask) {
        printf("Memory allocation failed!\n");
        return;
    }
    newTask->id = id;
    strncpy(newTask->description, description, sizeof(newTask->description) - 1);
    newTask->description[sizeof(newTask->description) - 1] = '\0';
    newTask->status = 0; // New task is not completed
    newTask->priority = priority;
    newTask->next = *head;
    *head = newTask;
    printf("Task added successfully.\n");
}

// Function to delete a task by ID
void deleteTask(Task** head, int id) {
    Task* temp = *head;
    Task* prev = NULL;
    
    // If the task to delete is the head
    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Task with ID %d deleted successfully.\n", id);
        return;
    }
    
    // Search for the task to delete
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    // If task is not found
    if (temp == NULL) {
        printf("Task with ID %d not found!\n", id);
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("Task with ID %d deleted successfully.\n", id);
}

// Function to update task status by ID
void updateTaskStatus(Task* head, int id, int status) {
    Task* temp = head;
    
    // Search for the task
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    
    // If task is found, update status
    if (temp != NULL) {
        temp->status = status;
        printf("Task with ID %d status updated to %d.\n", id, status);
    } else {
        printf("Task with ID %d not found!\n", id);
    }
}

// Function to display all tasks
void displayTasks(Task* head) {
    Task* temp = head;
    if (temp == NULL) {
        printf("No tasks available.\n");
        return;
    }
    printf("\nTask ID\tDescription\t\tPriority\tStatus\n");
    printf("------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("%d\t%s\t\t%d\t\t%s\n", temp->id, temp->description, temp->priority, temp->status == 0 ? "Not Completed" : "Completed");
        temp = temp->next;
    }
}

// Function to free the allocated memory for tasks
void freeTasks(Task* head) {
    Task* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

