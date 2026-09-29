/*
 * env.h
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * Vault folder from the environment
 */

#ifndef ENV_H
#define ENV_H

/*
 * vault_directory
 * Pick the folder that holds stored files.
 * LOCKBOX_DIR wins if it is set. Otherwise use DEFAULT_VAULT_DIR.
 *
 * return pointer to that folder name
 */
const char *vault_directory(void);

#endif
