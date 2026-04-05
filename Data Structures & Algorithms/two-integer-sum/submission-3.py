class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        dict = {} # dictionary w/ key value pairs

        for  i in range(len(nums)):
            focus_num = nums[i] # number we are currently on

            complement_num = target - focus_num # check if the neccessary number is in the dictionary

            if (complement_num in dict):
                return [dict[complement_num], i] # if the complement_num is alr in the dictionary, yk it's based on the previous math that it will add up to target, hence just return the indexes

            dict[nums[i]] = i # as u iterate thru array, put values in the dictionary
        
        return [] # incase blank
