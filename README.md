*This project has been created as part of the 42 curriculum by junlim.*

# Libft

## Description

**Libft** is a custom C library that reimplements a set of standard C library
(`libc`) functions from scratch, along with several additional utility and
linked-list functions. The goal of the project is to build a solid
understanding of how these fundamental functions work internally, and to
produce a small, reusable toolbox (`libft.a`) that can be reused throughout
the rest of the 42 curriculum.

The library is split into three parts:

- **Part 1 — Libc functions**: Reimplementations of standard C functions each
  prefixed with `ft_`.
- **Part 2 — Additional functions**: Functions for string manipulation and file descriptors outputs.
- **Part 3 — Linked list**: A singly linked list with creation, insertion, iteration, mapping, and cleanup operations.

## Instructions

### Compilation

The project is built with a `Makefile` that respects the standard 42 rules
and compiles every `.c` file with `-Wall -Wextra -Werror`.

```bash
make        # compiles *.c files into *.o files, archived into libft.a
make clean  # removes *.o
make fclean # removes *.o then libft.a
make re     # recompile everything and creates libft.a
```

### Usage

Once compiled, `libft.a` can be linked against a .c file that has `main()`:

```bash
cc your_program.c -L. -lft -I. -o your_program
```

Include the header in your source files to access the prototypes:

```c
#include "libft.h"
```

## Library Overview

| Category | Functions |
|---|---|
| Character classification | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Memory (raw buffers) | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Allocation | `ft_calloc`, `ft_strdup` |
| String length & copy | `ft_strlen`, `ft_strlcpy`, `ft_strlcat` |
| String search & compare | `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` |
| Conversion | `ft_atoi`, `ft_itoa` |
| String manipulation | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri` |
| File descriptor output | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| Linked list | `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` |

## Resources

- [The Linux `man` pages](https://man7.org/linux/man-pages/) —
  reference for the prototypes and behavior of every reimplemented libc
  function.
- [Neso Academy's Introduction to linked list in C](https://www.youtube.com/watch?v=R9PTBwOzceo&list=PLpYOpjNLz0aGIL9xaFHbw16uEmFxzy2rs) — helps with understanding basic of linked list.
- [Makefile tutorial](https://makefiletutorial.com/#pattern-rules) —
 recompilation and clean up becomes an easier process when setting up or changes are made.

**Use of AI**:
- Review already-written implementations and point out issues or edge cases. Sparks discussion of trade-offs to have better understanding.
- Do README and summarized notes in the format of inline comments.