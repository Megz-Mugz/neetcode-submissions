class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output_arr = []

        for index in range(len(nums)):
            # left product
            left_product = 1

            left_ptr = 0
            while (left_ptr < index):
                left_product *= nums[left_ptr]
                left_ptr += 1
            print(left_product)

            # right product
            right_product = 1

            right_ptr = len(nums) - 1
            while (right_ptr > index):
                right_product *= nums[right_ptr]
                right_ptr -= 1
            print(right_product)

            output_arr.append(left_product * right_product)     
        return output_arr    