class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        # build out adjacency list
        prereq_map = defaultdict(list)
        for course, pre_req in prerequisites:
            prereq_map[course].append(pre_req)

        visiting = set() # for current dfs cycle (0, 1)
        
        def dfs(course):
            # detect if there is a cycle
            if course in visiting: return False
            
            
            visiting.add(course)

            prerequisites = prereq_map[course]

            for pre in prerequisites:
                if not dfs(pre):
                    return False

            print(f'removing course from visiting: {course}')
            visiting.remove(course)
            return True
        
        status = True
        for course in range(numCourses):
            if not dfs(course):
                status = False
        print(f'visting: {visiting}')
        return status