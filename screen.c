/*
 * screen.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * Terminal file list of stored names.
 */

#include "screen.h"
#include "lockbox.h"
#include "vault.h"
#include "env.h"

#include <ncurses.h>
#include <string.h>
#include <dirent.h>

/*
 * collect_stored_names
 * Fill names with stored file names. Skip helper files.
 *
 * names     - caller array of name buffers
 * max_names - how many names fit
 * return how many names were stored
 */
static int collect_stored_names(char names[][NAME_BUFFER_SIZE], int max_names)
{
    DIR *vault_folder;
    struct dirent *entry;
    int count;

    count = 0;
    vault_folder = opendir(vault_directory());
    if (vault_folder == NULL) {
        return 0;
    }
    entry = readdir(vault_folder);
    while (entry != NULL && count < max_names) {
        if (!is_bookkeeping_name(entry->d_name)) {
            strncpy(names[count], entry->d_name, NAME_BUFFER_SIZE - 1);
            names[count][NAME_BUFFER_SIZE - 1] = '\0';
            count = count + 1;
        }
        entry = readdir(vault_folder);
    }
    closedir(vault_folder);
    return count;
}

/*
 * command_screen
 * Collect names, then show how many files were found.
 *
 * return 0
 */
int command_screen(void)
{
    char names[SCREEN_MAX_FILES][NAME_BUFFER_SIZE];
    int file_count;

    file_count = collect_stored_names(names, SCREEN_MAX_FILES);
    initscr();
    cbreak();
    noecho();
    mvprintw(0, 0, "lockbox  %d file(s)", file_count);
    mvprintw(2, 0, "press any key");
    refresh();
    getch();
    endwin();
    return 0;
}
