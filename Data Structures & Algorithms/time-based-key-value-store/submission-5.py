class TimeMap:

    def __init__(self):
        self.storage = {} # key = string, value = [val, timestamp]

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.storage:
            self.storage[key] = []
        self.storage[key].append([value, timestamp])


    def get(self, key: str, timestamp: int) -> str:
        result = ""
        if key not in self.storage:
            return result

        values = self.storage.get(key, [])

        # run binary search on values
        left, right = 0, len(values) - 1

        while left <= right:

            middle = (left + right) // 2

            if values[middle][1] <= timestamp:
                result = values[middle][0]
                left = middle + 1
            
            elif values[middle][1] > timestamp:
                right = middle - 1

        return result

        
