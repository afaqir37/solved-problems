// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
// To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    (void)nums1Size;
    (void)nums2Size;
    
    int j = m - 1;
    int i = n - 1;
    int k = m + n - 1;

    while (i >= 0)
    {
       if (j >= 0 && nums2[i] < nums1[j])
            nums1[k--] = nums1[j--];
        else
            nums1[k--]  = nums2[i--];
    }
   
}
int main()
{
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    int m = 3;
    int n = 3;
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2Size = sizeof(nums2) / sizeof(int);
    merge(nums1, nums1Size, m, nums2, nums2Size, n);
    int i;
    for (i = 0; i < m + n; i++)
        printf("%d ", nums1[i]);
    return 0;

}