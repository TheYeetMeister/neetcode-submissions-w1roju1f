class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;

        for (const string& i: operations) {
            int x;
            int y;

            switch (i[0]) {
                case '+':
                    x = scores.back();
                    y = *(scores.end() - 2);
                    scores.push_back(x + y);
                    break;

                case 'D':
                    x = scores.back();
                    scores.push_back(2 * x);
                    break;

                case 'C':
                    scores.pop_back();
                    break;

                default:
                    scores.push_back(stoi(i));
            }
        }

        int sum = 0;

        for (int num: scores) {
            sum += num;
        }

        return sum;
    }
};