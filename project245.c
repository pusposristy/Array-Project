#include <stdio.h>

int arr[200];
int size = 0;

void insert() {
    if (size >= 200) {
        printf("Array is full!\n");
        return;
    }
    int pos, value;
    printf("Enter position to insert (1 to %d): ", size + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter the new value: ");
    scanf("%d", &value);
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    size++;
    printf("Data inserted successfully!\n");
}

void update() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    int pos, value;
    printf("Enter position to update (1 to %d): ", size);
    scanf("%d", &pos);
    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &value);
    arr[pos - 1] = value;
    printf("Data updated successfully!\n");
}

void deleteElement() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    int pos;
    printf("Enter position to delete (1 to %d): ", size);
    scanf("%d", &pos);
    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Data deleted successfully!\n");
}

void display() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    int value, pos = -1;
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            pos = i + 1;
            break;
        }
    }
    if (pos == -1) {
        printf("Value not found!\n");
    } else {
        printf("The value is found at position %d\n", pos);
    }
}

void sort() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully!\n");
}

int main() {
    int choice;
    printf("Enter number of initial elements: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n1. Insert\n2. Update\n3. Delete\n4. Display\n5. Search\n6. Sort\n7. Exit\n");
        printf("Enter operation number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                update();
                break;
            case 3:
                deleteElement();
                break;
            case 4:
                display();
                break;
            case 5:
                search();
                break;
            case 6:
                sort();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid operation!\n");
        }
    } while (choice != 7);

    return 0;
}
