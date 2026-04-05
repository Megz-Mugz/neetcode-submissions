class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left_ptr = 0
        right_ptr = len(numbers) - 1
        sum_of_nums = numbers[left_ptr] + numbers[right_ptr]
        while(sum_of_nums != target):
            if(sum_of_nums < target):
                left_ptr +=1
            else:
                right_ptr -=1
            sum_of_nums = numbers[left_ptr] + numbers[right_ptr]
        return [left_ptr + 1, right_ptr + 1]