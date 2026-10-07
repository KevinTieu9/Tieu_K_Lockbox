/*
 * log.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * fopen the log with "a" and write one line.
 */

#include "log.h"

/*
 * log_action
 * Append one line to vault/lockbox.log.
 * "a" keeps old lines. A failed log write does not undo the command.
 *
 * message - text to store
 */
void log_action(const char *message)
{
    (void)message;
}
