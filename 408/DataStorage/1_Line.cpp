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
    // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
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

int delete_list(sqlist *L, int i, int &e)
{
    int j;
    if (i < 1 || e > L->length)
    {
        printf("%d is error\n", i);
        return 0;
    }
    i--;
    e = L->data[i];
    for (j = i; j < L->length - 1; j++)
    {
        L->data[j] = L->data[j + 1];
    }
    printf("%d ele %d is deleted\n", i + 1, e);
    L->length--;
    return 1;
}

int main2()
{

    sqlist *L;
    int e, i;
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
        insert_list(L, 1, i + 1);
    }
    show_list(L);
    delete_list(L, 3, e);
    show_list(L);
    destory_list(L);
    // printf("length: %d \n", L->length);
    return 0;
}

// 数组合并

int union_array(int a[], int n, int b[], int m, int *&c)
{
    int i, j, k;
    c = (int *)malloc((m + n) * sizeof(int));
    i = 0;
    j = 0;
    k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    return 1;
}

int main()
{
    int a[5] = {2, 3, 8, 10, 12};
    int b[10] = {1, 3, 7, 9, 16, 18, 19, 20, 22, 25};
    int *c, i;
    union_array(a, 5, b, 10,c);

    for (i = 0; i < 15; i++)
        printf("%d ", c[i]);

    free(c);
    printf("\n");
    return 0;
}