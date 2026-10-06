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

#endif
