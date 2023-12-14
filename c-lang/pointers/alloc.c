#include <stdio.h>
#define ALLOCSIZE 10000  /* avail space */

static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff; /* next free pos */

char *alloc(int n) {    /* returns pointer to next free pos */
   if (allocbuff + ALLOCSIZE - allocp >= n) { /* it fits */
      allocp += n;
      return allocp - n; /* old p */
   } else     /* not enough room */
       return NULL;
}

void afree(char *p)
{
    if (p >= allocbuff && p < allocbuff + ALLOCSIZE)
        allocp = p;
}