class Solution {
public:
    double calculateTime(int target, int position, int speed) {
        return (double(target) - position) / speed;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> posSpeedPair{};

        for (int i = 0; i < position.size(); ++i) {
            posSpeedPair.push_back(make_pair(position[i], speed[i]));
        }

        sort(posSpeedPair.begin(), posSpeedPair.end(), std::greater<pair<int, int>>());

        stack<double> fleetSlowestTime;

        fleetSlowestTime.push(calculateTime(target, 
                                    posSpeedPair[0].first, posSpeedPair[0].second));

        for (int i = 1; i < posSpeedPair.size(); ++i) {
            double currTime = calculateTime(target,
                                    posSpeedPair[i].first, posSpeedPair[i].second);
            
            if (currTime > fleetSlowestTime.top()) {
                fleetSlowestTime.push(currTime);
            }
        }

        return fleetSlowestTime.size();
    }
};
