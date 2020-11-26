#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstl/cmap.h"
#include "cstl/cqueue.h"


typedef struct {
    char msg[16];
} MyData_ST;

int main() {
    map_t *pt_map = NULL;
    pair_t *pt_pair = NULL;
    map_iterator_t it_iter;
    MyData_ST stMsg;
    int iIdx = 0;

    type_register(MyData_ST, NULL, NULL, NULL, NULL);

    pt_map = create_map(int, MyData_ST);
    pt_pair = create_pair(int, MyData_ST);

    pair_init(pt_pair);
    map_init_ex(pt_map, NULL);

    iIdx = 66;
    memset(&stMsg, 0x00, sizeof(stMsg));
    strcpy((char *) &stMsg, "hello~");
    pair_make(pt_pair, iIdx, &stMsg);
    it_iter = map_insert(pt_map, pt_pair);

    iIdx = 88;
    memset(&stMsg, 0x00, sizeof(stMsg));
    strcpy((char *) &stMsg, "word~");
    pair_make(pt_pair, iIdx, &stMsg);
    it_iter = map_insert(pt_map, pt_pair);

    iIdx = 66;
    it_iter = map_find(pt_map, iIdx);
    printf("[003]:%d\n", (*((int *) pair_first((pair_t *) iterator_get_pointer(it_iter)))));
    printf("[004]:%s\n", ((MyData_ST *) pair_second((pair_t *) iterator_get_pointer(it_iter)))->msg);


    map_destroy(pt_map);
    pair_destroy(pt_pair);

    return 0;
}

typedef struct T_Item{
    int id;
} Item;


int main1(){
    type_register(Item, NULL, NULL, NULL, NULL);
    deque_t * qt =  create_deque(Item);
    deque_init(qt);
    Item item1 = {1};
    Item item2 = {2};
    deque_push_back(qt,&item1);
    deque_push_back(qt,&item2);
    printf("%zu\n",deque_size(qt));
    deque_destroy(qt);

    deque_t * q_t =  create_deque(int);
    deque_init(q_t);
    deque_push_back(q_t,1);
    deque_push_back(q_t,2);
    printf("%zu\n",deque_size(q_t));
    deque_destroy(q_t);


    return 0;
}


struct New_Item{
    int id;
};

int main2(){
    type_register(struct New_Item, NULL, NULL, NULL, NULL);
    deque_t * qt =  create_deque(struct New_Item);


    deque_init(qt);
    struct New_Item item1 = {1};
    printf("%p\n",&item1);
    struct New_Item item2 = {2};
    printf("%p\n",&item2);
    deque_push_back(qt,&item1);
    deque_push_back(qt,&item2);
    printf("%zu\n",deque_size(qt));

    item1.id = 100;
    item2.id = 200;

    struct New_Item * out1 = deque_front(qt);
    deque_pop_front(qt);
    struct New_Item * out2 = deque_front(qt);
    printf("%p\n",out1);
    printf("%p\n",out2);


    printf("%d\n",out1->id);
    printf("%d\n",out2->id);
    deque_destroy(qt);
    return 0;
}


