#ifndef LIST_H
#define LIST_H

#include "info.h"

struct SNode {
   TInfo info;
   struct SNode *link;
};

typedef struct SNode TNode;
typedef TNode* TList;

TList list_create();
TList list_destroy(TList list);
void list_print(TList list);
TNode* list_search(TList list, TKey key);
TList list_insert(TList list, TInfo info);
TList list_delete(TList list, TKey key);
TList list_min(TList list);
int list_count_nodes(TList list);
TList list_reverse(TList list);
TList list_copy(TList list);
TList list_merge(TList list1, TList list2);

#endif
