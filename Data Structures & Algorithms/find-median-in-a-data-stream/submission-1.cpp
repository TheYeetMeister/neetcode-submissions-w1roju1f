class MedianFinder {
    priority_queue<int> leftSide;
    priority_queue<int, vector<int>, greater<int>> rightSide;

    void balanceSides() {
        if (leftSide.size() >= rightSide.size() + 2) {
            rightSide.push(leftSide.top());
            leftSide.pop();
        } else if (rightSide.size() >= leftSide.size() + 2) {
            leftSide.push(rightSide.top());
            rightSide.pop();
        }
    }
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (leftSide.empty() && rightSide.empty() || leftSide.top() > num) {
            leftSide.push(num);
        } else {
            rightSide.push(num);
        }

        balanceSides();
    }
    
    double findMedian() {
        if ((leftSide.size() + rightSide.size()) % 2 == 0) {
            return ((double) rightSide.top() + leftSide.top()) / 2;
        } else {
            return (rightSide.size() > leftSide.size()) ? rightSide.top() : leftSide.top();
        }
    }
};
