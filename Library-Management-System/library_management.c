#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 100

// Book structure
struct Book
{
    int id;
    char title[100];
    char author[100];
    int available;
};

// Member structure
struct Member
{
    int id;
    char name[100];
};

struct Book books[MAX_BOOKS];
struct Member members[MAX_MEMBERS];

int bookCount = 0;
int memberCount = 0;


// Add Book
void addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[bookCount].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[bookCount].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[bookCount].author);

    books[bookCount].available = 1;

    bookCount++;

    printf("\nBook added successfully!\n");
}


// Display Books
void displayBooks()
{
    if (bookCount == 0)
    {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n========== BOOK LIST ==========\n");

    for (int i = 0; i < bookCount; i++)
    {
        printf("\nBook ID: %d", books[i].id);
        printf("\nTitle: %s", books[i].title);
        printf("\nAuthor: %s", books[i].author);

        if (books[i].available == 1)
            printf("\nStatus: Available\n");
        else
            printf("\nStatus: Issued\n");
    }
}


// Search Book
void searchBook()
{
    int id;
    int found = 0;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            printf("\nBook Found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);

            if (books[i].available)
                printf("Status: Available\n");
            else
                printf("Status: Issued\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBook not found!\n");
}


// Add Member
void addMember()
{
    if (memberCount >= MAX_MEMBERS)
    {
        printf("\nMember limit reached!\n");
        return;
    }

    printf("\nEnter Member ID: ");
    scanf("%d", &members[memberCount].id);

    printf("Enter Member Name: ");
    scanf(" %[^\n]", members[memberCount].name);

    memberCount++;

    printf("\nMember added successfully!\n");
}


// Display Members
void displayMembers()
{
    if (memberCount == 0)
    {
        printf("\nNo members found.\n");
        return;
    }

    printf("\n========== MEMBER LIST ==========\n");

    for (int i = 0; i < memberCount; i++)
    {
        printf("\nMember ID: %d", members[i].id);
        printf("\nName: %s\n", members[i].name);
    }
}


// Issue Book
void issueBook()
{
    int id;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].available == 1)
            {
                books[i].available = 0;
                printf("\nBook issued successfully!\n");
            }
            else
            {
                printf("\nBook is already issued!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}


// Return Book
void returnBook()
{
    int id;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].available == 0)
            {
                books[i].available = 1;
                printf("\nBook returned successfully!\n");
            }
            else
            {
                printf("\nThis book was not issued.\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}


// Main
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n=================================");
        printf("\n     LIBRARY MANAGEMENT SYSTEM");
        printf("\n=================================");

        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Add Member");
        printf("\n5. Display Members");
        printf("\n6. Issue Book");
        printf("\n7. Return Book");
        printf("\n8. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                addMember();
                break;

            case 5:
                displayMembers();
                break;

            case 6:
                issueBook();
                break;

            case 7:
                returnBook();
                break;

            case 8:
                printf("\nThank you for using Library Management System!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}