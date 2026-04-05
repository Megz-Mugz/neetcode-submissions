class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # calc prefix
        prefix = [nums[0]]
        for idx in range(1, len(nums)):
            prefix.append(nums[idx] * prefix[idx - 1])
        # calc postfix
        postfix = [0] * len(nums)
        for idx in range(len(nums)-1, -1, -1):
            if idx == len(nums) - 1:
                postfix[idx] = nums[idx]
            else:
                postfix[idx] = nums[idx] * postfix[idx + 1]

        output = []
        print(prefix)
        print(postfix)
        for idx in range(len(nums)):
            pre = 1 if idx-1 < 0 else prefix[idx - 1]
            post = 1 if idx+1 >= len(nums) else postfix[idx + 1]
            print(f'pre:{pre} post:{post}')
            output.append(pre * post)
        return output