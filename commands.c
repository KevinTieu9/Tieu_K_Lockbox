/*
 * commands.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * put copies a file in. get copies it out. list names what is stored.
 */

#include "commands.h"
#include "lockbox.h"
#include "vault.h"
#include "env.h"
#include "log.h"
#include "copy.h"

#include <stdio.h>
#include <string.h>

/*
 * print_usage
 * How to run this program. Writes to stderr.
 *
 * program_name - argument_list[0]
 */
void print_usage(const char *program_name)
{
    fprintf(stderr, "usage:\n");
    fprintf(stderr, "  %s put <file>\n", program_name);
    fprintf(stderr, "  %s -d DIR <command>\n", program_name);
}
