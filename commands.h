/*
 * commands.h
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * put, get, list, and the usage text.
 */

#ifndef COMMANDS_H
#define COMMANDS_H

/*
 * print_usage
 * How to run this program. Writes to stderr.
 *
 * program_name - argument_list[0]
 */
void print_usage(const char *program_name);

/*
 * command_put
 * Copy source_path into the vault under its base name.
 *
 * source_path - file the user wants to store
 * return 0 if it worked, 1 if it failed
 */
int command_put(const char *source_path);

#endif
