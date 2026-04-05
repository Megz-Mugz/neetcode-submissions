class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.nums = nums

    def add(self, val: int) -> int:
        self.nums.append(val)
        self.nums = sorted(self.nums)
        return self.nums[len(self.nums) - 1 - (self.k - 1)]
