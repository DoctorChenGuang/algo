signed int maxValue(a, b, c)
{
  signed int pre = a > b ? a : b;
  pre = pre > c ? pre : c;
  return pre;
}

int maxSubArray(int *nums, int numsSize)
{
  signed int dp[numsSize], dp1[numsSize];
  dp[0] = nums[0];
  dp1[0] = nums[0];
  for (int i = 1; i < numsSize; i++)
  {
    dp1[i] = nums[i] + maxValue(nums[i - 1], dp1[i - 1], 0);
    dp[i] = maxValue(dp[i - 1], nums[i], dp1[i]);
  }
  return dp[numsSize - 1];
}

// 测试用例：[-2,1,-3,4,-1,2,1,-5,4]
// 空间复杂度以及空间复杂度均可优化