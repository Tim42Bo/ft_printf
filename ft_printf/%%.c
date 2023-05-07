#include "myprint.h"

int handle_percent()
{
    char c = '%';
    return write(1, &c, 1);
}