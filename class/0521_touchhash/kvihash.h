#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define uchar unsigned char
#define int32 unsigned int

struct hnode{
    uchar *key;
    uchar *val;
    int count;
    struct hnode *next;
};

struct hnode **HashTab; //  array of pointer

int32 maxHash;
