/*
 * Leetcode Medium 981. Time Based Key-Value Store
 * author: shizuka1024
 * (Java)
 */
class TimeMap {

    Map<String , List<String>> valueM;
    Map<String , List<Integer>> timeM;

    public TimeMap() {
        valueM = HashMap<>();
        timeM = HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if(!timeM.containsKey(key)){    //檢查key是否存在
            valueM.put(key, new ArrayList<String>());
            timeM.put(key, new ArryList<Integer>());
        }
        valueM.get(key).add(value);
        timeM.get(key).add(timestamp);
    }
    
    public String get(String key, int timestamp) {
        if(!timeM.containsKey(key) || timeM.get(key).get(0) > timestamp)
            return "";
        List<Integer> times = timeM.get(key);
        int a = 0, b = time.size();
        while(a < b){
            int n = (a + b) >> 1;
            if(time.get(n) <= timestamp)
                a = n + 1;
            else 
                b = n;
        }
        return valueM.get(key).get(a - 1);
    }
}
