# Libft

**Libft** is a custom implementation of various standard C library functions and additional utility functions to serve as a foundational library for future projects. This project is often one of the first steps in learning how to code effectively in C and understanding how libraries work.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
- [How to Use](#how-to-use)
- [Project Structure](#project-structure)
- [Functions Implemented](#functions-implemented)
- [Testing](#testing)
- [License](#license)

---

## Overview

The **Libft** project consists of reimplementing functions from the C standard library (`libc`), as well as creating additional utility functions for string manipulation, memory management, and working with linked lists. The goal is to build a strong understanding of how these functions operate under the hood and provide a robust library for future projects.

---

## Features

- Custom implementations of **standard library functions** such as `strlen`, `memcpy`, and `strchr`.
- Utility functions for:
  - String manipulation (e.g., `ft_strjoin`, `ft_substr`).
  - Memory management (e.g., `ft_calloc`, `ft_memmove`).
  - Number conversion (e.g., `ft_itoa`, `ft_atoi`).
- Support for **linked lists** with functions like `ft_lstnew`, `ft_lstadd_front`, and `ft_lstmap`.

---

## Getting Started

### Prerequisites

- A Unix-based system (Linux or macOS).
- A working C compiler (`gcc` or `clang`).
- Makefile support.

### Installation

1. Clone the repository:
	```bash
   git clone https://github.com/yourusername/libft.git
   cd libft

2. Compile the library:
	```bash
	make

3. This will generate the libft.a file, which you can link to your own projects.

---

## How to Use

To use the libft library in your projects:

1. Include the library header in your source files:
	```bash
	#include "libft.h"

2. Compile your program and link it with libft.a:
	```bash
	gcc -Wall -Wextra -Werror main.c -L. -lft -o my_program

3. Run your program:
	```bash
	./my_program


---

## Project Structure
	```bash
	libft/
	├── ft_atoi.c          # Convert string to integer
	├── ft_bzero.c         # Zero out memory
	├── ft_calloc.c        # Allocate memory and initialize to zero
	├── ft_isalpha.c       # Check if a character is alphabetic
	├── ft_lstnew.c        # Create a new linked list node
	├── ft_memcpy.c        # Copy memory area
	├── libft.h            # Header file containing all function prototypes
	├── Makefile           # Compilation rules for the library
	└── ...

---

## Functions Implemented
### Part 1: Libc Functions

- ft_strlen - Calculate the length of a string.
- ft_strchr - Locate a character in a string.
- ft_memcpy - Copy memory area.
- ft_strdup - Duplicate a string.

### Part 2: Additional Functions

- ft_substr - Extract a substring from a string.
- ft_strjoin - Concatenate two strings into a new one.
- ft_itoa - Convert an integer to a string.
- ft_split - Split a string into an array of substrings.

### Bonus: Linked List Functions (This project have no bonus yet)

- ft_lstnew - Create a new node.
- ft_lstadd_front - Add a node to the front of a list.
- ft_lstdelone - Delete a node and free its memory.
- ft_lstmap - Apply a function to each element of a list and create a new list.

---

## Testing

To test the library:

1. Use the provided main.c file or create your own.
2. Alternatively, you can use external testing frameworks like Francinette or LibftTester.
	```bash
	make test