function countSubarrays(nums: number[]): number {
  let i = 0;
  let counter = 0;

  while (nums.length - i >= 3) {
    if (nums[i] + nums[i + 2] === nums[i + 1] / 2) {
      counter++;
    }

    i++;
  }

  return counter;
}
