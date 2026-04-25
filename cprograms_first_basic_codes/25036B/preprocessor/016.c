#include <stdio.h>
#line 200 "file.h"// by this macro we can modifiy the name_file and number_line
int main()
{
    printf("current file = %s\ncurrent line = %d\n", __FILE__, __LINE__);
}