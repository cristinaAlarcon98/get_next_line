# Get Next Line - Read a Line from a File Descriptor

Welcome to **Get Next Line**, a project where I implemented a function that reads a line from a file descriptor.  
This project taught me how to manage static variables, handle memory allocation, and efficiently read data from files or standard input.

## Description

**Get Next Line** is a function that returns a single line from a file descriptor each time it is called.  
It continues reading from the same descriptor across multiple calls, maintaining the state between invocations.  
This project focuses on **file I/O**, **memory management**, and **static variable usage** in C.

The goal is to create a function with the following prototype:

```c
char *get_next_line(int fd);
```

Each call to `get_next_line` returns the next line from the file, including the newline character (`\n`) if one exists.  
When the end of the file is reached, the function returns `NULL`.

## List of Functions

- **`get_next_line`**: Reads and returns the next line from a file descriptor.  
- **`read_and_join`** *(helper)*: Reads data from the file and concatenates it with previous buffer content.  
- **`ft_strjoin`**: Joins two strings into a new dynamically allocated string.  
- **`ft_strchr`**: Searches for a character in a string.  
- **`ft_strlen`**: Returns the length of a string.  
- **`ft_strdup`**: Duplicates a string.  
- **`ft_substr`**: Extracts a substring from a string.

All functions are implemented manually, without using any prohibited standard library functions.

## Usage

To use **Get Next Line**, include the header file `get_next_line.h` and compile the source files.  
You can then call the function in your code to read a file line by line.

### Compilation

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Output Example

If `example.txt` contains:
```
Hello
World
42
```

The program will print:
```
Hello
World
42
```

## Learning Outcomes

Through this project, I learned to:
- Use **file descriptors** and system calls like `read()`.  
- Manage **static variables** to preserve state between function calls.  
- Handle **dynamic memory allocation** securely.  
- Build helper functions for modular, reusable code.

