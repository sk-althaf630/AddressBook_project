#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <string.h>

/* ------ ANSI colour codes --------------------------------------------------------------------------------------------------------------------------- */
#define RED   "\033[1;31m"
#define RESET "\033[0m"

/* ------ token_classifier.c ------------------------------------------------------------------------------------------------------------------------ */
int my_isalpha   (char ch);
int my_isalnum   (char ch);
int my_iskeyword (const char *word);

/* ------ token_handlers.c ------------------------------------------------------------------------------------------------------------------------------ */
void handle_preprocessor (FILE *fp, int *line);
void handle_word         (FILE *fp, int first_ch);
void handle_operator     (FILE *fp, int first_ch);
void handle_string       (FILE *fp, int *line);
void handle_number       (FILE *fp, int first_ch, int line);
void handle_char         (FILE *fp, int *line);
int  handle_comment      (FILE *fp, int *line);   /* returns 1 if comment consumed */

/* ------ file_parser.c --------------------------------------------------------------------------------------------------------------------------------------- */
void parse_file (FILE *fp);

#endif /* LEXER_H */