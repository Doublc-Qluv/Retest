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
        s->next = NULL;
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

int create_link_tail(linklist *&L, int a[], int n)
{
    linklist *r, *s;
    int i;
    L = (linklist *)malloc(sizeof(linklist));
    L->next = NULL;
    r = L;
    for (i = 0; i < n; i++)
    {
        s = (linklist *)malloc(sizeof(linklist));
        // s->next=NULL;//点明尾结点
        s->data = a[i];
        r->next = s;
        r = s;
    }
    s->next = NULL; //点明尾结点
    return 1;
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

// 判空

int empty_list(linklist *L)
{
    return (L->next == NULL);
}

//长度

int length_link(linklist *L)
{
    linklist *p;
    int c = 0;
    p = L->next; // p=L;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int get_elem_link(linklist *L, int i, int e) //按位查找
{
    int j = 0;
    linklist *p = L;
    while (j < i && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {

        printf("the %dth is not found\n", i);
        return 0;
    }
    else
    {
        printf("the %dth is %d\n", i, p->data);
        e = p->data;
        return 1;
    }
}
int locate_elem_link(linklist *L, int e) // 按值查找
{
    int i = 1;
    linklist *p = L->next;
    while (p != NULL && p->data != e)
    {
        i++;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("%d is not found\n", e);
        return 0;
    }
    else
    {
        printf("%d is found at %dth\n", p->data, i);
        return i;
    }
}

int insert_link(linklist *&L, int i, int e)
{
    int j = 0;
    linklist *p = L, *q;
    while (p != NULL && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("%d illgeal\n", i);
        return 0;
    }
    else
    {
        q = (linklist *)malloc(sizeof(linklist));
        q->data = e;
        q->next = p->next; // 指向后链
        p->next = q;       // 链接前链
        return 1;
    }
}

int del_link(linklist *L, int i, int &e)
{
    int j = 0;
    linklist *p = L, *q;
    while (p != NULL && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("%d illgeal\n", i);
        return 0;
    }
    else
    {
        q = p->next; // 取后链
        if (q == NULL)
        {
            printf("%d illgeal\n", i);
            return 0;
        }
        e = q->data; //取值
        printf("%d deleted\n", e);
        p->next = q->next; // 目标的后链链接前点
        free(q);           // 释放
        return 1;
    }
}

int del_all_key(linklist *L, int e)
{
    int j = 0;
    linklist *p = L, *q;
    while (p != NULL)
    {
        if (p->data == e)
        {
            q = p->next;
            p->next == q->next;
            free(q);
        }
        j++;
        p = p->next;
    }
    return 1;
}

int del_link_a_value(linklist *L, int e)
{
    linklist *pre, *p;
    pre = L;
    p = L->next;
    while (p != NULL)
    {
        if (p->data == e)
        {
            break;
        }
        pre = p;
        p = p->next;
    }
    if (p != NULL)
    {
        pre->next = p->next;
        free(p);
        return 1;
    }
    else
    {
        printf("%d not exist\n", e);
        return 0;
    }
}

int del_link_all_value(linklist *L, int e)
{
    linklist *pre, *p;
    pre = L;
    p = pre;
    while (p != NULL)
    {
        if (p->data == e)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return 1;
}

int set_link_value(linklist *L)
{
    linklist *p, *q, *pt;
    p = L;
    while (p != NULL)
    {
        q = p;
        pt = p->next;
        while (pt != NULL)
        {
            if (pt->data == p->data)
            {
                q->next = pt->next;
                free(pt);
                pt = q->next;
            }
            else
            {
                q = pt;
                pt = q->next;
            }
        }
        p = p->next;
    }
    return 1;
}
int merge_link(linklist *&La, linklist *&Lb, linklist *&Lc)
{
    linklist  *pa, *pb, *pc, *ptr;
    pa = La->next;
    pb = Lb->next;
    Lc=La;
    Lc->next=NULL;
    pc=Lc;
    free(Lb);
    while (pa != NULL && pb != NULL)
    {
        if (pa->data < pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa != NULL)
        pc->next = pa;
    else
        pc->next = pb;

    return 1;
}

int main()
{
    int a[5] = {2, 3, 8, 10, 12};
    int b[5] = {11, 13, 14, 16, 18};
    int n = 5;
    linklist *L;
    int e;
    // create_link_head(L, a, 5);
    // show_link(L);

    // create_link_head2(L,a,5);
    create_link_tail(L, a, n);
    linklist *L2;
    linklist *L3;
    create_link_tail(L2, b, n);

    show_link(L); //带有头结点的展示
    show_link(L2);
    int getnum = 5;
    // get_elem_link(L, getnum, e);
    // printf("length of link is %d\n",length_link(L));

    int f = 2;
    // locate_elem_link(L, f);
    // destory_link(L);
    // search_kth_link(L, 3);

    // insert_link(L, 1, 100);
    // del_link(L, 6, e);
    // del_link_a_value(L, 8);
    // del_link_all_value(L, 8);
    // set_link_value(L);
    merge_link(L, L2,L3);
    show_link(L3);
    return 0;
}