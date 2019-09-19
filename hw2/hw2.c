#include <stdio.h>
#include <string.h>
#define MaxLine 1024
#define MaxName 100
#define MaxEmail 100
#define MaxNumber 50
 
int main(){
        char line[MaxLine];
        struct Student_Data{
                char name[MaxName];
                char email[MaxEmail];
                char number[MaxNumber];
        }stu;
        strcpy(stu.name, "Willy");
        strcpy(stu.email, "Willy@gmail.com");
        strcpy(stu.number, "0912123123");
        printf("Name =%s\n", stu.name);
        printf("Email =%s\n", stu.email);
        printf("Phone Number =%s\n", stu.number);
        return 0;
 
}
