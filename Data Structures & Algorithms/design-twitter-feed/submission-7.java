class Twitter {
    Map<Integer, Set<Integer>> following;
    Map<Integer, Queue<Integer[]>> posts;
    int count;

    public Twitter() {
        following = new HashMap<>();
        posts = new HashMap<>();
        count = 0;
    }

    private void createUser(int userId) {
        if (!following.containsKey(userId)) {
            following.put(userId, new HashSet<Integer>());
            posts.put(userId, new LinkedList<Integer[]>());
        }
    }
    
    public void postTweet(int userId, int tweetId) {
        createUser(userId);
        posts.get(userId).add(new Integer[]{++count, tweetId});

        if (posts.get(userId).size() > 10) {
            posts.get(userId).poll();
        }
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Integer[]> minHeap = new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );

        for (Integer[] i: posts.get(userId)) {
            minHeap.add(i);
        }

        for (int user: following.get(userId)) {
            for (Integer[] i: posts.get(user)) {
                minHeap.add(i);

                if (minHeap.size() > 10) {
                    minHeap.poll();
                }
            }
        }

        List<Integer> returnVal = new ArrayList<>();

        while (!minHeap.isEmpty()) {
            returnVal.add(minHeap.poll()[1]);
        }

        Collections.reverse(returnVal);

        return returnVal;
    }
    
    public void follow(int followerId, int followeeId) {
        createUser(followerId);

        if (followerId != followeeId) {
            following.get(followerId).add(followeeId);
        }
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && 
            following.get(followerId).contains(followeeId)) {
                following.get(followerId).remove(followeeId);
        }
    }
}
