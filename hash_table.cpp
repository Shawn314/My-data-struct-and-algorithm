#include <stdlib.h>
#include <stdio.h>
//source: http://www.kaushikbaruah.com/posts/data-structure-in-c-hashmap/
//1) hash map node element include `key` and `value`
//2) hash map table store all hash map node
//3) three function in hash: createTable(), insert(), lookup(), hashCode()
//4) handle collision way include: linear probing, chaining(recommend) ...

typedef struct node_st {
    int key;
    int value;
    struct node_st* next;
}*node_t;


typedef struct table_st {
    int capacity;
    node_t *nodeArr;
}*table_t;


table_t createTable(int capacity) {
    table_t t = (table_t)malloc(sizeof(struct table_st));
    t->capacity = capacity;
    t->nodeArr = (node_t*)malloc(sizeof(node_t) * capacity);
    for(int i = 0; i < capacity; i++) {
        t->nodeArr[i] = NULL;
    }
    return t;
}
int hashCode (table_t t, int key) {
    if (key < 0)
        return -(key % t->capacity);
    return key % t->capacity;
}
void insert(table_t t, int key, int value) {
    int pos = hashCode(t, key);
    node_t node_list = t->nodeArr[pos];
    node_t tmp = node_list;
    while (tmp != NULL) {
        if (tmp->value == value) {
            return;
        }
        //list have same key elem
        if (tmp->key == key) {
            return;
        }
        tmp = tmp->next;
    }
    node_t new_node_key = (node_t)malloc(sizeof(node_st));
    new_node_key->key = key;
    new_node_key->value = value;
    new_node_key->next = node_list;
    t->nodeArr[pos] = new_node_key;
}
int lookup(table_t t, int key) {
    int pos = hashCode(t, key);
    node_t node_list = t->nodeArr[pos];
    if (node_list == NULL) {
        return -1;
    }
    node_t tmp = node_list;
    while (tmp != NULL) {
        if (tmp->key == key) {
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return -1;
}
int main() {
    table_t t = createTable(10);
    insert(t, 2, 3);
    insert(t, 2, 4);
    insert(t, 12,5);
    insert(t, 3,4);
    printf("%d\n", lookup(t, 3));
    printf("%d\n", lookup(t, 2));
    printf("%d\n", lookup(t, 12));
    return 0;
}
