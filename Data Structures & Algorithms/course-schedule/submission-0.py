class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        # build out adjacency list
        prereq_map = defaultdict(list)
        for course, pre_req in prerequisites:
            prereq_map[course].append(pre_req)

        visiting = set() # for current dfs cycle (0, 1)
        visited = set() # bigger picture - courses that are fully processed
        
        def dfs(course):
            # detect if there is a cycle
            if course in visiting: return False
            
            if course in visited: return True
            
            visiting.add(course)

            prerequisites = prereq_map[course]

            for pre in prerequisites:
                if not dfs(pre):
                    return False

            print(f'for course: {course}')
            visiting.remove(course)
            visited.add(course)
            return True
        
        for course in range(numCourses):
            if not dfs(course):
                return False
        return True