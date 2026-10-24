/*
 * process.c
 * CS 375 — lockbox
 *
 * Author: Kevin Tieu
 *
 * status uses fork. hash uses a pipe. SIGINT stops a blocked wait.
 */

#include "process.h"
#include "lockbox.h"
#include "vault.h"
#include "env.h"
#include "log.h"

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

static void handle_interrupt(int signal_number)
{
    (void)signal_number;
}

/*
 * install_interrupt_handler
 * Catch SIGINT so a blocked read or accept can return.
 */
void install_interrupt_handler(void)
{
    signal(SIGINT, handle_interrupt);
}

static int print_status_report(void)
{
    DIR *vault_folder;
    struct dirent *entry;
    int file_count;

    vault_folder = opendir(vault_directory());
    if (vault_folder == NULL) {
        perror(vault_directory());
        return 1;
    }
    file_count = 0;
    entry = readdir(vault_folder);
    while (entry != NULL) {
        if (!is_bookkeeping_name(entry->d_name)) {
            file_count = file_count + 1;
        }
        entry = readdir(vault_folder);
    }
    closedir(vault_folder);
    printf("vault: %s\n", vault_directory());
    printf("stored files: %d\n", file_count);
    fflush(stdout);
    return 0;
}

/*
 * command_status
 * Fork. The child prints the report. The parent waits.
 *
 * return 0 if it worked, 1 if fork or wait failed
 */
int command_status(void)
{
    pid_t child_process_id;
    int wait_status;

    child_process_id = fork();
    if (child_process_id < 0) {
        perror("fork");
        return 1;
    }
    if (child_process_id == 0) {
        _exit(print_status_report());
    }
    if (waitpid(child_process_id, &wait_status, 0) == -1) {
        perror("waitpid");
        return 1;
    }
    log_action("STATUS");
    return 0;
}
