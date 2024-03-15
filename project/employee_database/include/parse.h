#ifndef PARSE_H_
#define PARSE_H_

#include <sys/stat.h>

#define HEADER_MAGIC 0x6A6E6462
#define HEADER_VERSION 0x1
#define HEADER_SIZE sizeof(struct db_header)
#define EMPLOYEE_SIZE sizeof(struct employee)

struct db_header {
   unsigned int magic; // 4 bytes
   unsigned short version; // 2 bytes
   unsigned int filesize; // 4 bytes
   unsigned int count; // 4 bytes
};
// after padding = 12 bytes

struct employee {
   unsigned int id; // 4 bytes
   char name[256]; // 256 bytes
   char address[256]; // 256 bytes
   unsigned int hours; // 4 bytes
};
// after padding = 516 bytes

int init_db_header(struct db_header *const header);
int validate_db_header(const int fd, struct db_header *const header);
int ntoh_db_header(struct db_header *const header);
int hton_db_header(struct db_header *const header);
void print_db_header(struct db_header *const header);

#endif
