class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegrees = {i: 0 for i in range(numCourses)}
        neighbors = {i: [] for i in range(numCourses)}

        for course, req in prerequisites:
            indegrees[course] += 1
            neighbors[req].append(course)

        queue = deque()
        for i in range(numCourses):
            if indegrees[i] == 0:
                queue.append(i)

        res = []

        while queue:
            takenCourse = queue.popleft()
            res.append(takenCourse)

            for nei in neighbors[takenCourse]:
                indegrees[nei] -= 1

                if indegrees[nei] == 0:
                    queue.append(nei)
        
        return res if len(res) == numCourses else []
        