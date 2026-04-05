class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        dict = {}

        curr = 0;
        runner = 1

        while (len(dict) != len(nums)):

            dict.update({nums[curr] : curr})

            print(dict)

            print('curr' + str(curr))
            print('runner:' + str(runner))

            if (nums[curr] + nums[runner] == target):
                print(f'{nums[curr]} + {nums[runner]}')
                return [dict[nums[curr]], runner]
            elif (runner == len(nums) - 1):
                curr += 1
                runner = curr + 1
            else:
                runner += 1
