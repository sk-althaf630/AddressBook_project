#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
#include <unistd.h>

void listContacts(AddressBook *addressBook)
{
    // Bubble sort algorithm: compares each pair of names and swaps if out of order
    for (int i = 0; i < addressBook->contactCount - 1; i++)
    {
        for (int j = 0; j < addressBook->contactCount - 1 - i; j++)
        {
            if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0)
            {
                // Swap contacts if name[j] > name[j+1]
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
    printf("\n+-----+----------------------+-----------------+---------------------------+\n");
    printf("| %-3s | %-20s | %-15s | %-25s |\n", "No.", "Name", "Phone", "Email");
    printf("+-----+----------------------+-----------------+---------------------------+\n");

    // run a loop=> 0 to addressBook -> contactcount for display output
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %-3d | %-20s | %-15s | %-25s |\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
    printf("+-----+----------------------+-----------------+---------------------------+\n");
}
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
     loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

int valid_name(char *name)
{
    // Step1:-check first charater is alphabetic or not
    if (!isalpha(*name))
    {
        return 1;
    }
    name++;
    // run a loop for checking for NULL || Letters || spaces || dot
    while (*name != '\0')
    {
        if (isalpha(*name) || *name == ' ' || *name == '.')
        {
            name++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int valid_phone(AddressBook *addressBook, char *number)
{
    // Step1:- checking string have 10 digit or not
    if (strlen(number) != 10)
    {
        return 1;
    }
    // Step2:- Run a loop for check char by char
    for (int i = 0; number[i] != '\0'; i++)
    {
        // check given input is digit or not
        if (!isdigit(number[i]))
        {
            return 1;
        }
    }
    // Step3:- Run a loop for checking unique number or not
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, number) == 0)
        {
            printf("\n+---------------------------------------------+\n");
            printf("| WE FOUND SAME PHONE NUMBER IN  CONTACTS.... |\n");
            printf("+---------------------------------------------+\n");
            return 1;
        }
    }
    return 0;
}


int valid_email(AddressBook *addressBook, char *email)
{
    // Step1:-Finding @ by using strchar
    // Declareing char pointer for return value
    char *at_pos = strchr(email, '@');
    if (at_pos == NULL || strchr(at_pos + 1, '@') != NULL)
    {
        return 1;
    }
    // Step2:-Finding .com  by using strstr
    // Declareing char pointer for return value
    char *dotcom = strstr(at_pos, ".com");
    if (dotcom == NULL || strcmp(dotcom, ".com") != 0)
    {
        return 1;
    }

    //strp 3:- Validate local part (before '@')
    int at_index = at_pos - email;
    
    //cannot start with '.'
    if(email[0] == '.')
    {
        return 1;
    }

    //cannot end with '.'
    if(at_index > 0 && email[at_index - 1] == '.')
    {
        return 1;
    }

    //cannot contain consecutive ".."
    if(strstr(email, "..") != NULL)
    {
        return 1;
    }
    // step4:- Runing a loop for the chacking lower cases
    for (int i = 0; email[i]; i++)
    {
        if (isalpha(email[i]) && !islower(email[i]))
        {
            return 1;
        }
    }
    // Step5:- Run a loop for checking unique email or not
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].email, email) == 0)
        {
            printf("\n+---------------------------------------------+\n");
            printf("|     WE FOUND SAME EMAIL IN  CONTACTS....    |\n");
            printf("+---------------------------------------------+\n");
            return 1;
        }
    }
    return 0;
}


