class Solution {
    class Task {
        int numOfTasks;
        int nextUsage;

        public Task(int numOfTasks, int nextUsage) {
            this.numOfTasks = numOfTasks;
            this.nextUsage = nextUsage;
        }
    }

    public int leastInterval(char[] tasks, int n) {
        int[] taskCnt = new int[26];

        for (char task: tasks) {
            ++taskCnt[task - 'A'];
        }

        PriorityQueue<Task> maxHeap = new PriorityQueue<>
            ((Task a, Task b) -> Integer.compare(b.numOfTasks, a.numOfTasks));

        for (int i = 0; i < taskCnt.length; ++i) {
            if (taskCnt[i] > 0) {
                maxHeap.add(new Task(taskCnt[i], 0));
            }
        }
        Queue<Task> que = new LinkedList<>();

        int count = 0;

        while (!maxHeap.isEmpty() || !que.isEmpty()) {
            Task activeTask;
            if (maxHeap.isEmpty()) {
                activeTask = que.poll();
                count = activeTask.nextUsage;
            } else {
                activeTask = maxHeap.poll();
            }

            ++count;

            if (--activeTask.numOfTasks > 0) {
                activeTask.nextUsage = n + count;
                que.add(activeTask);
            }

            while (!que.isEmpty() && que.peek().nextUsage <= count) {
                maxHeap.add(que.poll());
            }
        }

        return count;
    }
}
