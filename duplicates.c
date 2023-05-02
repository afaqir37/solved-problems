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