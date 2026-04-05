class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        left_side_product = []
        right_side_product = [0] * len(nums)

        for i in range(len(nums)):
            if i > 0:
                left_side_product.append(left_side_product[-1] *  nums[i])
            else:
                left_side_product.append(nums[i])
        
        for i in range(len(nums)-1, -1, -1):
            if i == len(nums) - 1:
               right_side_product[i] = nums[i]
            else:
                right_side_product[i] = right_side_product[i+1] * nums[i]
        
        final_arr = []
        print(left_side_product, right_side_product)
        for i in range(len(nums)):
            if i == 0:
                final_arr.append(right_side_product[i+1])
            elif i == len(nums) - 1:
                final_arr.append(left_side_product[i-1])
            else:
                final_arr.append( left_side_product[i-1] * right_side_product[i+1])
        
        return final_arr
        
        