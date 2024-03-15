#include <stdio.h>
#include "parse.h"
#include "common.h"
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>

int init_db_header(struct db_header *const header)
{
   header->magic = HEADER_MAGIC;
   header->version = HEADER_VERSION;
   header->filesize = HEADER_SIZE;
   header->count = 0;

   return STATUS_SUCCESS;
}

int validate_db_header(const int fd, struct db_header *const header)
{
   // check magic number
   if (header->magic != HEADER_MAGIC) {
      printf("[read] ERROR : header magic number invalid\n");
      return STATUS_ERROR;
   };

   // check version
   if (header->version != HEADER_VERSION) {
      printf("[read] ERROR : header version invalid\n");
      return STATUS_ERROR;
   };

   // check filesize TODO
   struct stat database_metadata = {0};
   if (fstat(fd, &database_metadata) == -1) {
      perror("fstat");
      return STATUS_ERROR;
   };
   if (header->filesize != database_metadata.st_size) {
      printf("[read] ERROR : database size and header size not match\n");
      return STATUS_ERROR;
   }

   return STATUS_SUCCESS;
}

int ntoh_db_header(struct db_header *const header)
{
   header->magic = ntohl(header->magic);
   header->version = ntohs(header->version);
   header->filesize = ntohl(header->filesize);
   header->count = ntohl(header->count);

   return STATUS_SUCCESS;
}

int hton_db_header(struct db_header *const header)
{
   header->magic = htonl(header->magic);
   header->version = htons(header->version);
   header->filesize = htonl(header->filesize);
   header->count = htonl(header->count);

   return STATUS_SUCCESS;
}

void print_db_header(struct db_header *const header)
{
   printf("--- header ---\n"
          "magic: %d\n"
          "version: %hu\n"
          "filesize: %u\n"
          "count: %u\n"
          "--------------\n",\
          header->magic,\
          header->version,\
          header->filesize,\
          header->count);
}
