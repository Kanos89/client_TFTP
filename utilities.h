//
// Created by kanos on 18/12/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

parse_command(const char *input, char **command, char **host, char **file);
int handle_command(const char *input);

#endif //UTILITIES_H
