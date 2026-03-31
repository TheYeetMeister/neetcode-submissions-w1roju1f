class Twitter:
    def __init__(self):
        self._following = {}
        self._posting = {}
        self._count = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self._count += 1
        self._posting.setdefault(userId, []).append((self._count, tweetId))

    def _get_ten_recent_posts(self, userId: int, minHeap: List[int]):
        count: int = 0
        for i in reversed(self._posting.get(userId, [])):
            heapq.heappush(minHeap, i)

            if (len(minHeap) > 10):
                heapq.heappop(minHeap)

            if (count == 10):
                break;

    def getNewsFeed(self, userId: int) -> List[int]:
        minHeap = []

        self._get_ten_recent_posts(userId, minHeap)

        for user in self._following.get(userId, []):
            self._get_ten_recent_posts(user, minHeap)

        returnVal: List[int] = []

        while minHeap:
            returnVal.append(heapq.heappop(minHeap)[1])

        return returnVal[::-1]

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self._following.setdefault(followerId, set()).add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId and followeeId in self._following.get(followerId, set()):
            self._following[followerId].remove(followeeId)
        
