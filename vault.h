/*
 * vault.h
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * Vault folder, safe names, and full paths.
 */

#ifndef VAULT_H
#define VAULT_H

#include <stddef.h>

/*
 * ensure_vault
 * Create the vault folder if it is not there yet.
 * EEXIST means the folder already exists. That is not an error.
 *
 * return 0 if it worked, 1 if mkdir failed
 */
int ensure_vault(void);
/*
 * name_is_safe
 * A stored name must stay inside the vault folder.
 * Reject empty names, slashes, "." and "..".
 *
 * stored_name - name the caller wants to use inside vault/
 * return 1 if the name is usable, 0 if it is not
 */
int name_is_safe(const char *stored_name);
/*
 * base_name
 * Return the part after the last slash.
 * put /tmp/notes.txt should store notes.txt, not the whole path.
 *
 * path - path the user typed
 */
const char *base_name(const char *path);

#endif