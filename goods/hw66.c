#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct dnode{
	char key[100];
	int count;
	struct dnode* next;
};
unsigned hash33(char *text)
{
	int len=strlen(text);
	unsigned hashv=0;
	int i;
	for(i=0;i<len;i++)
		hashv=(hashv<<5)+hashv+text[i];
	return hashv;
}
int hinsert(struct dnode** htab,char* key)
{
	unsigned int hv;
	struct dnode* hptr;
	hv=hash33(key)%10000;
	hptr=htab[hv];
	while(hptr!=NULL)
	{
		if(strcmp(hptr->key,key)==0)
		{
			hptr->count++;
			return 0;
		}
		else
			hptr=hptr->next;
	}
	if(hptr==NULL)
	{
		hptr=(struct dnode*)malloc(sizeof(struct dnode));
		strcpy(hptr->key,key);
		hptr->count=1;
		hptr->next=htab[hv];
		htab[hv]=hptr;
		return 0;
	}
	return 0;
}
struct dnode* hfind(struct dnode** htab,char*key)
{
	unsigned int hv;
	struct dnode*hptr;
	hv=hash33(key)%10000;
	hptr=htab[hv];
	while(hptr!=NULL)
	{
		if(strcmp(hptr->key,key)==0)
			return hptr;
		hptr=hptr->next;
	}
	return NULL;
}
int hdelete(struct dnode** htab,char*key)
{
	struct dnode*hptr;
	hptr=hfind(htab,key);
	if(hptr==NULL)
		return 0;
	if(hptr->count>0)
	{
		hptr->count--;
		return 0;
	}
	return 0;
}
int compare(const void*x,const void*y)
{
	struct dnode*a=(struct dnode*)x;
	struct dnode*b=(struct dnode*)y;
	if(a->count==b->count)
		return strcmp(a->key,b->key);
	else
		return (b->count)-(a->count);
}
int main()
{
	int i,n=0,a;
	char command[100];
	char text[100];
	struct dnode *p;
	struct dnode *htab[10000];
	struct dnode sort[10000];
	for(i=0;i<10000;i++)//initialize
	{
		htab[i]=(struct dnode*)malloc(sizeof(struct dnode));
		htab[i]=NULL;
	}
	while(scanf("%s",command)!=EOF)
	{
		if(strcmp(command,"insert")==0)
		{
			a=scanf("%s",text);
			hinsert(htab,text);
		}
		else if(strcmp(command,"delete")==0)
		{
			a=scanf("%s",text);
			hdelete(htab,text);
		}
		else if(strcmp(command,"query")==0)
		{
			a=scanf("%s",text);
			a++;
			printf("----------\n");
			p=hfind(htab,text);
			if(p==NULL)
			{
				printf("Not found!\n");
				printf("----------\n");
			}
			else if(p->count>0)
			{
				printf("%s\t%d\n",p->key,p->count);
				printf("----------\n");
			}
		}
		else if(strcmp(command,"count")==0)
		{
			for(i=0;i<10000;i++)
			{
				if(htab[i]!=NULL)
				{
					p=htab[i];
					while(p!=NULL)
					{
						sort[n].count=p->count;
						strcpy(sort[n].key,p->key);
						n++;
						p=p->next;
					}
				}
			}
			qsort(sort,n,sizeof(struct dnode),compare);
			printf("----------\n");
			for(i=0;i<n;i++)
				printf("%d\t%s\n",sort[i].count,sort[i].key);
			printf("----------\n");
		}
		memset(command,0,sizeof(command));
		memset(text,0,sizeof(text));
	}
	return 0;
}
