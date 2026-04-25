/*
 * token_handlers.c
 * ----------------
 * One handler per token category.  Each function is called AFTER
 * the first character of the token has already been read from fp.
 *
 *   handle_comment      --- single-line and block comments
 *   handle_preprocessor --- # directives / macros
 *   handle_word         --- keywords and identifiers
 *   handle_operator     --- all C operators (single- and multi-char)
 *   handle_string       --- "..." string literals
 *   handle_number       --- integer, float, and hex constants
 *   handle_char         --- '.' character constants
 */

#include "lexer.h"

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * handle_comment
 * Called after the first '/' has been read.
 * Returns 1 if a comment was consumed, 0 if not (caller handles /  or  /=).
 * ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
int handle_comment(FILE *fp, int *line)
{
    int next = fgetc(fp);

    /* ------ single-line  //  ------------------------------------------------------------------------------------------------------------------------ */
    if (next == '/')
    {
        char buf[512];
        int  i = 0, ch;

        while ((ch = fgetc(fp)) != EOF && ch != '\n')
            if (i < (int)sizeof(buf) - 1)
                buf[i++] = (char)ch;

        buf[i] = '\0';
        if (ch == '\n') (*line)++;

        printf("COMMENT (single-line) : //%s\n", buf);
        return 1;
    }

    /* ------ block comment (slash-star ... star-slash) ------ */
    if (next == '*')
    {
        int ch, prev = 0, start_line = *line;

        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '\n')      (*line)++;
            else if (prev == '*' && ch == '/')
            {
                printf("COMMENT (block) : /* ... */  (lines %d-%d)\n",
                       start_line, *line);
                return 1;
            }
            prev = ch;
        }

        printf(RED "ERROR at line %d: Unterminated block comment\n" RESET,
               start_line);
        return 1;
    }

    /* ------ not a comment: put the peeked char back ------------------------------------------------------ */
    if (next != EOF) ungetc(next, fp);
    return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * handle_preprocessor
 * Called after '#' has been read.
 * ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
