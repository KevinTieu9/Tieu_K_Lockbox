/*
 * env.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * getenv, umask, and the -d folder override
 */

#include "env.h"
#include "lockbox.h"

#include <stdlib.h>
#include <sys/stat.h>

/*
 * vault_directory
 * Pick the folder that holds stored files.
 * LOCKBOX_DIR wins if it is set. Otherwise use DEFAULT_VAULT_DIR.
 *
 * return pointer to that folder name
 */
const char *vault_directory(void)
{
    const char *from_environment;

    from_environment = getenv("LOCKBOX_DIR");
    if (from_environment != NULL && from_environment[0] != '\0') {
        return from_environment;
    }
    return DEFAULT_VAULT_DIR;
}
