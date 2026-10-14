# Lockbox

**Author:** Kevin Tieu

## Overview

A multi-feature command-line utility. It dispatches commands, copies files, handles environment variables, maintains a binary index, logs activity, controls processes, and offers a screen-based file browser.

## What the Program Does

The main program reads command-line options and routes work to modules for copy, environment, index, log, process, screen, and vault operations. Data is stored in fixed binary records and plain-text logs.

## Files

| File | Description |
|------|-------------|
| `main.c`, `lockbox.h` | Entry point and shared definitions |
| `commands.c/.h` | Command dispatch |
| `copy.c/.h` | File copy |
| `env.c/.h` | Environment handling |
| `index.c/.h` | Binary index |
| `log.c/.h` | Activity log |
| `process.c/.h` | Process control |
| `screen.c/.h` | Screen-based file browser |
| `vault.c/.h` | Vault storage |

## Techniques

- File I/O and binary records
- `getopt` for options
- Process control
- Terminal screen UI

## Build and Run

```bash
make
./lockbox
```
