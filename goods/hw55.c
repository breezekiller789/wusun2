#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define thou 1010

struct format{

	char key[thou];
	int value;
	struct format *before;
	struct format *after;
};

void order(struct format *a){

	if(a!=NULL){
		if(a->key==NULL)
			return;
		
		order(a->before);
		if(a->value>0){
			printf("%s",a->key);
			printf("\t%d\n",a->value);
		}
		order(a->after);
	}
}

struct format *insert(struct format *a,char *b){

	if(a==NULL){
		a=(struct format *)malloc(sizeof(struct format));
		strcpy(a->key,b);
		a->value=1;
		a->before=a->after=NULL;
	}
	else if(strcmp(a->key,b)<0){
	 	a->after=insert(a->after,b);
	}
	else if(strcmp(a->key,b)>0){
		a->before=insert(a->before,b);
	}
	else{
		a->value++;
	}
	return a;
}

struct format *find(struct format *a,char *b){

	if(a==NULL)
		return NULL;

	if(strcmp(a->key,b)>0){
		a=find(a->before,b);
	}
	else if(strcmp(a->key,b)<0){
		a=find(a->after,b);
	}
	return a;
}

void find2(struct format *a,int b){

	if(a!=NULL){
		find2(a->before,b);
		if(a->value==b){
			printf("%d\t%s\n",a->value,a->key);
		}
		find2(a->after,b);
	}
}

int main(){

	char com[thou]={'\0'},k[thou]={'\0'},ar[100][100],s[thou]={'\0'},*pch;
	int to=0,max=0,i=0,de=0,num3=0;
	struct format *a=NULL,*start=NULL,*d,*b;

	while(fgets(s,1010,stdin)!=NULL){

		if(strncmp(s,"inorder",7)==0){
			printf("----------\n");
			order(start);
			printf("----------\n");
		}
		else if(strncmp(s,"count",5)==0){
			printf("----------\n");
			max=to;
			for(i=0;i<to;i++){
				if(max>0){
					find2(b,max);
					max--;
				}
			}
			printf("----------\n");
		}
		else{
			pch=strtok(s,"	");
			while(pch!=NULL){
				if(num3==0){
					for(i=0;i<1010;i++)
						com[i]='\0';
					strcpy(com,pch);
					num3++;
				}
				else if(num3==1){
					for(i=0;i<1010;i++)
						k[i]='\0';
					strncpy(k,pch,strlen(pch)-1);
					num3=0;
				}
				pch=strtok(NULL,"	");
			}
			if(strncmp(com,"insert",6)==0&&to==0){
				strcpy(ar[to],k);
				a=(struct format *)malloc(sizeof(struct format));
				strcpy(a->key,k);
				a->value++;
				start=a;
				b=a;
				a->before=NULL;
				a->after=NULL;
			}
			to++;
			if(strncmp(com,"insert",6)!=0&&to==1)
				to--;
			else if(strncmp(com,"insert",6)==0&&to>1){
				strcpy(ar[to],k);
				a=insert(a,k);
				to++;
			}
			else if(strncmp(com,"query",5)==0){
				d=find(a,k);
				if(d->value>0){
					printf("----------\n");
					printf("%s",d->key);	
					printf("\t%d",d->value);
					printf("\n----------\n");
				}
			}
			else if(strncmp(com,"delete",6)==0){
				for(i=0;i<to;i++){
					if(strcmp(ar[i],k)==0)
						de=1;
				}
				if(de==1){
					d=find(a,k);
					if(d->value>0)
						d->value--;
				}
			}
			de=0;
		}
	}
return 0;
}

