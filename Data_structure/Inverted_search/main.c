/*
Name: Shaik.Althaf
Project: Inverted Search
Submission Date: 24/04/2026
Submission Time: 7:30PM
Description:--
This project implements an Inverted Search system using the C programming language.
It constructs an inverted index that maps words to the files in which they appear,
enabling fast and efficient keyword-based retrieval. The system supports operations
such as database creation, display, saving, searching, and updating, all managed
through hash tables and linked lists. This project demonstrates practical applications
of data structures, file handling, and string manipulation, making it valuable for
understanding indexing techniques, information retrieval, and the foundations of
search engine design.
*/


#include "invt.h"

int main(int argc, char *argv[])
{
    flist *head_f_list = NULL;   

    ht_arr h_table[TABLE_SIZE];
    insert_ht(h_table);

    int Cflag = 0; /* 1 = create_db has been called */
    int Uflag = 0; /* 1 = update_db has been called */

    /* Validate command-line arguments and build file list */
    if(validate_cla(argc, argv, &head_f_list)== FAILURE)
    {
        printf("Entered argument is error\n");
        return FAILURE;
    }
    else
    {
        print_list(&head_f_list);  /* Show the loaded file names */
    }

    int choise;
    do{
        printf("1.create_db\n2.Display_db\n3.save_db\n4.search_db\n5.update_db\n6.Exit...\n");

        printf("Enter the choise : ");
        scanf("%d", &choise);

        switch(choise)
        {
            case 1:
               /* Build the word index from input files (only once) */
                if(Cflag == 0)
                {
                     /* If update was loaded before, remove already-indexed files */
                    if(Uflag == 1)
                    {
                        validate_files(h_table, &head_f_list);
                        print_list(&head_f_list);

                    }

                    if(create_db(h_table, head_f_list) == SUCCESS)
                    {
                        printf("Database created......\n");
                        Cflag = 1;
                    }
                }
                else
                {
                    printf("The create data base is only one time......\n");
                }
                break;
            
            case 2:
                /* Print the entire hash table */
                display_table(h_table);
                break;
            
            case 3:
                /* Save the hash table to a backup file */
                if(Cflag == 1)
                {
                  if(save_db(h_table) ==   SUCCESS)
                  {
                    printf("Save fuction is successfully done....\n");
                  }
                }
                else
                {
                   printf("ERROR : Before the create function save function not possible....\n");
                }
                break;
            
            case 4:
                 /* Search for a word in the hash table */
                if(search_db(h_table) == SUCCESS)
                {
                    printf("Searching Data base is don........\n");
                }
                break;

            case 5:
               /* Load a previously saved backup into the hash table */
                update_db(h_table);
                Uflag = 1;
                break;

            case 6:
                printf("Exiting for the program....\n");
                return SUCCESS;
            
            default:
                printf("Invalid inputes plz check..\n");
        }
        
    }while(choise != 6);
}