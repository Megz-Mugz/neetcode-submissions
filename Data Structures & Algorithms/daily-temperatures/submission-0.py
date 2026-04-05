class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        stack_of_temps = []

        result = [0] * len(temperatures)
        
        for index, temp in enumerate(temperatures):
            while (stack_of_temps and temp > stack_of_temps[-1][1]): 
                stackIndex, stackTemp = stack_of_temps.pop()
                result[stackIndex] = index - stackIndex
                
            stack_of_temps.append((index, temp))
        return result