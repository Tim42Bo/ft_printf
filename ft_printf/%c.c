#include "myprint.h"

int handle_char(va_list args)
{
    char c = (char) va_arg(args, int);
    char *buffer = (char *) malloc(2 * sizeof(char));
    if (!buffer)
        return -1;
    buffer[0] = c;
    buffer[1] = '\0';
    int len = write(1, buffer, 1);
    free(buffer);
    return len;
}
