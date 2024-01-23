# Get Next Line

The Get Next Line project is a function that reads a line from a file descriptor in C. It allows you to read text files and standard input, one line at a time, using repeated calls to the `get_next_line()` function.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Function Prototype](#function-prototype)
- [Return Value](#return-value)
- [Buffer Size](#buffer-size)
- [Compiling](#compiling)
- [Bonus Part](#bonus-part)

## Introduction

The Get Next Line function provides a convenient way to read lines from a file descriptor in C. It reads the file or standard input line by line, allowing you to process the input one line at a time.

## Usage

To use the Get Next Line function in your project, you need to include the `get_next_line.h` header file in your source code. The function prototype is as follows:

    char *get_next_line(int fd);
    
The fd parameter is the file descriptor from which you want to read the line. It can be a file descriptor for a file or the standard input (0).

## Function Prototype

The function prototype for Get Next Line is:

    char *get_next_line(int fd);

## Return Value

The Get Next Line function returns a line read from the file descriptor. It returns NULL if there is nothing else to read or if an error occurred.

The returned line includes the terminating newline character (\n) except when the end of file is reached and the line doesn't end with a newline character.

## Buffer Size

The buffer size for reading from the file descriptor can be defined using the -D BUFFER_SIZE=n flag when compiling your code. For example:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 <files>.c

The buffer size value can be modified by peer-evaluators and the grading system to test your code.

## Compiling

To compile your code with the Get Next Line function, you can use the following command:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 <files>.c

Make sure to replace <files>.c with your source code files.

## Bonus Part

The Get Next Line project also includes a bonus part that allows you to enhance the function. The bonus requirements include:

- Implementing get_next_line() using only one static variable
- Managing multiple file descriptors simultaneously
  
To include the bonus part in your project, use the _bonus suffix for the bonus files (get_next_line_bonus.c, get_next_line_bonus.h, get_next_line_utils_bonus.c).
