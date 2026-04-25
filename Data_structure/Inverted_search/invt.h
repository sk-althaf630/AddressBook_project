#ifndef INVT_H
#define INVT_H
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
/* Return values */
#define SUCCESS 0
#define FAILURE 1
 
/* Hash table has 28 buckets: a-z (26), digits (1), special chars (1) */
#define TABLE_SIZE 28
 
/* Magic string written at the top of every saved backup file */
#define MAGIC_STRING "&&**"
 
/* Sub-node: stores one file where the word was found */
typedef struct sub_node
{
    int w_count;           /* How many times the word appears in this file */
    char *f_name;          /* Name of the file */
    struct sub_node *link; /* Pointer to next sub-node (next file) */
} s_node;
 
/* Main-node: stores one unique word and its list of files */
typedef struct main_node
{
    char *word;             /* The word string */
    int f_count;            /* Number of files containing this word */
    s_node *s_link;         /* Pointer to first sub-node (file list) */
    struct main_node *m_link; /* Pointer to next main-node in the bucket */
} m_node;
 
/* Hash table array element: one bucket in the hash table */
typedef struct hash_arra
{
    int index;    /* Bucket index (0-27) */
    m_node *head; /* Pointer to first main-node in this bucket */
} ht_arr;
 
/* File list node: stores one input filename */
typedef struct f_list
{
    char *data;          /* Filename string */
    struct f_list *link; /* Pointer to next node */
} flist;
 
/* --- Core utility functions (invt.c) --- */
void insert_ht(ht_arr *table);                                  /* Initialize hash table */
int  validate_cla(int argc, char *argv[], flist **head_f_list); /* Check command-line args */
int  istextpresent(char *filename);                             /* Check if file exists and is non-empty */
int  insert_first(char *filename, flist **head_f_list);         /* Add filename to front of list */
void print_list(flist **head_f_list);                           /* Print the file list */
 
/* --- Database build functions (create_db.c) --- */
int create_db(ht_arr *ht_table, flist *head);                           /* Read files and build hash table */
int insert_word(ht_arr *ht_table, const char *word, const char *filename); /* Insert one word into hash table */
int index_find(const char ch);                                          /* Get bucket index for a character */
 
/* --- Display function (Display.c) --- */
void display_table(ht_arr *table); /* Print full hash table to screen */
 
/* --- Other feature functions --- */
int  search_db(ht_arr *ht_table);                        /* Search for a word in the hash table */
int  save_db(ht_arr *h_table);                           /* Save hash table to a backup file */
int  update_db(ht_arr *h_table);                         /* Load hash table from a backup file */
void validate_files(ht_arr *h_table, flist **head_f_list); /* Remove already-indexed files from list */
void delet_elemtent(flist **head_f_list, char *data);    /* Delete one node from file list */
 
#endif