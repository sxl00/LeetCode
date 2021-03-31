#define _CRT_SECURE_NO_WARNINGS 1

//27. 移除元素
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

//使用双指针，若nums[j] != val,则赋给nums[i],每次赋值i+1 
int removeElement(int* nums, int numsSize, int val){
	int i = 0;
	for (int j = 0; j < numsSize; j++)
	{
		if (nums[j] != val)
		{
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}

//26. 删除有序数组中的重复项
//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

int removeDuplicates(int* nums, int numsSize){
	int i = 1;
	if (numsSize == 0) return 0;
	for (int j = 1; j < numsSize; j++)
	{
		if (nums[j - 1] != nums[j])
		{
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}

