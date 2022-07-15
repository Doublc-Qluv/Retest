#include "stdio.h"
#include "stdlib.h"

typedef struct Linklist
{
    int data;
    struct Linklist *next;
} linklist;

void show_link(linklist *L)
{
    linklist *p;
    p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void show_link2(linklist *L)
{

    linklist *p;
    p = L;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 有头节点的头插法
int create_link_head(linklist *&L, int a[], int n)
{
    linklist *s;
    int i;
    L = (linklist *)malloc(sizeof(linklist));
    L->next = NULL;
    for (i = 0; i < n; i++)
    {
        s = (linklist *)malloc(sizeof(linklist));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
        // show_link(L);
    }

    return 1;
}
// 没有头结点的头插法
int create_link_head2(linklist *&L, int a[], int n)
{
    linklist *s;
    int i;
    L = NULL;
    for (i = 0; i < n; i++)
    {
        s = (linklist *)malloc(sizeof(linklist));
        s->next=NULL;
        s->data = a[i];
        if (L == NULL)
        {
            L = s;
        }
        else
        {
            s->next = L;
            L = s;
        }
        show_link2(L);
    }

    return 1;
}

int length_link(linklist *L)
{
    linklist *p;
    int c = 0;
    p = L->next;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

//基本运算

//初始化
void init_link(linklist *L)
{
    L = (linklist *)malloc(sizeof(linklist));
    L->next = NULL;
}

//销毁

void destory_link(linklist *&L)
{
    linklist *p = L, *q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}

int search_kth_link(linklist *L, int k)
{
    linklist *p;
    p = L->next;
    int c = 1;
    while (p != NULL && c < k)
    {
        c++;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("%d not exist\n", k);
        return 0;
    }
    else
    {
        printf("%d is found, value is %d\n", k, p->data);
        return 1;
    }
}

int main()
{
    int a[5] = {2, 3, 8, 10, 12};
    int n = 5;
    linklist *L;
    // create_link_head(L, a, 5);
    // show_link(L);

    create_link_head2(L,a,5);
    show_link2(L);

    // printf("length of link is %d\n",length_link(L));

    // search_kth_link(L, 3);
    return 0;
}