# Libft

This repository contains the implementation of the libft project, a fundamental project in the curriculum at 42 School. The libft project aims to create a library of essential C functions that can be used in various other projects throughout the 42 School curriculum.

## Project Description

The libft project requires you to create your own library of C functions, mimicking many of the standard library functions available in C, such as string manipulation, memory management, and more. The goal is to gain a deep understanding of these functions and their underlying mechanisms.

The project typically includes functions for tasks like string manipulation, memory allocation, and basic input/output operations. These functions are implemented from scratch and adhere to the C standard library specifications.

## Contents

The libft library typically includes functions categorized into several header files:

- `libft.h`: The main header file that includes prototypes for all the library functions.
- `libft.a`: The compiled library itself.
- `Makefile`: A makefile for easy compilation and management of the library.
- Additional header and source files for specific function categories (e.g., `ft_mem`, `ft_str`, `ft_lst`, etc.).

## Usage

To use the libft library in other 42 School projects, follow these steps:

1. Clone this repository or download the relevant files.
2. Compile the library using the provided `Makefile`. Run `make` in the project directory to build the `libft.a` library.
3. Link your project with the `libft.a` library during compilation.
4. Include the appropriate header files (e.g., `libft.h`) in your project source code.
5. Use the library functions as needed in your project.

## Project Structure

The project is typically organized into directories, each containing functions related to a specific category, such as strings, memory, linked lists, and more. The header files provide function prototypes and definitions for these categories.

```plaintext
libft/
│
├── ft_mem/            # Memory manipulation functions
├── ft_str/            # String manipulation functions
├── ft_lst/            # Linked list functions
├── ...
│
├── libft.h            # Main library header file
├── libft.a            # Compiled library
├── Makefile           # Makefile for building the library
└── ...
```

## Documentation

For detailed information about each function in the libft library, refer to the comments within the source code. You can also find documentation on the specific functions and their usage in the 42 School documentation provided for the project.

## Contributions

Contributions to the libft project are welcome. If you find any issues, have suggestions for improvements, or want to add new functions to the library, you can create pull requests or discuss changes with the 42 School community.
