#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Windows system-related constants
#define MAX_PATH 260
#define MAX_LOGONNAME 104
#define ROOT_SYS_PATH "/Windows/System32"
#define SETHC_PATH ROOT_SYS_PATH "/sethc.exe"
#define BACKUP_SETHC_PATH ROOT_SYS_PATH "/.sethc.exe"

// Program-related
#define SIZE (1024 * 1024)
#define HELP "Syntax: ./windowspasser [TARGET C drive path]"
