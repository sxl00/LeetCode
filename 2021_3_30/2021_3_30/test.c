#define _CRT_SECURE_NO_WARNINGS 1

//261 只出现一次的数字 III
//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。
//找出只出现一次的那两个元素。你可以按 任意顺序 返回答案

int* singleNumber(int* nums, int numsSize, int* returnSize){
	int x = 0, y = 0;

	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}

	//从低到高去找ret里面一个为1的位
	int j = 0;
	for (j = 0; j < 32; j++)
	{
		if (ret >> j & 1)
			break;
	}

	//将原数组分为两组，第j位为1的为一组，j位为0的为一组
	//int x = 0;
	//int y = 0;
	for (int k = 0; k < numsSize; k++)
	{
		if ((nums[k] >> j) & 1)   //不能左移，会到符号位上
		{
			x ^= nums[k];
		}
		else
		{
			y ^= nums[k];
		}
	}
	int* arr = (int*)malloc(sizeof(int)* 2);
	arr[0] = x;
	arr[1] = y;
	*returnSize = 2;

	return arr;
}


//剑指 Offer 56 - I.数组中数字出现的次数
//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。
//要求时间复杂度是O(n)，空间复杂度是O(1)。

int* singleNumbers(int* nums, int numsSize, int* returnSize){
	int* arr = (int *)malloc(sizeof(int)* 2);
	*returnSize = 2;

	int n1 = 0;
	int n2 = 0;

	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];  //这是两个不同数异或的结果
	}
	//找出第一位为1 的位置
	int pos = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}

	//把arr数组中每隔元素中二进制的第pos位为1的全部异或在一起
	for (int i = 0; i < numsSize; i++)
	{
		if (((nums[i] >> pos) & 1) == 1)
		{
			n1 ^= nums[i];
		}
	}

	n2 = ret^n1;
	arr[0] = n1;
	arr[1] = n2;

	return arr;
}

//面试题 17.04. 消失的数字
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。
//你有办法在O(n)时间内完成吗？

//采用求和相减的方法
int missingNumber(int* nums, int numsSize){
int n = numsSize + 1;
int ret1 = 0;
for(int i = 0; i < n; i++)
{
ret1 += i;
}

int ret2 = 0;
for(int j = 0; j < numsSize; j++)
{
ret2 += nums[j];
}

return ret1 - ret2;
}


//采用异或方法
int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	for (int i = 0; i < numsSize + 1; ++i)
	{
		x ^= i;
	}
	for (int j = 0; j < numsSize; ++j)
	{
		x ^= nums[j];
	}

	return x;
}
