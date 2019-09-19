#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student_Data
{
    int ID;
    char name[100];
    char phone[12];
    char mail[100];
    struct Student_Data *next;
} Node;

int print_hint()
{
    printf("Please input command(i/d/u/f/l/q) and data:\n");
    printf("Insert the record:i studentID\\tname\\tphone\\temail\n");
    printf("Delete the record:d studentID\n");
    printf("Update the record:u studentID\\tname\\tphone\\temail\n");
    printf("Find the record:f [string]\n");
    printf("List the record:l\n");
    printf("Quit:q\n");

    return 0;
}
Node *get_node(Node *current)
{
    //current到時候會「放進資料，接到整條連結串列中」，所以需要配置記憶體空間
    current=(Node*)malloc(sizeof(Node));
    //初始化所有資料
    current->ID=0;
    current->name[0]='\0';
    current->phone[0]='\0';
    current->mail[0]='\0';
    return current;
}
//注意回傳型態
Node *check_duplication(Node *head,int tem,Node *ptr,int *flag);
Node *insert_data(Node *head,char line[]);
Node *insert_node(Node *head, char line[],int *first);
Node *delete_node(Node *head, char line[]);
Node *update_node(Node *head, char line[]);
int Find(Node *head,char line[]);
int List(Node *head);

int main()
{
    Node *head=NULL;
    char Operation;
    char line[100];
    int first=1;
    //head一開始是空的，之後才會慢慢接上去，記得要送去配置記憶體和初始化
    head=get_node(head);

    print_hint();
    while(fgets(line,100,stdin)!=NULL)
    {
        Operation=line[0];

        //first是判斷是不是第一次輸入資料，只要輸入過資料之後，first的值會變成0
        //我直接傳first的位置過去，所以如果做了更動，我可以不用特別回傳他，因為我想要回傳我的連結串列
        if(Operation=='i') head=insert_node(head,line,&first);
        if(Operation=='d') head=delete_node(head,line);
        if(Operation=='u') head=update_node(head,line);
        if(Operation=='f') Find(head,line);
        if(Operation=='l') List(head);
        if(Operation=='q')
        {
            printf("Thanks for your using!\n");
            return 0;
        }
    }
    return 0;
}
Node *insert_data(Node *current,char line[])//因為輸入ID的以外的資料落落長的，所以我特別把他分離出來
{
    char *p,*q;
    char s[100];

    if((p=strstr(line,"name")))
    {
        q=s;
        p=p+5;
        while(*p!='\t') *q++=*p++;
        *q='\0';

        strcpy(current->name,s);
    }
    if((p=strstr(line,"phone")))
    {
        q=s;
        p=p+6;
        while(*p!='\t') *q++=*p++;
        *q='\0';

        strcpy(current->phone,s);
    }
    if((p=strstr(line,"email")))
    {
        q=s;
        p=p+6;
        while(*p!='\n') *q++=*p++;
        *q='\0';

        strcpy(current->mail,s);
    }
    return current;
}
Node *check_duplication(Node *head,int tem, Node *ptr,int *flag)
//檢查有沒有重複的ID，flag紀錄有沒有遇到重複的ID
//回傳的ptr就是重複的的位置，我可以直接處理
{
    *flag=1;
    ptr=head;
    while(ptr!=NULL) //檢查有沒有重複的ID
    {
        if((ptr->ID)!=tem) ptr=ptr->next;
        else
        {
            *flag=0;
            break;
        }
    }
    return ptr;
}
Node *insert_node(Node *head, char line[],int *first)
//輸入節點所有資料
{
    char *p;
    Node *current=NULL;
    Node *ptr=NULL,*qtr=NULL;
    int tem,flag;
    //記得current都要送過去配置空間和初始化
    current=get_node(current);

    if((p=strstr(line,"ID")))
    {
        p=p+3;
        tem=atoi(p);

        //如果是第一次輸入資料first會是1
        //就直接把資料放進head
        if(*first)
        {
            //first轉成0，就再也不會進這個if了
            *first=0;
            //因為沒用到current就要free掉
            free(current);

            head->ID=tem;
            //如果串列後面沒東西了，記得結尾指向NULL
            head->next=NULL;
            //把ID以外的資料輸入
            head=insert_data(head,line);
            printf("Insert successful!\n");
            return head;
        }
        else
        //第二次輸入開始就會進來這裡
        {
            //先檢查有沒重複的ID
            ptr=check_duplication(head,tem,ptr,&flag);
            if(flag==0)//出現重複ID
            {
                //沒用到current就要free掉
                free(current);
                printf("Insert error! studentID is exists!\n");
                return head;
            }

            //如果沒有重複就不會進上面的if，直接下來
            //先把ID放進去，next指向NULL
            current->ID=tem;
            current->next=NULL;

			//這邊開始找目前的資料應該放在哪裡
            if(current->ID<head->ID) //如果他一開始就比head小，就直接他接在head前面
            {
                current->next=head;
                head=current;//然後他就是head了
            }
            else
            //如果他沒有比head小，代表就是會在中間或是最後面(廢話哈哈)
            {
                ptr=head;
                //找到current正確的位置
                while(ptr->next!=NULL)
                {
                    qtr=ptr->next;
                    if(qtr->ID>current->ID) break;
                    //如果current是屬於在中間的情況，ptr就是current的前面，qtr(ptr->next)就是current的後面
                    ptr=ptr->next;
                }
                if(ptr->next==NULL)//如果ptr是串列結尾，就把current接到最後
                {
                    ptr->next=current;
                    current->next=NULL;//記得最後要指向NULL
                }
                else//如果他不是在結尾，當然就是在中間啦
                {
                    current->next=ptr->next;
                    ptr->next=current;
                }
            }

            //把ID以外的資料都放進去
            current=insert_data(current,line);
            printf("Insert successful!\n");
            return head;
        }
    }
		return head;
}

