/*
Box Stacking Problem: Assume that we are given a set of n rectangular 3–D boxes. The dimensions of ith box are height hi, width wi and depth di. Now we want to create a stack of boxes which is as tall as possible, but we can only stack a box on top of another box if the dimensions of the 2 –D base of the lower box are each strictly larger than those of the 2–D base of the higher box. We can rotate a box so that any side functions as its base. It is possible to use multiple instances of the same type of box.
Solution: Box stacking problem can be reduced to LIS (longest increasing subsequence)
*/

#include <bits/stdc++.h>
using namespace std;

struct Box
{
    int h, w, d;
};

int compare(const void *a, const void *b)
{
    return ((*(Box *)b).d * (*(Box *)b).w) - ((*(Box *)a).d * (*(Box *)a).w);
}

int maxStackHeight(Box arr[], int n)
{
    Box rot[3 * n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        // Copy the original box
        rot[index].h = arr[i].h;
        rot[index].d = max(arr[i].d, arr[i].w);
        rot[index].w = min(arr[i].d, arr[i].w);
        index++;

        // First rotation of box
        rot[index].h = arr[i].w;
        rot[index].d = max(arr[i].h, arr[i].d);
        rot[index].w = min(arr[i].h, arr[i].d);
        index++;

        // Second rotation of box
        rot[index].h = arr[i].d;
        rot[index].d = max(arr[i].h, arr[i].w);
        rot[index].w = min(arr[i].h, arr[i].w);
        index++;
    }
    // Now the number of boxes is 3n
    n = 3 * n;

    /* Sort the array 'rot[]' in non-increasing order of base area */
    qsort(rot, n, sizeof(rot[0]), compare);

    /*Initialize msh values for all indexes msh[i]--> Maximum possible Stack Height with box i on top */
    int msh[n];
    for (int i = 0; i < n; i++)
        msh[i] = rot[i].h;

    /* Compute optimized msh values in bottom up manner */
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (rot[i].w < rot[j].w && rot[i].d < rot[j].d && msh[i] < msh[j] + rot[i].h)
            {
                msh[i] = msh[j] + rot[i].h;
            }
        }
    }
    /* Pick maximum of all msh values */
    int max = -1;
    for (int i = 0; i < n; i++)
        if (max < msh[i])
            max = msh[i];

    return max;
}

int main()
{
    Box arr[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The maximum possible height of stack is %d\n",
           maxStackHeight(arr, n));
    return 0;
}