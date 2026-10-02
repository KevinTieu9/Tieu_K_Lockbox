/*
 * main.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 *   make
 *   ./lockbox
 */

#define _POSIX_C_SOURCE 200809L

#include "lockbox.h"
#include "env.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

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
    int option_letter;
    int first_command_index;

    apply_start_settings();

    opterr = 0;
    option_letter = getopt(argument_count, argument_list, "d:");
    while (option_letter != -1) {
        if (option_letter == 'd') {
            set_vault_directory(optarg);
        } else {
            fprintf(stderr, "usage: %s -d DIR <command>\n", argument_list[0]);
            return 1;
        }
        option_letter = getopt(argument_count, argument_list, "d:");
    }
    first_command_index = optind;
    if (first_command_index >= argument_count) {
        fprintf(stderr, "usage: %s <command>\n", argument_list[0]);
        return 1;
    }
    printf("command: %s\n", argument_list[first_command_index]);
    return 0;
}
