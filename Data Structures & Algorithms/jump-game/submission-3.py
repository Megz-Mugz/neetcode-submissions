class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        if len(nums) == 1: return True
        
        goal_index = len(nums) - 1

        for idx in range(len(nums) - 2, -1, -1):
            
            if idx + nums[idx] >= goal_index:
                goal_index = idx # goal_index will be going down to 0
            

            if goal_index == 0: return True
        
        return False
