#include <stdio.h>

#define SIZE 100  // Maximum size of the array

void insert(int arr[], int *n, int pos, int value) 
{
    if (*n >= SIZE) 
	{
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }
    if (pos < 0 || pos > *n) 
	{
        printf("Invalid position! Position should be between 0 and %d.\n", *n);
        return;
    }
    
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos] = value;
    (*n)++;
    printf("Element inserted successfully!\n");
}

void delete(int arr[], int *n, int pos) 
{
    if (*n == 0) 
	{
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *n) 
	{
        printf("Invalid position! Position should be between 0 and %d.\n", *n - 1);
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*n)--;
    printf("Element deleted successfully!\n");
}

void display(int arr[], int n) 
{
    if (n == 0) 
	{
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[SIZE], n = 0, choice, pos, value;

    while (1) 
	{
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter position (0 to %d) and value: ", n);
                scanf("%d %d", &pos, &value);
                insert(arr, &n, pos, value);
                break;

            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;

            case 3:
                display(arr, n);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
