#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>

char st[10000000][7];
char ss[10000000][7];
int ra[10000000]={0};

int compare(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}

void str(int a,char c[]){

	int i=0,r=0;
	char b[7]={'\0'};
	for(i=0;i<a;i++){
		r=rand()%26;
		b[i]=r+'a';
	}
	strcpy(c,b);	
}

int main(int argc,char *argv[]){
	char s[101]={'\0'},*p=NULL,b[1000][100],tmp[100]={'\0'};
	char stri[7]={'\0'};
	int a[1000]={0},i=0,num=0,to=0,j=0,tmp2=0,num3=0,num4=0;
	int r=0;
	FILE *file=NULL;
	struct timeval start1,end1;
	struct timeval start2,end2;
	long diff1=0,diff2=0;
	if(argc==2&&strncmp(argv[1],"-n",2)==0){
		while(fgets(s,101,stdin)!=NULL){
			for(i=0;i<(int)strlen(s);i++){
				if(s[i]<='9'&&s[i]>='0'){
					num=i;
					num3=1;
					break;
				}
			}
			if(num3!=1){
				a[to]=0;
				num4++;
			}
			else{
				p=s;
				for(i=0;i<num;i++)
					p++;
				a[to]=atoi(p);
				num3=0;
			}
			strcpy(b[to],s);
			to++;
		}
		for(i=0;i<to;i++){
			for(j=0;j<to-1;j++){
				if(a[j]>a[j+1]){
					memset(tmp,'\0',100);
					strcpy(tmp,b[j]);
					memset(b[j],'\0',100);
					strcpy(b[j],b[j+1]);
					memset(b[j+1],'\0',100);
					strcpy(b[j+1],tmp);
					tmp2=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp2;
				}
			}
		}
		for(i=0;i<num4;i++){
			for(j=0;j<num4-1;j++){
				if(strcmp(b[j],b[j+1])>0){
					memset(tmp,'\0',100);
					strcpy(tmp,b[j]);
					memset(b[j],'\0',100);
					strcpy(b[j],b[j+1]);
					memset(b[j+1],'\0',100);
					strcpy(b[j+1],tmp);
				}
			}
		}
		for(i=0;i<to;i++)
			printf("%s",b[i]);
	}
	if(argc==3&&strncmp(argv[1],"-n",2)==0){
		file=fopen(argv[2],"r");
		while(fgets(s,101,file)!=NULL){
			for(i=0;i<(int)strlen(s);i++){
				if(s[i]<='9'&&s[i]>='0'){
					num3=1;
					num=i;					
					break;
				}
			}
			if(num3!=1){
				num4++;
				a[to]=0;
			}
			else{
				p=s;
				for(i=0;i<num;i++)
					p++;
				a[to]=atoi(p);
				num3=0;
			}
			strcpy(b[to],s);
			to++;
		}

		for(i=0;i<to;i++){
			for(j=0;j<to-1;j++){
				if(a[j]>a[j+1]){
					memset(tmp,'\0',100);
					strcpy(tmp,b[j]);
					memset(b[j],'\0',100);
					strcpy(b[j],b[j+1]);
					memset(b[j+1],'\0',100);
					strcpy(b[j+1],tmp);
					tmp2=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp2;
				}
			}
		}
		for(i=0;i<num4;i++){
			for(j=0;j<num4-1;j++){
				if(strcmp(b[j],b[j+1])>0){
					memset(tmp,'\0',100);
					strcpy(tmp,b[j]);
					memset(b[j],'\0',100);
					strcpy(b[j],b[j+1]);
					memset(b[j+1],'\0',100);
					strcpy(b[j+1],tmp);
				}
			}
		}
		for(i=0;i<to;i++)
			printf("%s",b[i]);
	}
	if(strncmp(argv[1],"-a",2)==0){
		i=0;
		srand(time(NULL));
		for(i=0;i<10000000;i++){
			ra[i]=rand()%6+1;
		}
		for(i=0;i<10000000;i++){
			memset(stri,'\0',sizeof(stri));
			str(ra[i],stri);
			memset(st[i],'\0',sizeof(st[i]));
			strcpy(st[i],stri);
			memset(ss[i],'\0',sizeof(ss[i]));
			strcpy(ss[i],stri);
		}
		gettimeofday(&start1,NULL);
		qsort(st,10000000,sizeof(st[0]),compare);
		gettimeofday(&end1,NULL);
		gettimeofday(&start2,NULL);
		mergesort(ss,10000000,sizeof(ss[0]),compare);
		gettimeofday(&end2,NULL);
		diff1=1000*(end1.tv_sec-start1.tv_sec)+(end1.tv_usec-start1.tv_usec)/1000;
		diff2=1000*(end2.tv_sec-start2.tv_sec)+(end2.tv_usec-start2.tv_usec)/1000;

		printf("Q Sort:%dms\n",diff1);
		printf("Merge Sort:%dms\n",diff2);
		printf("Difference:%dms\n",diff2-diff1);
	}

	if(strncmp(argv[1],"-h",2)==0){
		printf("-n:Numeral comparison\n");
		printf("-a:Random number/string generator\n");
		printf("-h:Help usage\n");
	}

return 0;
}

