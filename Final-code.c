/***Code for storing and managing contact details using switch case in c***/
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char number[15];
    char email[50];
    char place[30];
};

struct Contact contacts[MAX];
int count = 0;

void addContact() {
    if (count >= MAX) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", contacts[count].name);
    printf("Enter Phone Number: ");
    scanf(" %[^\n]", contacts[count].number);
    printf("Enter Email: ");
    scanf(" %[^\n]", contacts[count].email);
    printf("Enter Place: ");
    scanf(" %[^\n]", contacts[count].place);

    count++;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("***All Contacts ***");
    for (int i = 0; i < count; i++) {
        printf("\nContact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].number);
        printf("Email: %s\n", contacts[i].email);
        printf("Place: %s\n", contacts[i].place);
    }
}

void updateContact() {
    char searchName[50];
    int found = 0;

    if (count == 0) {
        printf("No contacts to update.\n");
        return;
    }

    printf("Enter the name of the contact to update: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Enter new Phone Number: ");
            scanf(" %[^\n]", contacts[i].number);
            printf("Enter new Email: ");
            scanf(" %[^\n]", contacts[i].email);
            printf("Enter new Place: ");
            scanf(" %[^\n]", contacts[i].place);
            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found!\n");
}

void deleteContact() {
    char searchName[50];
    int found = 0;

    if (count == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found!\n");
}

int main() {
    int choice;

    do {
        printf("Contact Management System ");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: updateContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
