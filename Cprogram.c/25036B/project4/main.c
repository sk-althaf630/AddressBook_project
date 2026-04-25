/*
 * main.c
 * ------
 * Entry point.
 * Validates command-line arguments, checks the file extension,
 * opens the .c source file, delegates all parsing to parse_file(),
 * then closes the file.
 */

#include "lexer.h"

int main(int argc, char *argv[])
{
    /* ------ usage check ------------------------------------------------------------------------------------------------------------------------------ */
    if (argc != 2)
    {
        printf("Usage: %s <filename.c>\n", argv[0]);
        return 1;
    }

    /* ------ must end with .c --------------------------------------------------------------------------------------------------------------- */
    char *dot = strrchr(argv[1], '.');
    if (dot == NULL || strcmp(dot, ".c") != 0)
    {
        printf("Error: '%s' is not a .c file\n", argv[1]);
        return 1;
    }

    /* ------ open file ------------------------------------------------------------------------------------------------------------------------------------ */
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: cannot open '%s'\n", argv[1]);
        return 1;
    }

    /* ------ run the lexer ------------------------------------------------------------------------------------------------------------------------ */
    parse_file(fp);

    fclose(fp);
    return 0;
}