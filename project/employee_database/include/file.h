#ifndef FILE_H_
#define FILE_H_

#define POS_BEGIN 0
#define POS_END 1

int new_db(char const *pathname);
int open_db(char const *pathname);
int write_db(const int fd,  void *const buf, size_t size, const short pos);
int read_db(const int fd,  void *const buf, size_t size);

#endif
