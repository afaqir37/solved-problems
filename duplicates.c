/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.
Return k. */

#include <stdio.h>
int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int j = numsSize - 1;
    int *slow = nums;
    int *fast = nums;
    int k = 0;
    while(i < numsSize - k && j >= 0)
    {
        if (nums[i] == val)
        {
            k++;
            int tmp = nums[i];
            nums[i] = fast[j];
            fast[j] = tmp;
            j--;
        }
        else 
            i++;
    }
  
    return (numsSize - k);

}

int main(void)
{
    int arr[] = {0,1,2,2,3,0,4,2};
    int k = removeElement(arr, 8, 2);
    printf("\n%d", k);
}
