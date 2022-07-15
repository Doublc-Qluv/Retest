#include "stdio.h"
#include "stdlib.h"

typedef struct LinkList
{
    int data;
    struct LinkList *next;
} LinkNode; // *LinkList;

void show_linklist(LinkNode *L)
{
    LinkNode *p;
    p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int create_linklist_head(LinkNode *&L, int a[], int n)
{
    int i;
    LinkNode *p;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (i = 0; i < n; i++)
    {
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
    return 1;
}

int length_linklist(LinkList *L){
    LinkList *p;
    int c=0;
    p=L->next;
    while(p!=NULL){
        c++;p=p->next;
    }
    return c;
}

int search_kth_linklist(LinkList *&L, int k) //!
{
    LinkList *p;
    int c = 1;
    p->next;
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

//求倒数第k个位置的data

// 1.求总共长度
// 2.求n-k+1
// O(n)+O(1)

int find_inverse_kth(LinkList *L, int k)//!
{
    int n, m;
    n = length_linklist(L);
    if (k < 1 || k > n)
    {
        printf("%d error\n", k);
        return 0;
    }
    m = n - k + 1;
    search_kth_linklist(L, m);
    return 1;
}

//单链表改成数组O(n)+O(N)

//利用双指针
// 1) 前后 pre 和 p
// 2) 快慢 等距运动, 当前题目 2*n + O(1)
// 3) 左右(快排)

int find_inverse_kth2(LinkList *L, int k)
{
    LinkList *p, *q;
    int c;
    p = L;
    q = L->next;
    c = 1;
    while (q != NULL)
    {
        c++;
        if (c > k)
        {
            p = p-> next;
        }
        q = q->next;
    }
    if (p == L)
    {
        printf("%d error\n", k);
        return 0;
    }
    else
    {
        printf("%d is found at %d\n" ,k,p->data);
        return 1;
    }
}


int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    LinkNode *L;
    create_linklist_head(L, a, n);
    show_linklist(L);
    // search_kth_linklist(L,a,3);
    // find_inverse_kth(L,3);
    find_inverse_kth2(L,3);
    return 0;
}
