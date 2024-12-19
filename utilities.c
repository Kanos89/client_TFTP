#include "utilities.h"
#include "main.h"
int parse_command(const char *input, char **command, char **host, char **file) {
    if (input == NULL || command == NULL || host == NULL || file == NULL) {
        return -1; // Invalid arguments
    }

    // Make a copy of input because strtok modifies the string
    char *input_copy = strdup(input);
    if (input_copy == NULL) {
        return -1; // Memory allocation error
    }

    *command = strtok(input_copy, " ");
    *host = strtok(NULL, " ");
    *file = strtok(NULL, " ");

    if (*command == NULL || *host == NULL || *file == NULL) {
        free(input_copy); // Clean up allocated memory
        return -1; // Invalid command format
    }

    return 0; // Success
}

int handle_command(const char *input) {
    char *command, *host, *file;

    if (parse_command(input, &command, &host, &file) == -1) {
        return -1; // Parsing error
    }

    if (strcmp(command, "gettftp") == 0) {
        gettftp(host, file);
    } else if (strcmp(command, "puttftp") == 0) {
        puttftp(host, file);
    } else {
        write(1, "Unknown command.\n", 17);
        return -1; // Unknown command
    }

    return 0; // Success
}
