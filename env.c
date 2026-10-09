/*
 * env.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * getenv, umask, and the -d folder override.
*/
#include "env.h"
#include "lockbox.h"

#include <stdlib.h>
#include <sys/stat.h>

static const char *override_directory = NULL;

/*
 * vault_directory
 * Use the -d folder if it was set. Otherwise use LOCKBOX_DIR.
 * If neither is set, use the default vault folder.
 *
 * return pointer to that folder name
 */
const char *vault_directory(void)
{
    const char *from_environment;

    if (override_directory != NULL && override_directory[0] != '\0') {
        return override_directory;
    }
    from_environment = getenv("LOCKBOX_DIR");
    if (from_environment != NULL && from_environment[0] != '\0') {
        return from_environment;
    }
    return DEFAULT_VAULT_DIR;
}

/*
 * apply_start_settings
 * Set umask so new files are not group or world writable
 * unless we pass a mode to open or mkdir.
 */
void apply_start_settings(void)
{
    umask(077);
}

/*
 * set_vault_directory
 * Remember a folder from the -d switch for this run.
 *
 * folder - path typed after -d
 */
void set_vault_directory(const char *folder)
{
    override_directory = folder;
}