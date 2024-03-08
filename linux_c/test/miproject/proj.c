#include <stdio.h>

extern short i;

static int _func()
{
   printf("<%s>: i = %d\n", __FUNCTION__, i);
   return 0;
}

int call_func() {
  return _func();
}
