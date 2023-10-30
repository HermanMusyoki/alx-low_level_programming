# Low Level Programming Project 
## 0x15. C - File I/O

### File descriptors
process-unique identifier (handle) for a file or other input/output resource,
such as a pipe or network socket.)

|Integer|    Name	 |   <unistd.h>	     |<stdio.h> file stream |
| Value |                | symbolic constant |                      |
| :---: | :------------: | :---------------: | :-------------------:|
|0      |Standard input	 |STDIN_FILENO	     |stdin		    |
|1      |Standard output |STDOUT_FILENO	     |stdout		    |
|2      |Standard error	 |STDERR_FILENO	     |stderr		    |

### I/O system calls
* open
* close
* read
* write

### Flags
* O_RDONLY
* O_WRONLY
* O_RDWR
