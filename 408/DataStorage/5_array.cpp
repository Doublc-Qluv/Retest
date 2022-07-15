#include "stdio.h"
#include "stdlib.h"
int bi_search(int a[], int n, int k)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == k)
        {
            printf("%d found at %d\n", k, mid + 1);
            return 1;
        }
        else if (a[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("%d not found\n", k);
    return 0;
}

void show_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int one_quick_sort(int a[], int low, int high)
{
    int i = low, j = high, pivot = a[low];
    while (i < j)
    {
        while (i < j && a[j] > pivot)
        {
            j--;
        }
        a[i] = a[j];
        while (i < j && a[i] <= pivot)
        {
            i++;
        }
        if (i < j)
            a[j] = a[i];
    }
    a[i] = pivot;
    // show_array(a);
    return i;
}

void quick_sort(int a[], int low, int high)
{
    int k;
    if (low < high)
    {
        k = one_quick_sort(a, low, high);
        quick_sort(a, low, k - 1);
        quick_sort(a, k + 1, high);
    }
}

int union_array(int a[], int b[], int *&c, int n, int m)
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j < m)
    {
        c[k] = b[j];
        k++;
        j++;
    }
    return 0;
}

int left_shift1(int a[], int n, int p) //时间O(p*n) 暴力算法
{
    int tmp;
    while (p > 0)
    {
        tmp = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = tmp;
        p--;
    }
    return 1;
}
int left_shift2(int a[], int n, int p)
{ //时间O(n) 空间O(p)
    int *c;
    int i;
    c = (int *)malloc(p * sizeof(int));

    for (i = 0; i < p; i++)
    {
        c[i] = a[i];
    }
    for (; i < n; i++)
    {
        a[i - p] = a[i];
    }
    for (i = 0; i < p; i++)
    {
        a[n - p + i] = c[i];
    }
    free(c);
    return 0;
}

int inverse_array(int a[], int low, int high)
{
    int i, j, tmp;
    i = low;
    j = high;
    while (i < j)
    {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
    return 1;
}
int left_shift3(int a[], int n, int p)
{
    inverse_array(a, 0, n - 1);
    inverse_array(a, 0, n - p - 1);
    inverse_array(a, n - p, n - 1);
    return 1;
}
int find_mid_array(int a[], int b[], int n, int m) // O(n)+O(n)
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    int *c;
    c = (int *)malloc(2 * n * sizeof(int));
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j < m)
    {
        c[k] = b[j];
        k++;
        j++;
    }
    return c[n - 1];
}

int find_mid_array2(int a[], int b[], int n, int m) // O(n)+O(1)
{
    int i, j, k, c;
    i = 0;
    j = 0;
    k = 0;
    c = 1;
    while (c < (m + n) / 2)
    {
        if (a[i] < b[j])
        {
            i++;
            c++;
        }
        else
        {
            j++;
            c++;
        }
    }
    if (a[i] < b[j])
        return a[i];
    else
        return b[j];
}

int find_mid_array3(int a[], int b[], int n)//分治法 O(logn)+O(1)
{
    int s1, e1, m1, s2, e2, m2;
    s1 = 0;
    e1 = n - 1;
    s2 = 0;
    e2 = n - 1;
    while (s1 != e1)
    {
        m1 = (s1 + e1) / 2;
        m2 = (s2 + e2) / 2;
        if (a[m1] == b[m2])
            return a[m1];
        else if (a[m1] > b[m2])
        {
            if ((e1 - s1 + 1) % 2 == 0)
            {
                e1 = m1;
                s2 = m2 + 1;
            }
            else
            {
                e1 = m1;
                s2 = m2;
            }
        }
        else
        {
            if ((e1 - s1 + 1) % 2 == 0)
            {
                s1 = m1;
                e2 = m2 + 1;
            }
            else
            {
                s1 = m1;
                e2 = m2;
            }
        }
    }
    if (a[s1] < b[s2])
        return a[s1];
    else
        return b[s2];
}

int main()
{
    // int a[10] = {2, 4, 6, 7, 8, 10, 12, 16, 17, 18};
    int a[5] = {3, 5, 7, 9, 10};
    int b[5] = {1, 4, 8, 12, 13};
    int n = 5, m = 5, p = 3;
    // int *c;
    // c = (int *)malloc(2 * n * sizeof(int));

    // show_array(a);//原始数组
    // bi_search(a, n, 11); //二分查找!!
    // one_quick_sort(a, 0, n - 1);// 一次快排!!
    // quick_sort(a,0,n-1);//快排!!
    // show_array(a);//完成结果

    // union_array(a, b, *&c, n, m);//合并数组!!

    show_array(a, n);

    // left_shift1(a, n, p);//删除插入
    // left_shift2(a, n, p);//开辟空间
    // inverse_array(a,0,n-1);//逆置
    // left_shift3(a,n,p);//再逆置

    // 归并求中位数
    int r;
    // r=find_mid_array(a,b,n,m);
    // printf("mid is %d\n",r);
    // show_array(a, n);

    // 改进的归并求中位数
    // r=find_mid_array2(a,b,n,m);
    // printf("mid is %d\n",r);
    r = find_mid_array3(a, b, n);
    printf("mid is %d\n", r);

    return 0;
}