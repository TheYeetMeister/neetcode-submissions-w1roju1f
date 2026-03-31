class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int asteroid: asteroids) {
            if (res.empty() || asteroid > 0) {
                res.push_back(asteroid);
                continue;
            }

            while (!res.empty() && res.back() > 0 && res.back() < abs(asteroid)) {
                res.pop_back();
            }

            if (res.empty() || res.back() < 0) {
                res.push_back(asteroid);
            } else if (res.back() == abs(asteroid)) {
                res.pop_back();
            }
        }

        return res;
    }
};