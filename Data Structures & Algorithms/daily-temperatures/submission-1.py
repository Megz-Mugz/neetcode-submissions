class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        stack = []
        output = [0] * len(temperatures)

        for index, temperature in enumerate(temperatures):
            
            while stack and stack[-1][0] < temperature:
                temp, index_of_temp = stack.pop()
                output[index_of_temp] = index - index_of_temp

            stack.append([temperature, index])
            
        return output