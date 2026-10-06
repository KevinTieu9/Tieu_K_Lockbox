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