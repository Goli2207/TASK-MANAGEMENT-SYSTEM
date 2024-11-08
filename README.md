This implementation provides a basic task management system that can be extended to include additional features like sorting, searching, and persistent storage. It demonstrates the use of linked lists for dynamic task management and simple user interaction in C.

Data Structures to Use:
•	Linked List: To store tasks dynamically, allowing easy insertion and deletion.
•	Stacks: For undo/redo functionality (optional).
•	Queues: For tasks with deadlines or due dates that should be processed in order.
•	Binary Search Tree (BST): For efficient searching and sorting of tasks by priority or due date.
•	Arrays: For simple task lists (if no complex operations are needed).

Overview:
This project is designed to manage tasks, which might represent projects, activities, or assignments. The goal is to help users organize and track tasks efficiently by providing basic functionalities such as adding, deleting, updating, displaying, and searching for tasks.

Core Concepts:
The project will use linked lists to manage tasks dynamically, as this allows us to easily add and remove tasks without having to predefine the maximum number of tasks. Each task will contain important information such as:
•	ID: A unique identifier for the task.
•	Title: A short name for the task.
•	Description: A detailed explanation of the task.
•	Priority: Indicates how urgent the task is (e.g., high, medium, or low).
•	Status: The current state of the task (e.g., "Pending", "Completed").
•	Due Date: A deadline for the task.