void createContact(AddressBook *addressBook)
{
    // Define the logic to create a contacts
    printf("\n+-----------------------------------------+\n");
    printf("|           CREATE NEW CONTACT            |\n");
    printf("+-----------------------------------------+\n");

    char new_name[50];      // Variable to store the new contact's name
    char new_number[50];    // Variable to store the new contact's phone number
    char new_email[50];     // Variable to store the new contact's email

    while (1)  // Keep asking until the user enters a valid name
    {
        printf("Enter the Name: ");
        scanf(" %[^\n]", new_name);
        // Call helper function valid_name() to check if the name is valid
        // If it returns 1, the name is invalid
        if (valid_name(new_name) == 1)
        {
            printf("\n+-----------------------------------------+\n");
            printf("| ERROR : Entered name is INVALID         |\n");
            printf("+-----------------------------------------+\n");
            continue;  // Go back and ask again
        }
        break;   // Exit the loop if the email is valid
    }

    while (1)
    {
        printf("Enter the Phone Number: ");
        scanf(" %[^\n]", new_number);
        // Call helper function valid_phone() to check if the number is valid
        // If it returns 1, the number is invalid
        if (valid_phone(addressBook, new_number) == 1)
        {
            printf("\n+-----------------------------------------+\n");
            printf("| ERROR : Entered number is INVALID       |\n");
            printf("+-----------------------------------------+\n");
            continue;
        }
        break;
    }

    while (1)
    {
        printf("Enter the Email: ");
        scanf(" %[^\n]", new_email);
        // Call helper function valid_email() to check if the email is valid
        // If it returns 1, the email is invalid
        if (valid_email(addressBook, new_email) == 1)
        {
            printf("\n+-----------------------------------------+\n");
            printf("| ERROR : Entered email is INVALID        |\n");
            printf("+-----------------------------------------+\n");
            continue;
        }
        break;
    }

    // Copy the validated name, phone, and email into the address book
    strcpy(addressBook->contacts[addressBook->contactCount].name, new_name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, new_number);
    strcpy(addressBook->contacts[addressBook->contactCount].email, new_email);

   // Increase the total number of contacts by 1
    addressBook->contactCount++;

    // Show a simple "Saving" progress animation
    for (int i = 0; i <= 100; i++)
    {
        printf("Saving-------->%d\r", i);   // Print progress percentage on the same line
        fflush(stdout);                     // Force the output to appear immediately
        usleep(5000);                       // Small delay (5000 microseconds = 0.005 seconds)
    }

    printf("\n+-----------------------------------------+\n");
    printf("|   Contact stored successfully!          |\n");
    printf("+-----------------------------------------+\n");
}
void searchContact(AddressBook *addressBook)
{
    int choice;             // Variable to store user's menu choice (1–4)
    int flag = 0;           // Flag to check if a contact was found (0 = not found, 1 = found)
    char str_name[20];      // This is a string Buffer to hold name input
    char str_number[20];    // This is a string Buffer to hold phone input
    char str_email[20];     // This is a string Buffer to hold email input

    // Show the delete menu to the user.
    printf("\n+---------------------------------------------+\n");
    printf("|             SEARCH CONTACT MENU             |\n");
    printf("+---------------------------------------------+\n");
    printf("|1.   Search By Name                          |\n");
    printf("|2.   Search By Number                        |\n");
    printf("|3.   Search By Email                         |\n");
    printf("|4.   Exit                                    |\n");
    printf("+---------------------------------------------+\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();                    //Clear leftover newling character from input buffer.
    
    switch (choice)      //Decide what to do based on the user's choice.
    {
    case 1:
        printf("Enter the name: ");
        scanf(" %[^\n]", str_name);
        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");


        // Loop through all contacts in the contacts.csv file.
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            //strstr checks if 'str_name' is inside the contact's name
            if (strstr(addressBook->contacts[i].name, str_name) != NULL)
            {
                flag = 1;   // Mark as found
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                       i + 1,
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
            }
        }
        printf("+-----+----------------------+-----------------+---------------------------+\n");
        break;

    case 2:
        printf("Enter the number: ");
        scanf(" %[^\n]", str_number);
        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");
        
        // Loop through all contacts in the contacts.csv file.
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // strcmp checks if two strings are exactly equal
            if (strcmp(addressBook->contacts[i].phone, str_number) == 0)
            {
                flag = 1;   // Mark as found
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                       i + 1,
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
            }
        }

        break;

    case 3:
        printf("Enter the Email: ");
        scanf(" %[^\n]", str_email);
        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");
        
        // Loop through all contacts in the contacts.csv file.
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // strcmp checks if two strings are exactly equal
            if (strcmp(addressBook->contacts[i].email, str_email) == 0)
            {
                flag = 1;   // Mark as found
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                       i + 1,
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
            }
        }
        break;

    case 4:
        printf("\n+---------------------------------------------+\n");
        printf("| Exiting search...                           |\n");
        printf("+---------------------------------------------+\n");
        return;

    default:
        printf("\n+---------------------------------------------+\n");
        printf("| ERROR: Invalid choice. Please try again.    |\n");
        printf("+---------------------------------------------+\n");
        return;
    }
    if (flag == 0 && choice != 4)   // If no contact was found and user didn’t exit
    {
        printf("\n+---------------------------------------------+\n");
        printf("| Contact Not Found                           |\n");
        printf("+---------------------------------------------+\n");
    }
    for (int i = 0; i <= 100; i++)
    {
        printf("Saving-------->%d\r", i);
        fflush(stdout);
        usleep(5000);
    }

}
void editContact(AddressBook *addressBook)
{
    /* Define the logic for EditContact */
    int choice;            // This will store the user's menu choice (1–4)
    char str[100];        // This is a string buffer to hold the search input (like name, phone, or email).
    int dup_index[100];  // This array stores the positions (indexes) of contacts that match the search
    int count = 0;      // This keeps track of how many matches we found
    int num;           // This will store which match the user wants to delete (if multiple found)
    int index;

    // Show the delete menu to the user.
    printf("\n+---------------------------------------------+\n");
    printf("|             SEARCH CONTACT MENU             |\n");
    printf("+---------------------------------------------+\n");
    printf("|1.   Search By Name                          |\n");
    printf("|2.   Search By Number                        |\n");
    printf("|3.   Search By Email                         |\n");
    printf("|4.   Exit                                    |\n");
    printf("+---------------------------------------------+\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();                    //Clear leftover newling character from input buffer.

    //Decide what to do based on the user's choice.
    switch (choice)
    {
    case 1:
    {
        printf("Enter the name to Search: ");     
        scanf(" %[^\n]", str);                  
        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");
        
        // Loop through all contacts in the contacts.csv file.
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // strstr checks if 'str' is inside the contact's name
            if (strstr(addressBook->contacts[i].name, str) != NULL)
            {
                dup_index[count++] = i;           // Save index of match
                // Print matching contact details
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                                count,
                                addressBook->contacts[i].name,
                                addressBook->contacts[i].phone,
                                addressBook->contacts[i].email);
            }
        }

        // If no matches found
        if (count == 0)
        {
            printf("\n+---------------------------------------------+\n");
            printf("| Contact Not Found                           |\n");
            printf("+---------------------------------------------+\n");
            return;
        }
        printf("+-----+----------------------+-----------------+---------------------------+\n");

        int num;   // Variable to store which match user wants to edit
        printf("Enter the number of the contact to edit (1-%d): ", count);
        scanf("%d", &num);

        // Validate selection
        if (num < 1 || num > count)
        {
            printf("Invalid selection.\n");
            return;
        }

        index = dup_index[num - 1];   // Get actual index of chosen contact
        break;
    }

    case 2:   // Search by phone
    {
        printf("Enter the phone to Search: ");
        scanf(" %[^\n]", str);
        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");

        // Loop through all contacts in the contacts.csv file.
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // strcmp checks if phone numbers are exactly equal
            if (strcmp(addressBook->contacts[i].phone, str) == 0)
            {
                dup_index[count++] = i;           // Save index of match
                // Print contact details
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                                count,
                                addressBook->contacts[i].name,
                                addressBook->contacts[i].phone,
                                addressBook->contacts[i].email);
                break;   // Stop after first match
            }
        }

        if (count == 0)
        {
            printf("\n+---------------------------------------------+\n");
            printf("| Contact Not Found                           |\n");
            printf("+---------------------------------------------+\n");
            return;
        }
        printf("+-----+----------------------+-----------------+---------------------------+\n");

        index = dup_index[0];   // Only one match expected
        break;
    }

    case 3:
    {
        printf("Enter the Email to Search: ");
        scanf(" %[^\n]", str);
        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");

        // Loop through all contacts in the contacts.csv file.
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // strcmp checks if emails are exactly equal
            if (strcmp(addressBook->contacts[i].email, str) == 0)
            {
                dup_index[count++] = i;           // Save index of match
                // Print contact details
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                                count,
                                addressBook->contacts[i].name,
                                addressBook->contacts[i].phone,
                                addressBook->contacts[i].email);
                break;   // Stop after first match
            }
        }

        if (count == 0)
        {
            printf("\n+---------------------------------------------+\n");
            printf("| Contact Not Found                           |\n");
            printf("+---------------------------------------------+\n");
            return;
        }
        printf("+-----+----------------------+-----------------+---------------------------+\n");

        index = dup_index[0];   // Only one match expected
        break;
    }

    case 4:
        printf("\n+---------------------------------------------+\n");
        printf("| Exiting search...                           |\n");
        printf("+---------------------------------------------+\n");
        return;

    default:
        printf("\n+---------------------------------------------+\n");
        printf("| ERROR: Invalid choice. Please try again.    |\n");
        printf("+---------------------------------------------+\n");
        return;
    }

    int choice_edit;
    printf("\n+---------------------------------------------+\n");
    printf("|             EDIT CONTACT MENU               |\n");
    printf("+---------------------------------------------+\n");
    printf("|1.   Edit By Name                            |\n");
    printf("|2.   Edit By Number                          |\n");
    printf("|3.   Edit By Email                           |\n");
    printf("|4.   Exit                                    |\n");
    printf("+---------------------------------------------+\n");
    printf("Enter the choice: ");
    scanf("%d", &choice_edit);
    getchar();

    switch (choice_edit)
    {
    case 1:
    {
        char new_name[100];   // Buffer for new name
        while (1)
        {
            printf("Enter the Name: ");
            scanf(" %[^\n]", new_name);

            // Call helper function valid_name() to check validity
            if (valid_name(new_name) == 1)
            {
                printf("\n+-----------------------------------------+\n");
                printf("| ERROR : Entered name is INVALID         |\n");
                printf("+-----------------------------------------+\n");
                continue;   // Ask again
            }
            break;   // Exit loop if valid
        }
        strcpy(addressBook->contacts[index].name, new_name);   // Save new name
        break;
    }

    case 2:
    {
        char new_number[100];   // Buffer for new phone
        while (1)
        {
            printf("Enter the Number: ");
            scanf(" %[^\n]", new_number);

            // Here valid_name is incorrectly used; should be valid_phone
            if (valid_phone(addressBook, new_number) == 1)
            {
                printf("\n+-----------------------------------------+\n");
                printf("| ERROR : Entered number is INVALID       |\n");
                printf("+-----------------------------------------+\n");
                continue;
            }
            break;
        }
        strcpy(addressBook->contacts[index].phone, new_number);   // Save new phone
        break;
    }

    case 3:
    {
        char new_email[100];   // Buffer for new email
        while (1)
        {
            printf("Enter the Email: ");
            scanf(" %[^\n]", new_email);

            // Here valid_name is incorrectly used; should be valid_email
            if (valid_email(addressBook, new_email) == 1)
            {
                printf("\n+-----------------------------------------+\n");
                printf("| ERROR : Entered email is INVALID        |\n");
                printf("+-----------------------------------------+\n");
                continue;
            }
            break;
        }
        strcpy(addressBook->contacts[index].email, new_email);   // Save new email
        break;
    }

    case 4:
        printf("\n+---------------------------------------------+\n");
        printf("| Exiting Edit...                             |\n");
        printf("+---------------------------------------------+\n");
        break;

    default:
        printf("\n+---------------------------------------------+\n");
        printf("| ERROR: Invalid choice. Please try again.    |\n");
        printf("+---------------------------------------------+\n");
        return;
    }

    for (int i = 0; i <= 100; i++)
    {
        printf("Saving-------->%d\r", i);
        fflush(stdout);
        usleep(5000);
    }

    printf("\n+---------------------------------------------+\n");
    printf("| Contact edited successfully!                |\n");
    printf("+---------------------------------------------+\n");
}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
    int choice;            // This will store the user's menu choice (1–4)
    char str[100];        // This is a string buffer to hold the search input (like name, phone, or email).
    int dup_index[100];  // This array stores the positions (indexes) of contacts that match the search
    int count = 0;      // This keeps track of how many matches we found
    int num;           // This will store which match the user wants to delete (if multiple found)

    // Show the delete menu to the user.
    printf("\n+---------------------------------------------+\n");
    printf("|             DELETE CONTACT MENU             |\n");
    printf("+---------------------------------------------+\n");
    printf("|1. Delete By Name                            |\n");
    printf("|2. Delete By Number                          |\n");
    printf("|3. Delete By Email                           |\n");
    printf("|4. Exit                                      |\n");
    printf("+---------------------------------------------+\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();                    //Clear leftover newling character from input buffer.

    //Decide what to do based on the user's choice.
    switch (choice)
    {
    case 1:
        printf("Enter the name to search: ");
        scanf(" %[^\n]", str);

        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");
        // Loop through all contacts in the   0 to addressBook -> contacts.
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            //strstr checks if 'str' is inside the contact's name
            if (strstr(addressBook->contacts[i].name, str) != NULL)
            {
                dup_index[count++]= i;  // Save the index of the match contacts.
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                       count,
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
            }
        }
        printf("+-----+----------------------+-----------------+---------------------------+\n");
        // If more than one match, ask user which one to delete.
        if(count > 1)
        {
           printf("Enter the number of the contact to delete (1-%d): ", count);
           scanf("%d", &num);  // Read the user's selection.
           //Check if the selection is valid.
            if(num < 1 || num > count)
            {
                printf("Invalid selection.\n");
                return;
            }
        }
        else
        {
            num = 1;
        }
        break;

    case 2: // Delete by phone number.
        printf("Enter the phone to search: ");
        scanf(" %[^\n]", str);
        // Loop through all contacts in the contacts.csv file.
        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // strcmp checks if two strings are exactly equal
            if (strcmp(addressBook->contacts[i].phone, str) == 0)
            {
                dup_index[count++]= i;  // Save the index of the match contacts.
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                       count,
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
            }
        }
        printf("+-----+----------------------+-----------------+---------------------------+\n");
        num = 1;  // Phone numbers are usually unique, so auto-select
        break;

    case 3:
        printf("Enter the email to search: ");
        scanf(" %[^\n]", str);
        printf("\n+-----+----------------------+-----------------+---------------------------+\n");
        printf("| No. | Name                 | Phone           | Email                     |\n");
        printf("+-----+----------------------+-----------------+---------------------------+\n");

        // Loop through all contacts in the contacts.csv file.
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // strcmp checks if two strings are exactly equal
            if (strcmp(addressBook->contacts[i].email, str) == 0)
            {
                dup_index[count++]= i;  // Save the index of the match contacts.
                printf("| %-3d | %-20s | %-15s | %-25s |\n",
                       count,
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);

            }
        }
        printf("+-----+----------------------+-----------------+---------------------------+\n");
        num = 1;  // Emails are usually unique, so auto-select
        break;

    case 4:
        printf("\n+---------------------------------------------+\n");
        printf("| Exiting delete...                           |\n");
        printf("+---------------------------------------------+\n");
        return;

    default:
        printf("\n+---------------------------------------------+\n");
        printf("| ERROR: Invalid choice. Please try again.    |\n");
        printf("+---------------------------------------------+\n");
        return;
    }

    // If no matches were found
    if (count == 0)
    {
        printf("\n+---------------------------------------------+\n");
        printf("| ERROR: Contact Not Found                    |\n");
        printf("+---------------------------------------------+\n");
        return;
    }

    // Get the actual position in the contacts array
    int pos = dup_index[num - 1];
    char ch;  // Variable to store confirmation (y/n)

    // Ask the user if they really want to delete
    printf("Do you want to delete this contact? (y/n): ");
    scanf(" %c", &ch);  // Read a single character

    if (ch == 'y' || ch == 'Y')  // If user says yes
    {
        // Shift all contacts left to fill the gap
        for (int i = pos; i < addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        // Reduce the total number of contacts
        addressBook->contactCount--;
        for (int i = 0; i <= 100; i++)
        {
            printf("Processing-------->%d\r", i);
            fflush(stdout);
            usleep(5000);
        }

        printf("\n+---------------------------------------------+\n");
        printf("|   Contact deleted successfully!             |\n");
        printf("+---------------------------------------------+\n");
    }
    else 
    {
        for (int i = 0; i <= 100; i++)
        {
            printf("Processing-------->%d\r", i);
            fflush(stdout);
            usleep(5000);
        }

        printf("\n+---------------------------------------------+\n");
        printf("|   Delete cancelled.                         |\n");
        printf("+---------------------------------------------+\n");

    }
}