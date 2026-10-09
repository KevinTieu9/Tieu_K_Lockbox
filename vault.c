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

static int join_vault_file(char *path_buffer, size_t path_size,
                           const char *file_name)
{
    int written;

    written = snprintf(path_buffer, path_size, "%s/%s",
                       vault_directory(), file_name);
    if (written < 0 || (size_t)written >= path_size) {
        fprintf(stderr, "path too long\n");
        return 1;
    }
    return 0;
}

/*
 * make_vault_path
 * Build the full path of one stored file.
 *
 * path_buffer - caller array
 * path_size   - size of that array
 * stored_name - plain file name, no slashes
 * return 0 if it worked, 1 if the name is bad or the path is too long
 */
int make_vault_path(char *path_buffer, size_t path_size,
                    const char *stored_name)
{
    if (!name_is_safe(stored_name)) {
        fprintf(stderr, "bad name: %s\n",
                stored_name != NULL ? stored_name : "(null)");
        return 1;
    }
    return join_vault_file(path_buffer, path_size, stored_name);
}

/*
 * make_log_path
 * Build the path of vault/lockbox.log.
 *
 * return 0 if it worked, 1 if the path is too long
 */
int make_log_path(char *path_buffer, size_t path_size)
{
    return join_vault_file(path_buffer, path_size, LOG_FILE_NAME);
}