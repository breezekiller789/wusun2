#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 32

typedef struct Node
{
    char *word;
    int count;
    struct Node *next;

} Node;

void table_init(Node* table[]);
void get_keyword(char s[],char line[],int i);
void get_operation(char in[],char operation[]);
Node* get_node(Node *newnode,char s[]);
int Insert_Node(Node *table[],char in[],char s[]);
int query(Node *table[],char in[],char s[],int flag);
int traversal(Node *table[],char *word[],int count[],int num);
void sort(char *word[],int count[],int num);

int main()
{
    Node *table[MAX];
    char in[MAX],s[MAX],operation[8];
    char *word[MAX];
    int count[MAX];
    int num=0,i=0;

    freopen("test.txt","r",stdin);

    table_init(table);
    while(fgets(in,MAX,stdin)!=NULL)
    {
        //remove newline
        if(in[strlen(in)-1]=='\n')
            in[strlen(in)-1]='\0';

        get_operation(in,operation);
        if(strcmp(operation,"insert")==0)
            Insert_Node(table,in,s);
        else if(strcmp(operation,"delete")==0)
            query(table,in,s,1);

        else if(strcmp(operation,"query")==0)
            query(table,in,s,0);
        else if(strcmp(operation,"count")==0)
        {
            num=traversal(table,word,count,num);
            sort(word,count,num);
        }
    }
    return 0;
}

void table_init(Node* table[])
{
    int i;
    for(i=0; i<MAX; i++)
    {
        table[i]=(Node*)malloc(sizeof(Node));
        table[i]->word=(char*)malloc(sizeof(char)*16);
        table[i]->word[0]='\0';
        table[i]->count=0;
    }
}

void get_keyword(char s[],char line[],int i)
{
    int j=0;
    while(line[i]!=EOF)
        s[j++]=line[i++];
    s[j]='\0';
}

void get_operation(char in[],char operation[])
{
    int i;
    memset(operation,0,8);
    for(i=0; in[i]!=' '; i++)
        operation[i]=in[i];
    operation[i]='\0';
}

Node *get_node(Node *newnode,char s[])
{
    newnode=(Node*)malloc(sizeof(Node));
    newnode->word=(char*)malloc(sizeof(char)*MAX);
    strcpy(newnode->word,s);
    newnode->count=1;
    newnode->next=NULL;
    return newnode;
}

int Hash_func(char s[])
{
    int code=0,hv=37891;
    char *ptr;

    ptr=s;
    while(*ptr++)
        hv=((hv<<5)+hv)+*ptr;
    hv=hv%MAX;
    return hv;
}

int Insert_Node(Node *table[],char in[],char s[])
{
    int code;
    Node *newnode=NULL;
    Node *p,*q;

    get_keyword(s,in,7);
    code=Hash_func(s);
    if(table[code]->count==0)
    {
        strcpy(table[code]->word,s);
        table[code]->count=1;
    }
    else
    {
        p=table[code];
        while(p!=NULL)
        {
            q=p;
            if(strcmp(s,p->word)==0)
            {
                p->count++;
                memset(s,0,MAX);
                return 0;
            }
            p=p->next;
        }
        newnode=get_node(newnode,s);
        q->next=newnode;
    }
    memset(s,0,MAX);
    return 0;
}

int query(Node *table[],char in[],char s[],int flag)
{
    int code=0,tag=1;
    Node *p;

    code=Hash_func(s);
    p=table[code];
    if(flag)//delete call
    {
        get_keyword(s,in,7);
        while(p!=NULL)
        {
            if(strcmp(p->word,s)==0)
            {
                p->count--;
                break;
            }
            p=p->next;
        }
    }
    else//query call
    {
        get_keyword(s,in,6);
        while(p!=NULL)
        {
            if(strcmp(p->word,s)==0)
            {
                printf("----------\n");
                printf("%s\t%d\n",p->word,p->count);
                printf("----------\n");
                tag=0;
                break;
            }
            p=p->next;
        }
        if(tag)
        {
            printf("----------\n");
            printf("Not found!\n");
            printf("----------\n");
        }

    }
    memset(s,0,MAX);
    return 0;
}

int traversal(Node *table[],char *word[],int count[],int num)
{
    int i;
    Node *p;
    for(i=0,num=0; i<MAX; i++)
    {
        if(table[i]->count==0)
            continue;
        p=table[i];
        if(p!=NULL)
        {
            word[num]=(char*)malloc(sizeof(char)*MAX);
            strcpy(word[num],p->word);
            count[num]=p->count;
            num++;
            p=p->next;
        }
    }
    return num;
}

void sort(char *word[],int count[],int num)
{
    int i,j,t;
    char *tmp;

    for(i=0; i<num; i++)for(j=1; j<num; j++)
    {
        if(count[j-1]<count[j])
        {
            t=count[j-1];
            count[j-1]=count[j];
            count[j]=t;

            tmp=word[j-1];
            word[j-1]=word[j];
            word[j]=tmp;
        }
    }
    for(i=0; i<num; i++)for(j=1; j<num; j++)
    {
        if(count[j-1]==count[j]&&strcmp(word[j-1],word[j])>0)
        {
            tmp=word[j-1];
            word[j-1]=word[j];
            word[j]=tmp;
        }
    }
    printf("----------\n");
    for(i=0; i<num; i++)
    {
        if(count[i]==0)
            break;
        printf("%d\t%s\n",count[i],word[i]);
    }
    printf("----------\n");
}
