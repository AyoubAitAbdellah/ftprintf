*This project has been created as part of the 42 curriculum by aait-abd.*

# ft_printf

## Description

The **ft_printf** project consists of recoding the standard C library function `printf()`.

The objective is to understand variadic functions in C and learn how formatted output works by implementing a simplified version of `printf()`.

The project produces a static library named `libftprintf.a`, containing the function:

```c
int ft_printf(const char *format, ...);
```

The implementation reproduces the behavior of the original `printf()` for the following mandatory conversions:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |
| `%%` | Prints the percent character. |

The implementation focuses on format parsing, argument handling, character output, and return-value calculation.

The original `printf()` buffer management is not required by the project.

## Instructions

### Compilation

The library is compiled using the provided Makefile.

Run:

```bash
make
```

This generates:

```text
libftprintf.a
```

### Makefile commands

| Command | Description |
|---|---|
| `make` | Compiles the source files and creates the library. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the compiled library. |
| `make re` | Recompiles the library from scratch. |

### Using the library

Include the header file in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the static library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    int number;

    number = 42;
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d\n", number);
    ft_printf("Hexadecimal: %x\n", number);
    return (0);
}
```

## Algorithm and Implementation

### 1. Format parsing

The main function, `ft_printf()`, receives a format string and a variable number of arguments.

The format string is processed character by character.

- If the current character is not `%`, it is printed directly.
- If the current character is `%`, the next character is interpreted as a conversion specifier.
- The conversion specifier is passed to `ft_find_format()`.

The function `ft_format_process()` handles the parsing loop, printing operations, and character counting.

### 2. Conversion identification and argument retrieval

The function `ft_find_format()` identifies the conversion specifier and retrieves the corresponding argument using `va_arg()`.

Each conversion uses the appropriate argument type:

- `int` for `%d` and `%i`.
- `unsigned int` for `%u`, `%x`, and `%X`.
- `void *` for `%p`.
- `char *` for `%s`.
- `int` for `%c`, due to default argument promotions.

The `%%` conversion does not retrieve an argument because it simply prints a percent character.

### 3. Decimal number handling

The functions `ft_print_numbers()` and `ft_print_unsigned()` handle signed and unsigned decimal integers.

The number is printed recursively by extracting its digits.

For signed integers, negative values are handled by printing the minus sign first. The value is converted to `long` before negation to safely handle the minimum integer value.

For unsigned integers, the digits are extracted without handling a negative sign.

### 4. Hexadecimal conversion

The function `ft_print_hex()` handles hexadecimal output.

It uses a digit table containing hexadecimal characters:

- Lowercase characters for `%x`.
- Uppercase characters for `%X`.

The number is divided by 16 recursively until the most significant digit is reached. The digits are then printed in the correct order.

### 5. Pointer conversion

The function `ft_print_pointers()` handles pointer addresses.

The pointer is converted to `unsigned long` and printed in hexadecimal format with the `0x` prefix.

A NULL pointer is handled separately.

### 6. Return-value calculation

The return value of `ft_printf()` represents the total number of characters successfully printed.

Each conversion function returns the number of characters it prints.

The main processing function adds these values together while processing the format string.

If a write operation fails, the printing functions return `-1`. This error is propagated through the conversion handler and the format-processing function until it reaches `ft_printf()`.

### 7. Code organization

The project is divided into several source files, each responsible for a specific task:

| File | Responsibility |
|---|---|
| `ft_printf.c` | Main function and format-processing loop. |
| `ft_find_format.c` | Identifies conversion specifiers and retrieves arguments. |
| `ft_print_char.c` | Prints a single character. |
| `ft_print_strings.c` | Prints strings. |
| `ft_print_numbers.c` | Prints signed decimal integers. |
| `ft_print_unsigned.c` | Prints unsigned decimal integers. |
| `ft_print_hex.c` | Prints hexadecimal numbers. |
| `ft_print_pointers.c` | Prints pointer addresses. |
| `ft_printf.h` | Contains function prototypes and required headers. |

## Resources

The following resources were used to understand the concepts involved in this project:

- The official 42 ft_printf subject.
- `man printf` for understanding the behavior of the standard function.
- `man 3 stdarg` for variadic functions.
- `man 2 write` for output operations.
- [cppreference](https://en.cppreference.com/w/c/io/fprintf) for C output documentation.

## AI Usage

AI tools were used as supplementary learning and development resources during this project.

The following tasks involved AI assistance:

- **Understanding concepts:** Explanations of variadic functions, `va_list`, `va_arg`, pointers, integer types, and hexadecimal conversion.
- **Code review:** Reviewing individual functions to identify logical errors, edge cases, and error-handling issues.
- **Documentation:** Assistance with structuring and drafting this README.

AI assistance was used as a learning and review tool.
