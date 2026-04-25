/*
 * file_parser.c
 * -------------
 * Contains parse_file() --- the main lexer loop.
 * Reads one character at a time and dispatches to the
 * appropriate token handler in token_handlers.c.
 */

#include "lexer.h"

void parse_file(FILE *fp)
{
    int line = 1;
    int ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        /* ------ skip whitespace ------------------------------------------------------------------------------------------------------ */
        if (ch == '\n') { line++; continue; }
        if (ch == ' ' || ch == '\t' || ch == '\r') continue;

        /* ------ preprocessor directive --------------------------------------------------------------------------------- */
        if (ch == '#')
        {
            handle_preprocessor(fp, &line);
            continue;
        }

        /* ------ keyword or identifier ------------------------------------------------------------------------------------ */
        if (my_isalpha((char)ch) || ch == '_')
        {
            handle_word(fp, ch);
            continue;
        }

        /* ------ string literal --------------------------------------------------------------------------------------------------------- */
        if (ch == '"')
        {
            handle_string(fp, &line);
            continue;
        }

        /* ------ character constant --------------------------------------------------------------------------------------------- */
        if (ch == '\'')
        {
            handle_char(fp, &line);
            continue;
        }

        /* ------ numeric constant --------------------------------------------------------------------------------------------------- */
        if (ch >= '0' && ch <= '9')
        {
            handle_number(fp, ch, line);
            continue;
        }

        /* ------ punctuation symbols ------------------------------------------------------------------------------------------ */
        if (ch == ';' || ch == ',' ||
            ch == '(' || ch == ')' ||
            ch == '{' || ch == '}' ||
            ch == '[' || ch == ']')
        {
            printf("SYMBOL     : %c\n", ch);
            continue;
        }

        /*
         * ------ '/' : could be a comment (// or block) or operator (/ or /=) ------
         * Try comment first; if it returns 0 it wasn't a comment,
         * so fall through to operator handling.
         */
        if (ch == '/')
        {
            if (!handle_comment(fp, &line))
                handle_operator(fp, ch);
            continue;
        }

        /* ------ other operators ------------------------------------------------------------------------------------------------------ */
        if (ch == '+' || ch == '-' || ch == '*' || ch == '%' ||
            ch == '<' || ch == '>' || ch == '=' || ch == '!' ||
            ch == '&' || ch == '|' || ch == '^' || ch == '~' ||
            ch == '?' || ch == ':' || ch == '.')
        {
            handle_operator(fp, ch);
            continue;
        }

        /* ------ unknown symbol --------------------------------------------------------------------------------------------------------- */
        printf(RED "ERROR at line %d: Unknown symbol '%c'\n" RESET, line, ch);
    }
}