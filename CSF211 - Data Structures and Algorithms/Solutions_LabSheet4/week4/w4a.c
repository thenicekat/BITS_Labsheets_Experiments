#include <stdio.h>
#include <stdlib.h>

/*
Problem A
Difficulty: Medium
Original Problem: https://leetcode.com/problems/merge-intervals/

We treat each slot as a pair of integers and sort the input array
of pairs. Sorting is O(nlogn).

Overlapping slots will be adjacent after sorting, so we can merge
them using two pointers. Finding merged slots is O(n).

Overall time complexity is O(nlogn).
*/

struct Slot_t
{
    int s;
    int e;
};
typedef struct Slot_t Slot;

int isLessThan(Slot sl1, Slot sl2)
{
    if (sl1.s < sl2.s)
        return 1;
    if (sl1.s == sl2.s && sl1.e < sl2.e)
        return 1;
    return 0;
}

void merge(Slot *a, int l1, int l2, int r2)
{
    int n1 = l2 - l1, n2 = r2 - l2;
    Slot *a1 = malloc(n1 * sizeof(Slot));
    Slot *a2 = malloc(n2 * sizeof(Slot));
    for (int i = 0; i < n1; ++i)
        a1[i] = a[l1 + i];
    for (int i = 0; i < n2; ++i)
        a2[i] = a[l2 + i];
    int i = l1, i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        if (isLessThan(a1[i1], a2[i2]))
        {
            a[i] = a1[i1];
            i1++;
        }
        else
        {
            a[i] = a2[i2];
            i2++;
        }
        i++;
    }
    while (i1 < n1)
    {
        a[i] = a1[i1];
        i++, i1++;
    }
    while (i2 < n2)
    {
        a[i] = a2[i2];
        i++, i2++;
    }
    free(a1);
    free(a2);
}

// Sorts [l, r) of array a
void sort(Slot *a, int l, int r)
{
    if (r - l > 1)
    {
        int m = (l + r) / 2;
        sort(a, l, m);
        sort(a, m, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Slot *slots = malloc(n * sizeof(Slot));
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &(slots[i].s));
        scanf("%d", &(slots[i].e));
    }
    sort(slots, 0, n);
    Slot *newSlots = malloc(n * sizeof(Slot));
    int k = 0;
    int l = 0;
    while (l < n)
    {
        int r = l;
        int snew = slots[l].s, enew = slots[l].e;
        while (r < n && slots[r].s <= enew)
        {
            if (enew < slots[r].e)
                enew = slots[r].e;
            r++;
        }
        newSlots[k].s = snew;
        newSlots[k].e = enew;
        k++;
        l = r;
    }

    printf("%d\n", k);
    for (int i = 0; i < k; ++i)
        printf("%d %d\n", newSlots[i].s, newSlots[i].e);

    free(slots);
    free(newSlots);

    return 0;
}