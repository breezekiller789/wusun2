int main(){
    struct addr{
        char name[MaxName];
        char phone[MaxPhone];
        char email[MaxEmail]
    };
    struct addr addrbook[MaxStuCnt];//這給太多就是浪費空間
    struct addr *addrbookp;
    struct addr tmpaddr;
    char line[MaxLine], *ptr;
    char name[MaxName], phone[MaxPhone], email[MaxEnail];
    int addrCnt = 0;
    int i;


    ctrcpy(tmpaddr.phone, "0982123123");
    strcpy(tmpaddr.name, "john");
    strcpy(tmpaddr.email, "john@gmail.com");

    addrp = &tmpaddr;

    printf("%s\t%s\t%s\n", tmpaddr.name, tmpaddr.phone, tmpaddr.email);
    addrp = (struct addr *) malloc(sizeof(struct addr));
    strcpy(addrp->name, "mary");
    strcpy(addrp->phone, "0982123123");
    strcpy(addrp->email, "mary@gmail.com");
    printf("%s\t%s\t%s\n", addrp -> name, addrp -> phone, addrp -> email);

    exit(1);

    return 0;

    /*
    while(fgets(line, MaxLine, stdin)){
        if(parseline(line, name, phone, email) == FAILED){
            

        }

    }
    */



}
