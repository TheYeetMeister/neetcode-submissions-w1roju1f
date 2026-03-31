class Twitter {
    //first int is time, second is id
    typedef vector<pair<int, int>> tweetInfo;

    //first variable is users the user is following
    //second variable is posting info
    typedef pair<unordered_set<int>, tweetInfo> userInfo;

    unordered_map<int, userInfo> globalUserInfo;
    int time;
public:
    Twitter(): time(0) {
        globalUserInfo = {};
    }
    
    void postTweet(int userId, int tweetId) {
        globalUserInfo[userId].second.push_back({time, tweetId});
        ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        if (globalUserInfo.find(userId) == globalUserInfo.end()) {
            return {};
        }

        vector<int> res{};

        vector<int> tweetPos(globalUserInfo[userId].first.size() + 1);
        tweetPos[0] = globalUserInfo[userId].second.size() - 1;
        int j = 1;
        for (int followeeId: globalUserInfo[userId].first) {
            tweetPos[j] = globalUserInfo[followeeId].second.size() - 1;
            ++j;
        }

        for (int i = 0; i < 10; ++i) {
            int mostRecentTime = -1;
            int tweetId = -1;
            int chosenIndex = -1;
            bool chosen = false;

            if (tweetPos[0] >= 0) {
                chosen = true;
                mostRecentTime = globalUserInfo[userId].second[tweetPos[0]].first;
                tweetId = globalUserInfo[userId].second[tweetPos[0]].second;
                chosenIndex = 0;
            }

            //check followees
            int j = 1;
            for (int followeeId: globalUserInfo[userId].first) {
                if (tweetPos[j] < 0) {
                    ++j;
                    continue;
                }

                if (!chosen) {
                    chosen = true;
                    mostRecentTime = globalUserInfo[followeeId].second[tweetPos[j]].first;
                    tweetId = globalUserInfo[followeeId].second[tweetPos[j]].second;
                    chosenIndex = j;
                } else if (globalUserInfo[followeeId].second[tweetPos[j]].first > mostRecentTime) {
                    mostRecentTime = globalUserInfo[followeeId].second[tweetPos[j]].first;
                    tweetId = globalUserInfo[followeeId].second[tweetPos[j]].second;
                    chosenIndex = j;
                }

                ++j;
            }

            if (!chosen) {
                break;
            } else {
                res.push_back(tweetId);
                --tweetPos[chosenIndex];
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId && globalUserInfo[followerId].first.find(followeeId) ==
            globalUserInfo[followerId].first.end()) {
            globalUserInfo[followerId].first.insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && globalUserInfo[followerId].first.find(followeeId) !=
            globalUserInfo[followerId].first.end()) {
                globalUserInfo[followerId].first.erase(followeeId);
        }
    }
};
