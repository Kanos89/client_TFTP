#include <stdio.h>
#include "main.h"

#include <string.h>


int main(void) {
    char command[BUFFSIZE];

    while (1) {
        write(1, line_start, strlen(line_start)); // Prompt
        ssize_t input = read(0, command, BUFFSIZE - 1); // Read input


        if (input > 0) {
            command[input - 1] = '\0'; // Null-terminate (replace newline)

            if (strcmp(command, "exit") == 0) {
                break;
            }

            else if (handle_command(command) == -1) {
                write(1, "Invalid command or arguments for this lab\n", 43);
            }
        }
    }

    return 0;
}
