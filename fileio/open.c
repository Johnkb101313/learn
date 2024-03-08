#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
   if (argc != 2) {
      printf("Usage: %s <filename>\n", argv[0]);
      return -1;
   }

   int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
   if (fd == -1) {
      perror("open");
      return -1;
   }

   char buffer[] = "hello world\n";

   write(fd, buffer, strlen(buffer));

   close(fd);

   return 0;
}
