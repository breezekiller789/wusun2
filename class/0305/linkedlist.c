LinkedList has three methods:
Insertion : 
            1 . at tail
            2 . at front
            3 . ordered ( sorted )

Traverse  :
            1 .

Deletion  :
            1 .

Find      :
            1 .

Reversion :
            1 .


struct lnode{};

l_insert(struct lnode *Llist, char *name, int cnt){
    struct lnode *tmp;
    if(tmp == NULL){
        tmp = (struct lnode *) malloc(sizeof(struct lnode));
        strcpy(tmp->name, name);
        tmp->cnt = 1;
        tmp->next = Llist;
        return tmp;
    }

}
