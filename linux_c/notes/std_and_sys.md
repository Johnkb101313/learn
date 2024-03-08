I/O: input & output
# stdio
standard io
# sysio
system io

standard base on system(linux or windows) provide api

例子:
stdio base on sysio
fopen(standard) base on :
- open(linux api) or
- openfile(windows api)
standard base on system(linux or windows)

# stdio function
fopen();
fclose();

character:
- fgetc();
- fputc();

string:
- fgets();
- fputs();

binary:
- fread();
- fwrite();

printf();
scanf();

cursor pos:
fseek();
ftell();
rewind();

fflush();

struct:
FILE
