#include "myprint.h"

int handle_pointer(void *ptr)
{
    uintptr_t addr = (uintptr_t)ptr;
    char hex_string[20];
    char *buffer;
    size_t str_len;
    int len;

    str_len = strlen(ft_ulltoa(addr, hex_string, 16)) + 2; // add 2 for "0x" prefix
    buffer = (char *)malloc((str_len + 1) * sizeof(char));
    if (!buffer)
        return -1;

    buffer[0] = '0';
    buffer[1] = 'x';
    strncpy(buffer + 2, hex_string, str_len - 2);
    buffer[str_len] = '\0';

    len = write(1, buffer, str_len);

    free(buffer);

    return len;
}
