#include <stdio.h>
#include <stdlib.h>

#include "hashmap-link-hash.h"

int main(int argc, char *argv[])
{
    size_t ret;
    unsigned long res;

    hash_t *h = hash_init();

    (void)argc;
    (void)argv;

    ret = h->adds(h->hash, "Hello world!",0U);
    printf("\t%d) Add: [%d]\n", __LINE__, ret);
    ret = h->adds(h->hash, "Hello",0U);
    printf("\t%d) Add: [%d]\n", __LINE__, ret);
    ret = h->adds(h->hash, "world!",0U);
    printf("\t%d) Add: [%d]\n", __LINE__, ret);
    ret = h->adds(h->hash, "Helloworld",0U);
    printf("\t%d) Add: [%d]\n", __LINE__, ret);
    ret = h->adds(h->hash, "Helloworld!",0U);
    printf("\t%d) Add: [%d]\n", __LINE__, ret);

    printf("\n\t%d) Dump\n", __LINE__);
    h->dump(h->hash);

    ret = (size_t)h->sort(h->hash);
    printf("\n\t%d) Sort: [%d]\n", __LINE__, ret);

    printf("\n\t%d) Dump\n", __LINE__);
    h->dump(h->hash);

    res = h->searchs(h->hash, "world!", 0);
    printf("\n\t%d) Search: [%lu]  [%s]\n", __LINE__, res, "world!");

    res = h->searchs(h->hash, "xyzz", 0);
    printf("\t%d) Search: [%lu] [%s]\n", __LINE__, res, "xyzz");

    res = h->searchs(h->hash, "Hello world!", 0);
    printf("\t%d) Search: [%lu] [%s]\n", __LINE__, res, "Hello world!");

    ret = (size_t)h->dels(h->hash, "world!", 0);
    printf("\n\t%d) Sdelete: [%d] [%s]\n", __LINE__, ret, "world!");

    printf("\n\t%d) Dump\n", __LINE__);
    h->dump(h->hash);

    ret = (size_t)h->dels(h->hash, "Hello world!", 0);
    printf("\n\t%d) Sdelete: [%d] [%s]\n", __LINE__, ret, "Hello world!");

    printf("\n\t%d) Dump\n", __LINE__);
    h->dump(h->hash);

    h->free(h->hash);
    free(h);

    return 0;
}
