class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> edges;
    bool dfs(string cur, vector<string>& res, int ticketCount) {
        if (edges[cur].size() == 0) {
            return ticketCount == 0;
        }

        stack<string> past;

        for (int i = 0; i < edges[cur].size(); ++i) {
            for (int j = 0; j < i; ++j) {
                past.push(edges[cur].top());
                edges[cur].pop();
            }

            string dest = edges[cur].top();
            edges[cur].pop();
            res.push_back(dest);

            while(!past.empty()) {
                edges[cur].push(past.top());
                past.pop();
            }

            if (dfs(dest, res, ticketCount - 1)) {
                return true;
            }
            res.pop_back();
            edges[cur].push(dest);
        }

        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unsigned ticketCount = 0;
        for (vector<string> edge: tickets) {
            edges[edge[0]].push(edge[1]);
            ++ticketCount;
        }
        vector<string> res{"JFK"};
        dfs("JFK", res, ticketCount);

        return res;
    }
};
