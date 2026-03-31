class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        courseUnlocks = defaultdict(set)
        visited = set()

        for req, course in prerequisites:
            courseUnlocks[req].add(course)

        def dfs(preReqCourse) -> set:
            if preReqCourse in visited:
                return courseUnlocks[preReqCourse]

            visited.add(preReqCourse)
            returnUnionSet = set()
            for nextCourse in courseUnlocks[preReqCourse]:
                returnUnionSet |= dfs(nextCourse)
                returnUnionSet.add(nextCourse)

            courseUnlocks[preReqCourse] = returnUnionSet
            return courseUnlocks[preReqCourse]

        for i in range(numCourses):
            courseUnlocks[i] = dfs(i)

        res = []
        for i, j in queries:
            res.append(j in courseUnlocks[i])

        return res
            