#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "common.h"
#include "file.h"
#include "parse.h"

// this program is follow posix

int main(int argc, char *argv[])
{
   int option;
   int database_fd = -1;
   char const *pathname;
   char const *employee_data;
   struct db_header *header = calloc(1, HEADER_SIZE);

   // flag for check option
   bool flag_new = false;
   bool flag_add = false;
   bool flag_delete = false;
   bool flag_edit = false;
   bool flag_read = false;
   bool flag_open = false;

   while((option = getopt(argc, argv, "+f:na:der")) != -1) {
      switch(option) {
         case 'n':
            flag_new = true;
            break;
         case 'a':
            flag_add = true;
            employee_data = optarg;
            break;
         case 'd':
            flag_delete = true;
            break;
         case 'e':
            flag_edit = true;
            break;
         case 'r':
            flag_read = true;
            break;
         case 'f':
            flag_open = true;
            pathname = optarg;
            break;
         case '?':
         default:
            return STATUS_ERROR;
      }
   };

   if (!flag_open) {
      printf("You don't specify a file path\n");
      return STATUS_ERROR;
   }

   if (flag_new) {
      database_fd = new_db(pathname);
      if (database_fd == STATUS_ERROR) {
         return STATUS_ERROR;
      }
      init_db_header(header);
      printf("[new] SUCCESS : create database successfully\n");
      print_db_header(header);
   } else {
      database_fd = open_db(pathname);
      if (database_fd == STATUS_ERROR) {
         return STATUS_ERROR;
      }
      // read database header from disk to struct *db_header header
      if (read_db(database_fd, header, HEADER_SIZE) == STATUS_ERROR) {
         return STATUS_ERROR; 
      }
      if (ntoh_db_header(header) == STATUS_ERROR) {
         return STATUS_ERROR;
      };
      if (validate_db_header(database_fd, header) == STATUS_ERROR) {
         return STATUS_ERROR;
      };
      printf("[open] SUCCESS : database format valid\n");
      print_db_header(header);
   }

   if (flag_add) {
      // TODO
      header->count++;
   }

   hton_db_header(header);
   if (write_db(database_fd, header, HEADER_SIZE, POS_BEGIN) == STATUS_ERROR) {
      return STATUS_ERROR;
   };

   printf("empolyee struct size = %lu\n", EMPLOYEE_SIZE);

   free(header);
   close(database_fd);

   return 0;
}
