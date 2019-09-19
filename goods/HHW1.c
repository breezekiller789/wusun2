#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int replace(char line[],char *tpat,char *spat)
{
	char *ptr;
	int i,len2,len3;

    ptr=strstr(line,tpat);
   // len1=strlen(line);
    len2=ptr-line;
    len3=strlen(tpat); 

    for(i=0;i<len2;i++)
	{
	   printf("%c",line[i]); //print你要的字串前面的東西
	} 

    printf("%s",spat);
    ptr+=len3;               //因為要插入你要插入的東西
    printf("%s",ptr);        //ptr現在指的是spat後面整個的東西

	return 0;
}

int main(int argc,char *argv[])
{
  int i,lenth;		
  char line[1001];
  char *tpat=NULL,*spat=NULL;
  while(fgets(line,1001,stdin)!=NULL)
  {
  	lenth=strlen(line);	  
  	for(i=0;i<argc;i++)
	{
	   if(argv[i][0]=='-')
	   {
	     if(argv[i][1]=='s')
		 {
		    tpat=argv[i+1];
		    spat=argv[i+2];
		    replace(line,tpat,spat);
		 }
		 else if(argv[i][1]=='l')
		 {
		    for(i=0;i<lenth;i++)
			{
			  if((line[i]>='A')&&(line[i]<='Z')){
			  		  line[i]+=32;}
			  printf("%c",line[i]);
			}
		 }
		 else if(argv[i][1]=='r')
		 {
		    for(i=0;i<lenth;i++)
			{
			  if(line[i]!=' ')
			  		  printf("%c",line[i]);
			  else if(i>0&&(line[i-1]==' ')&&(line[i]==' '))
			  		  continue;
              else if(i>0&&(line[i-1]!=' ')&&(line[i]==' '))
              		  printf("%c",line[i]);
			}
		 }
	   }
	}
  }		  
  return 0;
}
