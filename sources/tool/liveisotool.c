// Part of windowspasser project @github.com

#include "../../headers/liveisotool.h"

int main(void){
  char partition[6];
  char completedrive[11] = "/dev/";

  system("modprobe ntfs3");

  while(1){
    puts("Lookup the partitions, then enter 'q' to enter the target.");
    sleep(3);
    system("fdisk -l | less");
    puts("Choose target partition(C drive) (Enter for example sda1, sda2, sdb1 ...):");
    fgets(partition, 5, stdin);
    partition[strcspn(partition, "\n")] = 0;

    strcat(completedrive, partition);

    if(0 != mount(completedrive, MOUNTPOINT_PATH, "ntfs3", 0, "")){
      perror("Failed to mount target partition");
      fprintf(stderr, "Your entry: %s\n", completedrive);
      sleep(2);
      continue;
    }
    break;
  }
  puts("Successfully mounted.");

  execl(WINDOWSPASSER_PATH, "",MOUNTPOINT_PATH, NULL);

  return 0;
}
