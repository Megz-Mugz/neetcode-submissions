class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output_arr = []
        for i in range(len(nums)):
            product = 1
            for j in range(len(nums)):
                if i != j:
                    product *= nums[j]
            print(product)
            output_arr.append(product)
        return output_arr            