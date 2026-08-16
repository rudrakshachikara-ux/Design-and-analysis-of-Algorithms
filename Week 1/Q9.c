#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int totalCopies;
    int availableCopies;
};

struct Book books[MAX_BOOKS];
int count = 0;

void addBook() {
    if (count >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    printf("Enter Total Copies: ");
    scanf("%d", &books[count].totalCopies);

    books[count].availableCopies = books[count].totalCopies;

    count++;

    printf("Book added successfully.\n");
}

void searchBook() {
    int id, i, found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found!\n");
            printf("ID              : %d\n", books[i].id);
            printf("Title           : %s\n", books[i].title);
            printf("Author          : %s\n", books[i].author);
            printf("Total Copies    : %d\n", books[i].totalCopies);
            printf("Available Copies: %d\n", books[i].availableCopies);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");
}

void issueBook() {
    int id, i;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].availableCopies > 0) {
                books[i].availableCopies--;
                printf("Book issued successfully.\n");
            } else {
                printf("Book is currently unavailable.\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}

void returnBook() {
    int id, i;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].availableCopies < books[i].totalCopies) {
                books[i].availableCopies++;
                printf("Book returned successfully.\n");
            } else {
                printf("All copies are already available.\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}

void displayUnavailableBooks() {
    int i, found = 0;

    printf("\n========== UNAVAILABLE BOOKS ==========\n");

    for (i = 0; i < count; i++) {
        if (books[i].availableCopies == 0) {
            printf("\nID     : %d", books[i].id);
            printf("\nTitle  : %s", books[i].title);
            printf("\nAuthor : %s\n", books[i].author);

            found = 1;
        }
    }

    if (!found)
        printf("No books are currently unavailable.\n");
}

int main() {
    int choice;

    do {
        printf("\n\n========== LIBRARY MANAGEMENT ==========");
        printf("\n1. Add Book");
        printf("\n2. Search Book");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Display Unavailable Books");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                searchBook();
                break;

            case 3:
                issueBook();
                break;

            case 4:
                returnBook();
                break;

            case 5:
                displayUnavailableBooks();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