Node *delete_node(Node *head, char line[])
{
    Node *ptr=NULL;
    Node *qtr=NULL;
    char *p;
    int tem,flag;

    p=strstr(line,"ID");
    p=p+3;
    tem=atoi(p);

    //檢查有沒有重複的ID
    ptr=check_duplication(head,tem,ptr,&flag);
    if(flag==0)//出現重複ID
    {
        if(ptr==head)//如果ptr就是head
            //直接把head指向本來head指的下一個東西
            head=head->next;
        else//如果ptr不是開頭，代表要刪掉的資料就是在中間或是在最後(一樣廢話哈哈)
        {
            //用qtr找他的下一個是不是ptr，要知道ptr的前一個我們才能夠把不要的東西拔掉
            qtr=head;
            while(qtr->next!=ptr) qtr=qtr->next;

            if(ptr->next==NULL)//如果ptr是串列的結尾
                //因為qtr是ptr的上一個，就直接把qtr指向結尾就好
                qtr->next=NULL;
            else qtr->next=ptr->next;//因為qtr是ptr的上一個，就直接把qtr指向ptr的下一個，也就是qtr的下一個的下一個
        }

        free(ptr);//ptr目前還指著我們要拔掉的垃圾，所以就把他free掉吧
        printf("delete successful!\n");
    }
    else printf("Delete error! studentID not exists!\n");

    return head;
}

Node *update_node(Node *head, char line[])
{
    char *p;
    Node *ptr=NULL,*qtr=NULL;
    Node *current;
    int tem,flag;
    current=(Node*)malloc(sizeof(Node));

    p=strstr(line,"ID");
    p=p+3;
    tem=atoi(p);

    //一樣檢查有沒有重複的ID
    ptr=check_duplication(head,tem,ptr,&flag);
    if(flag==0)//出現重複ID
    {
        //先做刪除的動作
        if(ptr==head)//如果ptr是第一個node
            head=head->next;
        else
        {
            qtr=head;
            while(qtr->next!=ptr) qtr=qtr->next;


            if(ptr->next==NULL)//如果ptr是串列的結尾
                qtr->next=NULL;
            else qtr->next=ptr->next;
        }
        free(ptr);

        //做完刪除，做輸入
        current->ID=tem;
        current->next=NULL;

        if(current->ID<head->ID)
        {
            current->next=head;
            head=current;
        }
        else
        {
            ptr=head;
            //找到current正確的位置
            while(ptr->next!=NULL)
            {
                qtr=ptr->next;
                if(qtr->ID>current->ID) break;
                ptr=ptr->next;
            }
            if(ptr->next==NULL)//如果ptr是串列結尾
            {
                ptr->next=current;
                current->next=NULL;
            }
            else
            {
                current->next=ptr->next;
                ptr->next=current;
            }
        }

        //再把ID以外的資料都放進去
        current=insert_data(current,line);
        printf("Update successful!\n");
    }
    else  printf("Update error! studentID not exists!\n");

    return head;
}

int Find(Node *head,char line[])
{
    int i,j,flag;
    char spat[20];
    Node *ptr;

    //分離出spat
    i=2;
    j=0;
    while(line[i]!=' '&&line[i]!='\n')
    {
        spat[j++]=line[i++];
    }
    spat[j]='\0';

    //如果兩個strstr任意一個回傳1，代表找到匹配的字詞，就把他所有的資料都印出來
    flag=0;
    ptr=head;
    while(ptr!=NULL)
    {
        if((strstr(ptr->name,spat)) || (strstr(ptr->mail,spat)))
        {
            printf("studentID:%d\t",ptr->ID);
            printf("name:%s\t",ptr->name);
            printf("phone:%s\t",ptr->phone);
            printf("email:%s\n",ptr->mail);
            //flag用來判斷，到底有沒有找到匹配的資料
            flag=1;
        }
        ptr=ptr->next;
    }
    //如果flag回傳0，代表根本沒有找到匹配的字詞
    if(flag==0) printf("Find error! Not exists!\n");
    return 0;
}

int List(Node *head)
{
    Node *ptr;

    ptr=head;
    while(ptr!=NULL)
    {
        printf("studentID:%d\t",ptr->ID);
        printf("name:%s\t",ptr->name);
        printf("phone:%s\t",ptr->phone);
        printf("email:%s\n",ptr->mail);
        ptr=ptr->next;//記得印完要把ptr指向下一個，要不然ptr永遠都不會跑
    }
    return 0;
}
