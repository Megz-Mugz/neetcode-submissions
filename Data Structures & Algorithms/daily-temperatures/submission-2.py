class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # brute force -> 2 for loops, inner one is to see when outer < inner O(n^2)

        N = len(temperatures)
        results = [0] * N
        temp_stack = [] # will contain (temperature, index)

        for i in range(N):

            while temp_stack and temperatures[i] > temp_stack[-1][0]:
                _, popped_index = temp_stack.pop()
                results[popped_index] = i - popped_index

            temp_stack.append((temperatures[i], i))


        return results