class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> courseSatisfy(numCourses);

        for (auto i: prerequisites) {
            ++indegrees[i[0]];
            courseSatisfy[i[1]].push_back(i[0]);
        }

        vector<int> res{};
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                res.push_back(i);
            }
        }

        int currPos = 0;

        while (currPos < res.size()) {
            int courseCompleted = res[currPos];
            for (int i: courseSatisfy[courseCompleted]) {
                --indegrees[i];

                if (indegrees[i] == 0) {
                    res.push_back(i);
                }
            }
            ++currPos;
        }

        if (res.size() == numCourses) {
            return res;
        } else {
            return {};
        }
    }
};
