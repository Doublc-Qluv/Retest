#include "stdio.h"
#include "stdlib.h"
#define Maxsize 30

typedef struct Sqlist
{
    int data[Maxsize];
    int length;
} sqlist;

int init_list(sqlist *&L) //初始化
{
    // int a[10] = {1, 2, 3, 4, 5, 6,               7, 8, 9, 10};
    int i;
    L = (sqlist *)malloc(sizeof(sqlist));
    // for (i = 0; i < 10; i++)
    // {
    //     L->data[i] = a[i];
    // }
    L->length = 0;
    return 1;
}

void destory_list(sqlist *L)
{
    free(L);
}

int empty_list(sqlist *L)
{
    if (L->length == 0)
    {
        printf("empty list\n");
        return 1;
    }
    else
        return 0;
}

int show_list(sqlist *L)
{
    int i;
    empty_list(L);
    for (i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
    return 1;
}

int get_num(sqlist *L, int i, int &e)
{
    if (i < 1 || i > L->length)
    {
        printf("error\n");
        return 0;
    }
    e = L->data[i - 1];
    printf("%d is %d\n", i, e);
    return 1;
}

int get_value(sqlist *L, int e)
{
    int i = 0;
    // for (i = 0; i < L->length; i++)
    // {
    //     if (L->data[i] == e)
    //     {
    //         break;
    //     }
    // }
    // or
    while (i < L->length && L->data[i] != e)
    {
        i++;
    }

    if (i == L->length)
    {
        printf("%d not exist", e);
        return 0;
    }
    else
        printf("%d found at %d\n", e, i + 1);
    return i + 1;
}

int insert_list(sqlist *L, int i, int e)
{
    int j;
    if (i < 1 || i > L->length + 1)
    {
        printf("error pos\n");
        return 0;
    }
    i = i - 1;
    for (j = L->length - 1; j >= i; j--)
    {
        L->data[j + 1] = L->data[j];
    }

    L->data[i] = e;
    L->length++;

    return 1;
}

int main()
{

    sqlist *L;
    int e,i;
    printf("\nwendu 2023\n");
    init_list(L);

    // empty_list(L);
    // show_list(L);

    // get_num(L, 11, e);

    // get_value(L, 8);
    // insert_list(L, 3, 100);
    // show_list(L);

    for (i = 0; i < 10; i++)
    {
        insert_list(L,1,i+1);
        show_list(L);
    }
    


    destory_list(L);
    // printf("length: %d \n", L->length);
    return 0;
}