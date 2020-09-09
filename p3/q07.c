#include <stdio.h>
#include <stdlib.h>

void    *binsearch(const void *key, const void *base, size_t nmemb,
 size_t size, int (*compar)(const void *,const void *));