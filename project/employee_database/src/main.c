#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>
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
	struct employee *employee_ = calloc(1, EMPLOYEE_SIZE);
	struct db_header *header = calloc(1, HEADER_SIZE);
	struct employee *employee_list = NULL;

	// flag for check option
	bool flag_new = false;
	bool flag_add = false;
	bool flag_delete = false;
	bool flag_edit = false;
	bool flag_list = false;
	bool flag_open = false;

	while((option = getopt(argc, argv, "+f:na:del")) != -1) {
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
			case 'l':
				flag_list = true;
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
	}

	if (flag_add) {

		strncpy(employee_->name, strtok(employee_data, ","), EMPLOYEE_NAME_SIZE);
		strncpy(employee_->address, strtok(NULL, ","),\
				EMPLOYEE_ADDRESS_SIZE);
		employee_->hours = atoi(strtok(NULL, ","));

		hton_employee(employee_);
		if (write_db(database_fd, employee_, EMPLOYEE_SIZE, POS_END)) {
			return STATUS_ERROR; 
		};

		header->count++;
		header->filesize += EMPLOYEE_SIZE;
	}

	if (flag_list) {
		// read 
		if (employee_list == NULL) {
			employee_list = calloc(header->count, EMPLOYEE_SIZE);
			if (employee_list == NULL) {
				perror("calloc");
				return STATUS_ERROR;
			}
		}

		lseek(database_fd, HEADER_SIZE, SEEK_SET);
		if (read(database_fd, employee_list,\
					header->count * EMPLOYEE_SIZE) == -1) {
			perror("read");
			return STATUS_ERROR;
		};

		for (int i = 0; i < header->count; i++) {
			ntoh_employee(employee_list + i);
			print_employee(employee_list + i);
		}

		free(employee_list);
		// list
	}

	print_db_header(header);

	// update header and write it into database
	hton_db_header(header);
	if (write_db(database_fd, header, HEADER_SIZE, POS_BEGIN) == STATUS_ERROR) {
		return STATUS_ERROR;
	};

	free(header);
	free(employee_);
	close(database_fd);

	return 0;
}
