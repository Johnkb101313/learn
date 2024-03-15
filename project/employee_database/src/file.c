#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "common.h"
#include "file.h"

int new_db(char const *pathname)
{
   int fd = open(pathname, O_RDWR);
   if (fd > 0) {
      printf("[new] ERROR : file is exist\n");
      close(fd);
      return STATUS_ERROR;
   }

   fd = open(pathname, O_RDWR | O_CREAT, 0644);
   if (fd == -1) {
      perror("open");
      return STATUS_ERROR;
   }

   return fd;
}

int open_db(char const *pathname)
{
   int fd = open(pathname, O_RDWR);
   if (fd == -1) {
      perror("open");
      return STATUS_ERROR;
   }

   return fd;
}

int write_db(const int fd, void *const buf, size_t size, short const pos)
{
   if (pos == POS_BEGIN) {
      lseek(fd, 0, SEEK_SET);
   } else if (pos == POS_END) {
      lseek(fd, 0, SEEK_END);
   } else {
      printf("[write] ERROR : a invalid position for write into database\n");
      return STATUS_ERROR;
   }

   if (write(fd, buf, size) == -1) {
      perror("write");
      return STATUS_ERROR;
   };

   return STATUS_SUCCESS;
}

int read_db(const int fd, void *const buf, size_t size)
{
   if (read(fd, buf, size) == -1) {
      perror("read");
      return STATUS_ERROR;
   }

   return STATUS_SUCCESS;
}
