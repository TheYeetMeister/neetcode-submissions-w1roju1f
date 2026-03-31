class TimeMap {
    Map<String, ArrayList<TimeValue>> buf = new HashMap<>();

    private class TimeValue {
        public Integer timeStamp;
        public String value;

        public TimeValue(int timeStamp, String value) {
            this.timeStamp = timeStamp;
            this.value = value;
        }
    }

    public TimeMap() {}
    
    public void set(String key, String value, int timestamp) {
        if (!buf.containsKey(key)) {
            buf.put(key, new ArrayList<>());
        }
        buf.get(key).add(new TimeValue(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        if (!buf.containsKey(key)) {
            return "";
        }

        ArrayList<TimeValue> timeList = buf.get(key);

        int l = 0, r = timeList.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (timeList.get(mid).timeStamp > timestamp) {
                r = mid - 1;
            } else if (timeList.get(mid).timeStamp < timestamp) {
                l = mid + 1;
            } else {
                return timeList.get(mid).value;
            }
        }

        if (r < 0) {
            return "";
        }
        return timeList.get(r).value;
    }
}
