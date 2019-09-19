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
    //current��ɭԷ|�u��i��ơA�������s����C���v�A�ҥH�ݭn�t�m�O����Ŷ�
    current=(Node*)malloc(sizeof(Node));
    //��l�ƩҦ����
    current->ID=0;
    current->name[0]='\0';
    current->phone[0]='\0';
    current->mail[0]='\0';
    return current;
}
//�`�N�^�ǫ��A
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
    //head�@�}�l�O�Ū��A����~�|�C�C���W�h�A�O�o�n�e�h�t�m�O����M��l��
    head=get_node(head);

    print_hint();
    while(fgets(line,100,stdin)!=NULL)
    {
        Operation=line[0];

        //first�O�P�_�O���O�Ĥ@����J��ơA�u�n��J�L��Ƥ���Afirst���ȷ|�ܦ�0
        //�ڪ�����first����m�L�h�A�ҥH�p�G���F��ʡA�ڥi�H���ίS�O�^�ǥL�A�]���ڷQ�n�^�ǧڪ��s����C
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
Node *insert_data(Node *current,char line[])//�]����JID���H�~����Ƹ��������A�ҥH�گS�O��L�����X��
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
//�ˬd���S�����ƪ�ID�Aflag�������S���J�쭫�ƪ�ID
//�^�Ǫ�ptr�N�O���ƪ�����m�A�ڥi�H�����B�z
{
    *flag=1;
    ptr=head;
    while(ptr!=NULL) //�ˬd���S�����ƪ�ID
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
//��J�`�I�Ҧ����
{
    char *p;
    Node *current=NULL;
    Node *ptr=NULL,*qtr=NULL;
    int tem,flag;
    //�O�ocurrent���n�e�L�h�t�m�Ŷ��M��l��
    current=get_node(current);

    if((p=strstr(line,"ID")))
    {
        p=p+3;
        tem=atoi(p);

        //�p�G�O�Ĥ@����J���first�|�O1
        //�N�������Ʃ�ihead
        if(*first)
        {
            //first�ন0�A�N�A�]���|�i�o��if�F
            *first=0;
            //�]���S�Ψ�current�N�nfree��
            free(current);

            head->ID=tem;
            //�p�G��C�᭱�S�F��F�A�O�o�������VNULL
            head->next=NULL;
            //��ID�H�~����ƿ�J
            head=insert_data(head,line);
            printf("Insert successful!\n");
            return head;
        }
        else
        //�ĤG����J�}�l�N�|�i�ӳo��
        {
            //���ˬd���S���ƪ�ID
            ptr=check_duplication(head,tem,ptr,&flag);
            if(flag==0)//�X�{����ID
            {
                //�S�Ψ�current�N�nfree��
                free(current);
                printf("Insert error! studentID is exists!\n");
                return head;
            }

            //�p�G�S�����ƴN���|�i�W����if�A�����U��
            //����ID��i�h�Anext���VNULL
            current->ID=tem;
            current->next=NULL;

			//�o��}�l��ثe��������ө�b����
            if(current->ID<head->ID) //�p�G�L�@�}�l�N��head�p�A�N�����L���bhead�e��
            {
                current->next=head;
                head=current;//�M��L�N�Ohead�F
            }
            else
            //�p�G�L�S����head�p�A�N��N�O�|�b�����άO�̫᭱(�o�ܫ���)
            {
                ptr=head;
                //���current���T����m
                while(ptr->next!=NULL)
                {
                    qtr=ptr->next;
                    if(qtr->ID>current->ID) break;
                    //�p�Gcurrent�O�ݩ�b���������p�Aptr�N�Ocurrent���e���Aqtr(ptr->next)�N�Ocurrent���᭱
                    ptr=ptr->next;
                }
                if(ptr->next==NULL)//�p�Gptr�O��C�����A�N��current����̫�
                {
                    ptr->next=current;
                    current->next=NULL;//�O�o�̫�n���VNULL
                }
                else//�p�G�L���O�b�����A��M�N�O�b������
                {
                    current->next=ptr->next;
                    ptr->next=current;
                }
            }

            //��ID�H�~����Ƴ���i�h
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

    //�ˬd���S�����ƪ�ID
    ptr=check_duplication(head,tem,ptr,&flag);
    if(flag==0)//�X�{����ID
    {
        if(ptr==head)//�p�Gptr�N�Ohead
            //������head���V����head�����U�@�ӪF��
            head=head->next;
        else//�p�Gptr���O�}�Y�A�N��n�R������ƴN�O�b�����άO�b�̫�(�@�˼o�ܫ���)
        {
            //��qtr��L���U�@�ӬO���Optr�A�n���Dptr���e�@�ӧڭ̤~����⤣�n���F��ޱ�
            qtr=head;
            while(qtr->next!=ptr) qtr=qtr->next;

            if(ptr->next==NULL)//�p�Gptr�O��C������
                //�]��qtr�Optr���W�@�ӡA�N������qtr���V�����N�n
                qtr->next=NULL;
            else qtr->next=ptr->next;//�]��qtr�Optr���W�@�ӡA�N������qtr���Vptr���U�@�ӡA�]�N�Oqtr���U�@�Ӫ��U�@��
        }

        free(ptr);//ptr�ثe�٫��ۧڭ̭n�ޱ����U���A�ҥH�N��Lfree���a
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

    //�@���ˬd���S�����ƪ�ID
    ptr=check_duplication(head,tem,ptr,&flag);
    if(flag==0)//�X�{����ID
    {
        //�����R�����ʧ@
        if(ptr==head)//�p�Gptr�O�Ĥ@��node
            head=head->next;
        else
        {
            qtr=head;
            while(qtr->next!=ptr) qtr=qtr->next;


            if(ptr->next==NULL)//�p�Gptr�O��C������
                qtr->next=NULL;
            else qtr->next=ptr->next;
        }
        free(ptr);

        //�����R���A����J
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
            //���current���T����m
            while(ptr->next!=NULL)
            {
                qtr=ptr->next;
                if(qtr->ID>current->ID) break;
                ptr=ptr->next;
            }
            if(ptr->next==NULL)//�p�Gptr�O��C����
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

        //�A��ID�H�~����Ƴ���i�h
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

    //�����Xspat
    i=2;
    j=0;
    while(line[i]!=' '&&line[i]!='\n')
    {
        spat[j++]=line[i++];
    }
    spat[j]='\0';

    //�p�G���strstr���N�@�Ӧ^��1�A�N����ǰt���r���A�N��L�Ҧ�����Ƴ��L�X��
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
            //flag�ΨӧP�_�A�쩳���S�����ǰt�����
            flag=1;
        }
        ptr=ptr->next;
    }
    //�p�Gflag�^��0�A�N��ڥ��S�����ǰt���r��
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
        ptr=ptr->next;//�O�o�L���n��ptr���V�U�@�ӡA�n���Mptr�û������|�]
    }
    return 0;
}
