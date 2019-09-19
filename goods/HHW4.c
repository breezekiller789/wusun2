#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Term_Count
{
    int count;
    char term[105];
    struct Term_Count *next;
} Node;

Node *get_node(Node *current);
Node *sort_count(Node *head);
Node *sort_term(Node *head);
int print_node(Node *head);

int main()
{
    char line[105];
    Node *head=NULL;
    Node *current=NULL;
    int first=1;
    int flag;
    Node *ptr,*qtr;

    head=get_node(head);
    while(fgets(line,105,stdin)!=NULL)
    {
        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        if(first)
        {
            strcpy(head->term,line);
            head->next=NULL;
            first=0;
            continue;
        }
        ptr=head;
        flag=1;
        while(ptr!=NULL)
        {
            if(strcmp(ptr->term,line)==0)  //比對input看有沒有一樣
            {
                ptr->count++;
                flag=0;
                break;
            }
            else
            {
                qtr=ptr;                   //存要連接下一個節點的連接位置
                ptr=ptr->next;
            }
        }

        if(flag)             //表示現在這個跟前一個不同 所以要開一個新的接下去
        {
            current=get_node(current);
            strcpy(current->term,line);
            qtr->next=current;
            current->next=NULL;
        }
    }
    head=sort_count(head);
    head=sort_term(head);

    print_node(head);
    return 0;
}

Node *get_node(Node *current)
{
    current=(Node*)malloc(sizeof(Node));
    current->count=1;
    current->term[0]='\0';

    return current;
}

Node *sort_count(Node *head)
{
    Node *tmp;
    Node *curr;
    Node *prev;
    Node *tail=NULL;

    while(head!=tail)
    {
        curr=head;
        prev=head;
        while(curr&&curr->next&&curr->next!=tail)
        {
            if(curr->count < curr->next->count)
            {
                tmp=curr->next;
                curr->next=tmp->next;
                tmp->next=curr;
                if(curr==head)
                {
                    prev=tmp;
                    head=tmp;
                }
                else
                {
                    prev->next=tmp;
                    prev=prev->next;
                }
            }
            else
            {
                if(curr!=head)
                {
                    prev=prev->next;
                }
                curr=curr->next;
            }
        }
        tail=curr;
    }
    return head;
}

Node *sort_term(Node *head)
{
    Node *tmp;
    Node *curr;
    Node *prev;
    Node *tail=NULL;

    while(head!=tail)
    {
        curr=head;
        prev=head;
        while(curr&&curr->next&&curr->next!=tail)
        {
            if((curr->count==curr->next->count)&&(strcmp(curr->term,curr->next->term)>0))  //如果count一樣就去比權重
            {
                tmp=curr->next;
                curr->next=tmp->next;
                tmp->next=curr;
                if(curr==head)
                {
                    prev=tmp;
                    head=tmp;
                }
                else
                {
                    prev->next=tmp;
                    prev=prev->next;
                }
            }
            else
            {
                if(curr!=head)
                {
                    prev=prev->next;
                }
                curr=curr->next;
            }
        }
        tail=curr;
    }
    return head;
}

int print_node(Node *head)
{
    Node *ptr;

    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->count);
        printf("%s\n",ptr->term);
        ptr=ptr->next;
    }
    return 0;
}
