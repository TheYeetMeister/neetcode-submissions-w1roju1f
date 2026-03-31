class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        courseCnt = numCourses
        indegree = defaultdict(int)
        reqs = defaultdict(list)

        for course, req in prerequisites:
            reqs[req].append(course)
            indegree[course] += 1

        courseQueue = deque()

        for i in range(numCourses):
            if indegree[i] == 0:
                courseQueue.append(i)

        while courseQueue:
            courseTaken = courseQueue.popleft()
            courseCnt -= 1

            for upperClass in reqs[courseTaken]:
                indegree[upperClass] -= 1

                if indegree[upperClass] == 0:
                    courseQueue.append(upperClass)

        return courseCnt == 0

