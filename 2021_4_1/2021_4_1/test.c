#define _CRT_SECURE_NO_WARNINGS 1

//移除==val的数
int removeElenment(int* nums, int numsSize, int val)
{
	int src = 0, dst = 0;
	while (nums[src] < numsSize)
	{
		if (nums[src] == val)
		{
			++src;
		}
		else
		{
			nums[dst] = nums[src];
			++src;
			++dst;
		}
	}
	return dst;
}

//删除有序数组重复项
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int dst = 0;
	int cur = 0;
	int next = 1;
	while (next < numsSize)
	{
		if (nums[cur] != nums[next])
		{
			nums[dst++] = nums[cur++];
			++next;
		}
		else
		{
			while (next < numsSize && nums[cur] == nums[next])
			{
				++next;
			}
			nums[dst] = nums[cur];
			++dst;
			cur = next;
			next++;
		}
	}
	if (cur <numsSize)
	    nums[dst] = nums[cur];
	return dst;
}


//989. 数组形式的整数加法
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
//例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int kSize = 0;  //K的位数
	int num = K;
	while (num)  //求位数
	{
		++kSize;
		num /= 10;
	}
	int len = kSize > ASize ? (kSize + 1) : (ASize + 1);//进位最多加1
	int* retArr = (int*)malloc(sizeof(int)*len);
	int Ai = ASize - 1;  //A数组从后取值
	int Ki = 0;
	int next = 0; //进位
	int reti = 0;   //数据个数
	while (Ai >= 0 || Ki < kSize)
	{
		int aVal = 0;
		//判断A数组中是否有值
		if (Ai >= 0)
		{
			aVal = A[Ai--];
		}
		int kVal = 0;
		kVal = K % 10;
		K /= 10;
		Ki++;

		int ret = aVal + kVal + next;
		if (ret >= 10)
		{
			next = 1;
			ret -= 10;
		}
		else
		{
			next = 0;
		}
		retArr[reti++] = ret;  //值从前往后存储

	}
	if (next == 1)
	{
		retArr[reti++] = 1;
	}
	int begin = 0, end = reti - 1;
	//值逆置
	while (begin < end)
	{
		int tmp = retArr[begin];
		retArr[begin] = retArr[end];
		retArr[end] = tmp;
		++begin;
		--end;
	}
	*returnSize = reti;
	return retArr;
}

