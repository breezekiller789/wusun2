#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Tree_Node
{
    int count;
    char key[100];
    struct Tree_Node *l_child;
    struct Tree_Node *r_child;
    struct Tree_Node *parent;
} Node;

Node *get_node(Node *current)
{
    current=(Node*)malloc(sizeof(Node));
    current->count=1;
    current->key[0]='\0';
    current->l_child=NULL;
    current->r_child=NULL;
    current->parent=NULL;

    return current;
}

void get_keyword(char s[],char line[],int i,int j)
{
    while(line[i]!=EOF)
        s[j++]=line[i++];
    s[j]='\0';
}
int create_array(char *word[],int count[],char s[],int num)
{
    int i,tag;

    //check duplication
    for(i=0,tag=1; i<num; i++)
        if(strcmp(word[i],s)==0)
        {
            tag=0;
            count[i]++;
            break;
        }

    //make array
    if(tag)
    {
        word[num]=(char*)malloc(sizeof(char)*16);
        strcpy(word[num],s);
        count[num]=1;
        num++;
    }
    return num;
}
Node *Insert_Node(Node *root,char line[],int *first);
Node *Delete_Node(Node *root,char line[]);
Node *query(Node *root,char word[],int flag);
void inorder(Node *current);
void sort(char *word[],int count[],int n);

int main()
{
    Node *root=NULL;
    char line[100],s[16];
    char *input[100];
    int input_cnt[100];
    int first=1,num=0;
    int i,flag;

    root=get_node(root);
    while(fgets(line,100,stdin)!=NULL)
    {
        if(line[strlen(line)-1]=='\n')
            line[strlen(line)-1]='\0';

        if(line[0]=='i'&&line[1]=='n'&&line[2]=='s'&&line[3]=='e'&&line[4]=='r'&&line[5]=='t')
        {
            //separate the keyword
            get_keyword(s,line,7,0);

            //create the array to sort
            num=create_array(input,input_cnt,s,num);

            //insert
            root=Insert_Node(root,s,&first);
            
            //reset
            memset(s,0,16);
        }

        if(line[0]=='d'&&line[1]=='e'&&line[2]=='l'&&line[3]=='e'&&line[4]=='t'&&line[5]=='e')
        {
            //separate the keyword
            get_keyword(s,line,7,0);

            //reduce
            for(i=0,flag=0;i<num;i++)
				if(strcmp(s,input[i])==0)
				{
					flag=1;
					break;
				}
            if(flag&&input_cnt[i]>0)
                input_cnt[i]--;

            //delete
            root=Delete_Node(root,s);

            //reset
            memset(s,0,16);
        }

        if(line[0]=='q'&&line[1]=='u'&&line[2]=='e'&&line[3]=='r'&&line[4]=='y')
        {
            get_keyword(s,line,6,0);
            query(root,s,1);
        }
        if(line[0]=='i'&&line[1]=='n'&&line[2]=='o'&&line[3]=='r'&&line[4]=='d'&&line[5]=='e'&&line[6]=='r')
        {
            printf("----------\n");
            inorder(root);
            printf("----------\n");
        }

        if(line[0]=='c'&&line[1]=='o'&&line[2]=='u'&&line[3]=='n'&&line[4]=='t')
            sort(input,input_cnt,num);
    }
    return 0;
}

Node *Insert_Node(Node *root,char word[],int *first)
{
    Node *current=NULL;
    Node *x,*y;

    if(*first)
    {
        *first=0;
        strcpy(root->key,word);
        return root;
    }
    else
    {
        x=root;
        while(x!=NULL)
        {
            y=x;
            if(strcmp(word,x->key)>0)
                x=x->r_child;
            else if(strcmp(word,x->key)<0)
                x=x->l_child;
            else
            {
                x->count++;
                return root;
            }
        }
        current=get_node(current);
        strcpy(current->key,word);
        current->parent=y;
        if(y==NULL)
            root=current;
        else if(strcmp(current->key,y->key)>0)
            y->r_child=current;
        else if(strcmp(current->key,y->key)<0)
            y->l_child=current;
    }
    return root;
}

Node *Delete_Node(Node *root,char word[])
{
    Node *tpat;

    tpat=query(root,word,0);
    if(tpat!=NULL&&tpat->count>0)
        tpat->count--;

    return root;
}

Node *query(Node *root, char word[],int flag)
{
    Node *current=root;

    while(current!=NULL && strcmp(word,current->key)!=0)
    {
        if(strcmp(word,current->key)>0)
            current=current->r_child;
        else
            current=current->l_child;
    }
    if(flag==0)
        return current;
    else if(flag==1&&current!=NULL)
    {
        printf("----------\n");
        printf("%s\t%d\n",current->key,current->count);
        printf("----------\n");
    }
    return 0;
}

void inorder(Node *current)
{
    if(current)
    {
        inorder(current->l_child);
        if(current->count>0)
            printf("%s\t%d\n",current->key,current->count);
        inorder(current->r_child);
    }
}

void sort(char *word[],int count[],int n)
{
    int i,j,t;
    char *tmp;

    for(i=0; i<n; i++)
        for(j=1; j<n; j++)
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
    printf("----------\n");
    for(i=0; i<n; i++)
	{	
		if(count[i]==0) break;
        printf("%d\t%s\n",count[i],word[i]);
	}
    printf("----------\n");
}





