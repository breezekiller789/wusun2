/* Implement a hash function : */
struct lnode{
    char key[MaxK];
    int cnt;
    struct lnode *next;
};

struct lnode **hashtable;
int maxHash;
maxHash = N * 2 + 13;
hashtable = (struct lnode **)malloc(sizeof(struct lnode *) * maxHash);
initialize  (memset())

hashplus(char *key){
    uint hv = 0;
    int len;
    for(int i = 0; i<strlen(key); i++){
        hv = hv + key[i];
    }
}
