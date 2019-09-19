struct lnode{
    char key[MaxKey];
    char value[MaxVal];
    struct lnode *next;
}

struct lnode *L.insert(strcut lnode *L){
    p = malloc(...);
    strcpy(p->key, key);
    strcpy(p->value, value);
    p->next = L;
    return p;
}

l_insert_c(L, key, value){
    struct lnode *p;
    while(p->next)
        p = p->next;
    return L;

}

insert.order(){
    while(strcmp(p->key, key) > 0){
        last = p;   //把上一個記下來，不然等到遇到比較大的，就忘記上一個是誰
        p = p->next;
    }

    while(strcmp(p->key, key) > 0){ //這樣做有危險，因為不一定p有next，可能會core dump
        next = p->next;
        //if(next==NULL || strcmp(next->key, key < 0))
        if(strcmp(next->key, key) < 0){
            malloc...;
            insert...;
            p->next = t;
            t->next = next;
        }
        p = p->next;
    }

}
//linked list handler
struct l_handle{
    struct lnode *head;
    struct lnode *tail;
    int cnt;
}









