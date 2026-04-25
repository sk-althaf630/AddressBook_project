/*
 * token_classifier.c
 * ------------------
 * Utility functions that classify characters and words:
 *   my_isalpha    --- is the char a letter?
 *   my_isalnum    --- is the char a letter or digit?
 *   my_iskeyword  --- is the word a C keyword?
 */

#include "lexer.h"

/* ------ character tests --------------------------------------------------------------------------------------------------------------------------------- */

int my_isalpha(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int my_isalnum(char ch)
{
    return my_isalpha(ch) || (ch >= '0' && ch <= '9');
}

/* ------ keyword table --------------------------------------------------------------------------------------------------------------------------------------- */

int my_iskeyword(const char *word)
{
    static const char *keywords[] = {
        "int",      "char",     "float",    "double",
        "if",       "else",     "while",    "for",
        "return",   "void",     "break",    "continue",
        "struct",   "union",    "typedef",  "const",
        "static",   "extern",   "signed",   "unsigned",
        "long",     "short",    "sizeof",   "goto",
        "enum",     "switch",   "case",     "default",
        "do",       "auto",     "register", "volatile",
        "inline",   "restrict", "_Bool",    "_Complex",
        "NULL"
    };

    int n = (int)(sizeof(keywords) / sizeof(keywords[0]));
    for (int i = 0; i < n; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;

    return 0;
}