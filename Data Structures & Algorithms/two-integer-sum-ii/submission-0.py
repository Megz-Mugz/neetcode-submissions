class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left_ptr = 0
        right_ptr = len(numbers) - 1
        while(numbers[left_ptr] + numbers[right_ptr] != target):
            if(numbers[left_ptr] + numbers[right_ptr] < target):
                left_ptr +=1
            else:
                right_ptr -=1
        return [left_ptr + 1, right_ptr + 1]