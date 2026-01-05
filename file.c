#include <stdio.h>
#include <unistd.h> 
#include "file.h" 

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fp;   // Declare a file pointer (used to work with files)

    // Try to open the file "contacts.csv" in write mode ("w")
    // If fopen returns NULL, it means the file could not be opened
    if((fp = fopen("contacts.csv","w")) == NULL)
    {
        fprintf(stderr,"File is not Found\n");   // Print error message to standard error
        return;                                 // Exit the function
    } 

    // Loop through all contacts in the address book
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        // Write each contact's details (name, phone, email) into the file
        // Format: name,phone,email (comma separated values)
        fprintf(fp,"%s,%s,%s\n", 
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
    fclose(fp);

    // Show a simple progress bar effect while saving
    for(int i = 0; i <= 100; i++)
    {
        printf("Saving-------->%d\r", i);   // Print progress percentage on the same line
        fflush(stdout);                     // Force output to appear immediately
        usleep(5000);                       // Small delay (5000 microseconds = 0.005 seconds)
    }

    printf("\n Saved Successfully \n");     // Final confirmation message
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp;   // Declare a file pointer

    // Try to open the file "contacts.csv" in read mode ("r")
    // If fopen returns NULL, it means the file could not be opened
    if((fp = fopen("contacts.csv","r")) == NULL)
    {
        fprintf(stderr,"File is not Found\n");   // Print error message
        return;                                 // Exit the function
    }

    // Read each line from the file until end of file
    // fscanf reads data separated by commas into name, phone, and email
    // "%[^,]" means read until a comma, "%[^\n]" means read until newline
    while((fscanf(fp,"%[^,],%[^,],%[^\n] ",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email)) == 3)
    {
        // If fscanf successfully reads 3 values (name, phone, email), increase contact count
        addressBook->contactCount++;
    }
    fclose(fp);
}