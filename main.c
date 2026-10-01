/*
 * main.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 *   make
 *   ./lockbox
 */

#include "lockbox.h"
#include "env.h"

#include <stdio.h>
#include <string.h>

/*
 * main
 * Start the program. Read the command line and run one command.
 *
 * argument_count - how many words are on the command line
 * argument_list - those words. argument_list[0] is the program name
 * return 0 if it worked, 1 if it failed
 */
int main(int argument_count, char *argument_list[])
{
    apply_start_settings();
    if (argument_count < 2) {
        fprintf(stderr, "usage: %s <command>\n", argument_list[0]);
        return 1;
    }
    printf("command: %s\n", argument_list[1]);
    return 0;
}
