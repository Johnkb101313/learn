#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct employee_t {
   short id;
   int num;
   short small;
};

int main()
{
   int fd = open("1.txt", O_RDONLY);
   if (fd == -1) {
      perror("open");
      return -1;
   }

   struct employee_t emp = {0};

   read(fd, &emp, sizeof(struct employee_t));

   struct stat fileinfo = {0};

   int error = fstat(fd, &fileinfo);
   if (error == -1) {
      perror("fstat");
      return -2;
   }

   close(fd);

   return 0;
}
