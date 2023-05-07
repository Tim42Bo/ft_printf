#include "myprint.h"

int handle_string(va_list args)
{
    char *str_arg = va_arg(args, char *);
    size_t str_len = strlen(str_arg);
    char *buffer = (char *)malloc((str_len + 1) * sizeof(char));
    if (!buffer)
        return -1;
    strncpy(buffer, str_arg, str_len);
    buffer[str_len] = '\0';
    int len = write(1, buffer, str_len);
    free(buffer);
    return len;
}