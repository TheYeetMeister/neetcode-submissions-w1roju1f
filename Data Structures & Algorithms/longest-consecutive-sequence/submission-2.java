class UnionFind {
    HashMap<Integer, Integer> parent = new HashMap<>();
    HashMap<Integer, Integer> size = new HashMap<>();

    void make_set(int v) {
        parent.put(v, v);
        size.put(v, 1);
    }

    int find_set(int v) {
        if (v == parent.get(v)) {
            return v;
        }
        parent.put(v, find_set(parent.get(v)));
        return parent.get(v);
    }

    boolean variableExists(int v) {
        return parent.containsKey(v);
    }

    int union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (size.get(a) < size.get(b)) {
                //swap
                int temp = a;
                a = b;
                b = temp;
            }
            parent.put(b, a);
            size.put(a, size.get(a) + size.get(b));
        }

        return size.get(a);
    }
    
}

class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;

        UnionFind ufSet = new UnionFind();
        int res = 1;
        for (int num: nums) {
            if (ufSet.variableExists(num)) continue;

            ufSet.make_set(num);

            if (ufSet.variableExists(num - 1)) {
                res = Math.max(ufSet.union_sets(num, num - 1), res);
            }

            if (ufSet.variableExists(num + 1)) {
                res = Math.max(ufSet.union_sets(num, num + 1), res);
            }
        }

       return res;
    }
}