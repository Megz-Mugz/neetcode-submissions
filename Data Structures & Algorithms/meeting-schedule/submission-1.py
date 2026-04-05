"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        intervals = sorted(intervals, key=lambda i: i.start)

        for index in range(1, len(intervals)):
            prev_end = intervals[index - 1].end
            curr_start = intervals[index].start

            if curr_start < prev_end:
                return False
        return True

            # print(f'prev_end: {prev_end} curr_start {curr_start}')