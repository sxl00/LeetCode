#define _CRT_SECURE_NO_WARNINGS 1
//88. 合并两个有序数组

//给你两个有序整数数组 nums1 和 nums2，
//请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)  //写的继续的条件
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	//如果是end2还有数据，则需要继续挪动、
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}

	//若是end1还有数据，则不需要挪动数据 


}

//189. 旋转数组

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

void Reverse(int* num, int left, int right)
{
	while (left < right)
	{
		int tmp = num[left];
		num[left] = num[right];
		num[right] = tmp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k){
	k %= numsSize;   //k>数组的个数，需要取模
	Reverse(nums, 0, numsSize - k - 1);
	Reverse(nums, numsSize - k, numsSize - 1);
	Reverse(nums, 0, numsSize - 1);
}