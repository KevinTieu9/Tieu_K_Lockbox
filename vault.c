/*
 * vault.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * mkdir the vault and build paths inside it.
 */

#include "vault.h"
#include "lockbox.h"
#include "env.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

/*
 * ensure_vault
 * Create the vault folder if it is not there yet.
 * EEXIST means the folder already exists. That is not an error.
 *
 * return 0 if it worked, 1 if mkdir failed
 */
int ensure_vault(void)
{
    const char *folder;

    folder = vault_directory();
    if (mkdir(folder, 0700) == -1 && errno != EEXIST) {
        perror(folder);
        return 1;
    }
    return 0;
}

/*
 * name_is_safe
 * A stored name must stay inside the vault folder.
 * Reject empty names, slashes, "." and "..".
 *
 * stored_name - name the caller wants to use inside vault/
 * return 1 if the name is usable, 0 if it is not
 */
int name_is_safe(const char *stored_name)
{
    if (stored_name == NULL || stored_name[0] == '\0') {
        return 0;
    }
    if (strchr(stored_name, '/') != NULL) {
        return 0;
    }
    if (strcmp(stored_name, ".") == 0 || strcmp(stored_name, "..") == 0) {
        return 0;
    }
    return 1;
}

/*
 * base_name
 * Return the part after the last slash.
 * put /tmp/notes.txt should store notes.txt, not the whole path.
 *
 * path - path the user typed
 */
const char *base_name(const char *path)
{
    const char *slash;

    if (path == NULL) {
        return "";
    }
    slash = strrchr(path, '/');
    if (slash == NULL) {
        return path;
    }
    return slash + 1;
}