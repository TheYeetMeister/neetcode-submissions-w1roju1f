class Solution {
    void addPreCount(vector<vector<int>>& prereqs, 
            unordered_map<int, int>& preReqCount, 
            unordered_map<int, vector<int>>& preReqUnlocks) {
                for (vector<int> preReqPair: prereqs) {
                    ++preReqCount[preReqPair[0]];
                    preReqUnlocks[preReqPair[1]].push_back(preReqPair[0]);
                }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> coursePreCount;
        unordered_map<int, vector<int>> coursePrereqs;
        addPreCount(prerequisites, coursePreCount, coursePrereqs);
        queue<int> bfs;

        int finishedCourses = 0;

        for (int i = 0; i < numCourses; ++i) {
            if (coursePreCount.find(i) == coursePreCount.end()) {
                bfs.push(i);
            }
        }

        while(!bfs.empty()) {
            int finishedCourse = bfs.front();
            bfs.pop();
            ++finishedCourses;

            for (int i: coursePrereqs[finishedCourse]) {
                --coursePreCount[i];

                if (!coursePreCount[i]) {
                    bfs.push(i);
                }
            }
        }

        return finishedCourses == numCourses;
    }
};
