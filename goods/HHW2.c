#include <stdio.h>
#include <stdlib.h>
struct stdata {
		char name[100],phone[100],mail[100];
        int  ID;
};

int insert(char line[],struct stdata std[],int count)
{
	if(ptr=strstr(line,"ID:"))
	{
		ptr=ptr+3;
		std[count].ID=atoi(*ptr);
	}
	if(ptr=strstr(line,"name:"))
	{
		ptr+=5;	
		qtr=std[count].name;	
		while(*ptr!='\t')
		{
		  *qtr++ = *ptr++;
		  *qtr = '\0';
		}
	}
	if(ptr=strstr(line,"phone:"))
	{
		ptr+=6;
		std[count].phone=
	}
}

int delete()
{
	
}

int update()
{

}

int find()
{

}

int list()
{

}

int main()
{
	int count;	
	char *ptr, *qtr;	
	struct stdata std[100];	
	char line[100];	
	count=0;
	while(fgets(line,100,stdin)!=NULL)
	{
		if(line[0]=='i')
		{
			if(ptr=strstr(line,"studentID:"))
			{		
				ptr=ptr+10;
				std[].ID=atoi(*ptr);
			}
		}
		else if(line[0]=='d')
		{
		
		}
		else if(line[0]=='u')
		{
		
		}
		else if(line[0]=='f')
		{
		
		}
		else if(line[0]=='l')
		{
		
		}
        else
		{
		
		}
	}
}