void handle_preprocessor(FILE *fp, int *line)
{
    char buf[256];
    int  i = 0, start_line = *line, ch;

    buf[i++] = '#';

    while ((ch = fgetc(fp)) != EOF && ch != '\n')
    {
        /* handle line continuation:  #define FOO \<newline>bar  */
        if (ch == '\\')
        {
            int nx = fgetc(fp);
            if (nx == '\n') { (*line)++; if (i < (int)sizeof(buf)-1) buf[i++] = ' '; continue; }
            if (nx != EOF) ungetc(nx, fp);
        }
        if (i < (int)sizeof(buf) - 1)
            buf[i++] = (char)ch;
    }
    buf[i] = '\0';
    if (ch == '\n') (*line)++;

    printf("PREPROCESSOR / MACRO : %s  (line %d)\n", buf, start_line);
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * handle_word
 * Called after the first letter or '_' has been read (passed as first_ch).
 * ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
void handle_word(FILE *fp, int first_ch)
{
    char word[256];
    int  i = 0, ch = first_ch;

    word[i++] = (char)ch;

    while ((ch = fgetc(fp)) != EOF && (my_isalnum((char)ch) || ch == '_'))
        if (i < (int)sizeof(word) - 2)
            word[i++] = (char)ch;

    word[i] = '\0';
    if (ch != EOF) ungetc(ch, fp);

    if (my_iskeyword(word))
        printf("KEYWORD    : %s\n", word);
    else
        printf("IDENTIFIER : %s\n", word);
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * handle_operator
 * Called after an operator character has been read (passed as first_ch).
 * For '/', handle_comment() must be tried first in file_parser.c.
 * ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
void handle_operator(FILE *fp, int first_ch)
{
    char word[5];
    int  i = 0, next_ch;

    word[i++] = (char)first_ch;
    next_ch   = fgetc(fp);

    switch (first_ch)
    {
        case '+':   /* +  ++  +=  */
            if (next_ch == '+' || next_ch == '=') word[i++] = (char)next_ch;
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '-':   /* -  --  -=  ->  */
            if (next_ch == '-' || next_ch == '=' || next_ch == '>') word[i++] = (char)next_ch;
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '*':   /* *  *=  */
        case '%':   /* %  %=  */
            if (next_ch == '=') word[i++] = (char)next_ch;
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '/':   /* /  /=  (confirmed non-comment by caller) */
            if (next_ch == '=') word[i++] = (char)next_ch;
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '<':   /* <  <=  <<  <<=  */
            if (next_ch == '=') { word[i++] = (char)next_ch; }
            else if (next_ch == '<')
            {
                word[i++] = (char)next_ch;
                int nx2 = fgetc(fp);
                if (nx2 == '=') word[i++] = (char)nx2;
                else if (nx2 != EOF) ungetc(nx2, fp);
            }
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '>':   /* >  >=  >>  >>=  */
            if (next_ch == '=') { word[i++] = (char)next_ch; }
            else if (next_ch == '>')
            {
                word[i++] = (char)next_ch;
                int nx2 = fgetc(fp);
                if (nx2 == '=') word[i++] = (char)nx2;
                else if (nx2 != EOF) ungetc(nx2, fp);
            }
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '=':   /* =  ==  */
        case '!':   /* !  !=  */
            if (next_ch == '=') word[i++] = (char)next_ch;
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '&':   /* &  &&  &=  */
            if (next_ch == '&' || next_ch == '=') word[i++] = (char)next_ch;
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '|':   /* |  ||  |=  */
            if (next_ch == '|' || next_ch == '=') word[i++] = (char)next_ch;
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '^':   /* ^  ^=  */
            if (next_ch == '=') word[i++] = (char)next_ch;
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        case '.':   /* .  ...  */
            if (next_ch == '.')
            {
                int nx2 = fgetc(fp);
                if (nx2 == '.') { word[i++] = '.'; word[i++] = '.'; }
                else
                {
                    if (nx2 != EOF) ungetc(nx2, fp);
                    ungetc(next_ch, fp);
                }
            }
            else if (next_ch != EOF) ungetc(next_ch, fp);
            break;

        default:    /* ~  ?  :  --- always single-char */
            if (next_ch != EOF) ungetc(next_ch, fp);
            break;
    }

    word[i] = '\0';
    printf("OPERATOR   : %s\n", word);
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * handle_string
 * Called after the opening '"' has been read.
 * FIX: escape sequences (e.g. \") no longer close the string early.
 * ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
void handle_string(FILE *fp, int *line)
{
    char buf[512];
    int  i = 0, closed = 0, start_line = *line, ch;

    buf[i++] = '"';

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n') { (*line)++; break; }   /* unterminated */

        /* consume escape sequence as a unit so \" does NOT close */
        if (ch == '\\')
        {
            int esc = fgetc(fp);
            if (esc == EOF) break;
            if (i < (int)sizeof(buf) - 3) { buf[i++] = '\\'; buf[i++] = (char)esc; }
            if (esc == '\n') (*line)++;
            continue;
        }

        if (i < (int)sizeof(buf) - 2) buf[i++] = (char)ch;

        if (ch == '"') { closed = 1; break; }
    }

    buf[i] = '\0';

    if (!closed)
        printf(RED "ERROR at line %d: Unterminated string literal : %s\n" RESET,
               start_line, buf);
    else
        printf("STRING LITERAL : %s\n", buf);
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * handle_number
 * Called after the first digit has been read (passed as first_ch).
 * Supports decimal, float (with optional f/F suffix), and 0x hex.
 * FIX: a second '.' is unget so it is not swallowed into the token.
 * ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
void handle_number(FILE *fp, int first_ch, int line)
{
    char num[128];
    int  i = 0, dot_count = 0, ch = first_ch;

    num[i++] = (char)ch;

    /* 0x / 0X  hex prefix */
    if (ch == '0')
    {
        int nx = fgetc(fp);
        if (nx == 'x' || nx == 'X')
        {
            num[i++] = (char)nx;
            while ((ch = fgetc(fp)) != EOF &&
                   ((ch >= '0' && ch <= '9') ||
                    (ch >= 'a' && ch <= 'f') ||
                    (ch >= 'A' && ch <= 'F')))
                if (i < (int)sizeof(num) - 2) num[i++] = (char)ch;
            if (ch != EOF) ungetc(ch, fp);
            num[i] = '\0';
            printf("NUMERIC CONSTANT (hex) : %s  (line %d)\n", num, line);
            return;
        }
        if (nx != EOF) ungetc(nx, fp);
    }

    /* decimal / float */
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= '0' && ch <= '9')
        {
            if (i < (int)sizeof(num) - 2) num[i++] = (char)ch;
        }
        else if (ch == '.' && dot_count == 0)
        {
            dot_count++;
            if (i < (int)sizeof(num) - 2) num[i++] = (char)ch;
        }
        else if (ch == '.' && dot_count > 0)
        {
            ungetc(ch, fp);   /* second dot is NOT part of this number */
            break;
        }
        else
        {
            /* optional float suffix */
            if (dot_count > 0 && (ch == 'f' || ch == 'F' || ch == 'l' || ch == 'L'))
            {
                if (i < (int)sizeof(num) - 2) num[i++] = (char)ch;
            }
            else
            {
                ungetc(ch, fp);
            }
            break;
        }
    }

    num[i] = '\0';
    printf("NUMERIC CONSTANT : %s  (line %d)\n", num, line);
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * handle_char
 * Called after the opening '\'' has been read.
 * FIX: '\'' (escaped quote) is now handled correctly via escape logic.
 * ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
void handle_char(FILE *fp, int *line)
{
    char word[16];
    int  i = 0, closed = 0, start_line = *line, ch;

    word[i++] = '\'';

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n') { (*line)++; break; }

        /* consume escape sequence as a unit */
        if (ch == '\\')
        {
            int esc = fgetc(fp);
            if (esc == EOF) break;
            if (i < (int)sizeof(word) - 3) { word[i++] = '\\'; word[i++] = (char)esc; }
            continue;
        }

        if (i < (int)sizeof(word) - 2) word[i++] = (char)ch;

        if (ch == '\'') { closed = 1; break; }
    }

    word[i] = '\0';

    if (!closed)
    {
        printf(RED "ERROR at line %d: Unterminated character constant -> %s\n" RESET,
               start_line, word);
        return;
    }

    /*
     * Valid forms:
     *   'a'   --- length 3
     *   '\n'  --- length 4  (word[1] == '\\')
     *   '\''  --- length 4  (word[1] == '\\')  --- fixed by escape handling above
     */
    int len = i;
    if (len == 3 || (len == 4 && word[1] == '\\'))
        printf("CHAR CONSTANT : %s\n", word);
    else
        printf(RED "ERROR at line %d: Invalid character constant -> %s\n" RESET,
               start_line, word);
}