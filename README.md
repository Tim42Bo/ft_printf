# ft_printf

**ft_printf** is a custom implementation of the C library function `printf`. It provides a powerful and flexible way to format and print output to the standard output stream or a character array.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Supported Format Specifiers](#supported-format-specifiers)
- [Examples](#examples)

## Features

- Supports a wide range of format specifiers, including `%d`, `%s`, `%c`, `%f`, `%x`, and more.
- Handles various flags, width, precision, and length modifiers to customize output formatting.
- Provides error handling and returns the number of characters written.

## Usage

1. Clone the repository:

   git clone https://github.com/Tim42Bo/ft_printf.git
   
2. Include the "ft_printf" function in your project:
   #include "ft_printf.h"
   
3. If you want to compile it with your libft implement following in your MAKEFILE
   gcc -Wall -Wextra -Werror -I includes/ -L . -lftprintf -o your_program main.c

## Supported Format Specifiers
%d, %i: Signed decimal integer.

%u: Unsigned decimal integer.

%x, %X: Unsigned hexadecimal integer (lowercase/uppercase).

%c: Character.

%s: String.

%p: Pointer address.

%f: Floating-point number.


For a complete list of supported format specifiers and their usage, please refer to the ft_printf.h header file.


## Examples:

#include "ft_printf.h"

int main(void)
{
    ft_printf("Integer: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("String: %s\n", "Hello, world!");
    return (0);
}

Contributing
Contributions to the ft_printf project are welcome! If you encounter any bugs, issues, or have suggestions for improvements, please feel free to open an issue or submit a pull request.

When contributing to this repository, please follow the existing coding style and keep your changes concise and well-documented.




