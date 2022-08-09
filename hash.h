#ifndef HASH_H
#define HASH_H

#include "bool.h"
#include "list.h"

struct SHash{
       TList *bucket;
       unsigned long size;
};
typedef struct SHash THash;

int f_hash(TKey key);
THash chained_hash_create(unsigned long size);
THash chained_hash_destroy(THash hash);
TNode* chained_hash_search(THash hash, TKey key);
void chained_hash_insert(THash hash, TInfo info);
void chained_hash_delete(THash hash, TKey key);
bool chained_hash_empty(THash hash);
bool chained_hash_full(THash hash);
void chained_hash_print(THash hash);

#endif
