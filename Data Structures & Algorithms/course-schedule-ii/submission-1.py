class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        # build out adjacency list course(int) -> prereqs([])
        course_to_prereq = defaultdict(list)
        for course, prereq in prerequisites:
            course_to_prereq[course].append(prereq)


        visiting = set()
        order_of_courses = []

        
        def valid_order(course):
            '''
            checks to see if there is a cycle (aka order of courses is not possible)

            course: current course being examined for a cycle
            rtype: returns False if there is a cycle, true if there isn't a cycle
            '''
            if course in visiting: return False

            visiting.add(course)

            for prereq in course_to_prereq[course]:
                if not valid_order(prereq):
                    return False

            visiting.remove(course)
            if course not in order_of_courses:
                order_of_courses.append(course)
            return True
        

        for course in range(numCourses):
            if not valid_order(course):
                return []
            
        return order_of_courses


