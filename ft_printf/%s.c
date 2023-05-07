#include "myprint.h"

int handle_string(va_list args)
{
    char *arg = va_arg(args, char *);
    size_t len = strlen(arg);
    char *buffer = (char *)malloc((len + 1) * sizeof(char));
    if (!buffer)
        return -1;
    strncpy(buffer, arg, len);
    buffer[len] = '\0';
    int returnlen = write(1, buffer, len);
    free(buffer);
    return len;
}