#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct database_header {
   unsigned short version;
   unsigned short employees;
   unsigned int filelength;
};

int main()
{
   int fd = open("./my-db.db", O_RDONLY);
   if (fd == -1) {
      perror("open");
      return -1;
   }

   struct database_header head = {0};

   read(fd, &head, sizeof(head));
   printf("Database Version: %d\n", head.version);
   printf("Database Employees: %d\n", head.employees);
   printf("Database filelength: %d\n", head.filelength);

   close(fd);

   return 0;
}
