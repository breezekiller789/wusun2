#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#define Max_data 10000000

int my_cmp(const void *a, const void *b)
{
    char **x=(char**)a;
    char **y=(char**)b;
    return(strcmp(*x,*y));
}
void merge(char** s,int front,int mid,int end);

void merge_sort(char** s,int front,int end)
{
    int mid;
    if(front<end)
    {
        mid=(front+end)/2;
        merge_sort(s,front,mid);
        merge_sort(s,mid+1,end);
        merge(s,front,mid,end);
    }
}

void merge(char **s,int front,int mid,int end)
{
    char **leftsub,**rightsub;
    char *p,*q;
    int i,j,k;

	leftsub=(char**)malloc(sizeof(char*)*(mid-front+1));
	rightsub=(char**)malloc(sizeof(char*)*(end-mid));
    for(i=front,j=0; i<=mid; i++,j++)
    {
    	leftsub[j]=(char*)malloc(sizeof(char)*10);
        strcpy(leftsub[j],s[i]);
	}
    leftsub[j]=strdup("zzzzzzz");

    for(i=mid+1,j=0; i<=end; i++,j++)
	{
		rightsub[j]=(char*)malloc(sizeof(char)*10);
        strcpy(rightsub[j],s[i]);
	}
    rightsub[j]=strdup("zzzzzzz");
 
    for(i=front,p=leftsub[0],q=rightsub[0]; i<=end; i++)
    {
        if(strcmp(p,q)<=0)
        {
       		memset(s[i],0,10);
            strcpy(s[i],p);
            p++;
        }
        else
        {
        	memset(s[i],0,10);
            strcpy(s[i],q);
            q++;
        }
    }
}

void Random_Generator()
{
    int len,i,j,flag,q_sort_time,merge_sort_time;
    char tmp[7];
    char **s;
    struct timeval tv_begin,tv_end;

    s=(char**)malloc(sizeof(char*)*Max_data);
    srand(time(NULL));
    for(i=0; i<Max_data; i++)
    {
        len=1+rand()%6;
        for(j=0; j<len; j++)
        {
            flag=rand()%2;
            switch(flag)
            {
            case 0:
                tmp[j]='A'+rand()%26;
                break;
            case 1:
                tmp[j]='a'+rand()%26;
                break;
            default:
                tmp[j]='x';
                break;
            }
        }
        tmp[j]='\0';
        s[i]=(char*)malloc(sizeof(char)*10);
        strcpy(s[i],tmp);
        memset(tmp,0,7);
    }
    
    gettimeofday(&tv_begin,NULL);
    qsort(s,Max_data,sizeof(char*),my_cmp);
    gettimeofday(&tv_end,NULL);

    for(i=0; i<Max_data; i++)
        printf("%s\n",s[i]);
	
    q_sort_time=((tv_end.tv_sec)-(tv_begin.tv_sec))*1000;
    printf("Q Sort:%d ms\n",q_sort_time);

    gettimeofday(&tv_begin,NULL);
    merge_sort(s,0,Max_data-1);
    gettimeofday(&tv_end,NULL);

    merge_sort_time=((tv_end.tv_sec)-(tv_begin.tv_sec))*1000;
    printf("Merge Sort:%d ms\n",merge_sort_time);

    printf("Time Interval:%d ms\n",abs(merge_sort_time-q_sort_time));
   	
   	free(s);
}

int get_data(char line[],char *str[],int num[],int cnt)
{
    char *tmp;
    int flag;

    if(line[strlen(line)-1]=='\n')
        line[strlen(line)-1]='\0';
    str[cnt]=strdup(line);

    for(tmp=line,flag=1; *tmp!=EOF; tmp++)
        if('0'<=*tmp&&*tmp<='9')
        {
            num[cnt]=atoi(tmp);
            flag=0;
            break;
        }
    if(flag)
        num[cnt]=0;
    cnt++;

    return cnt;
}

void sort(char *str[],int num[],int cnt)
{
    int i,j,tem;
    char *tmp;

    for(i=0; i<cnt; i++)
        for(j=1; j<cnt; j++)
        {
            if(num[j-1]>num[j])
            {
                tmp=str[j-1];
                str[j-1]=str[j];
                str[j]=tmp;
                tem=num[j-1];
                num[j-1]=num[j];
                num[j]=tem;
            }
        }
    for(i=0; num[i]==0; i++)
        for(j=1; num[j]==0; j++)
        {
            if(strcmp(str[j-1],str[j])>0)
            {
                tmp=str[j-1];
                str[j-1]=str[j];
                str[j]=tmp;
            }
        }
    for(i=0; i<cnt; i++)
	{
        printf("%s\n",str[i]);
        free(str[i]);
	}
}

void Numeral_Comparison(char *filename)
{
    FILE *fp;
    char *str[100];
    char line[100];
    int num[100];
    int cnt=0;

    if(filename==NULL)
        while(fgets(line,100,stdin)!=NULL)
            cnt=get_data(line,str,num,cnt);
    else
    {
        fp=fopen(filename,"r");
        while(fgets(line,100,fp)!=NULL)
            cnt=get_data(line,str,num,cnt);
    }
	sort(str,num,cnt);
	fclose(fp);
}

int main(int argc,char *argv[])
{
    if(strcmp(argv[1],"-h")==0)
        printf("-n:Numeral comparison\n-a:Random number/string generator\n-h:Help usage\n");
    else if(strcmp(argv[1],"-a")==0)
        Random_Generator();
    else if(strcmp(argv[1],"-n")==0||argc==1)
    {
        if(argc==3)
            Numeral_Comparison(argv[2]);
        else
            Numeral_Comparison(NULL);
    }

    return 0;
}
