class RandomizedSet {
    private Random rand;
    private Map<Integer, Integer> mp;
    private List<Integer> nums;

    public RandomizedSet() {
        rand = new Random();
        mp = new HashMap<>();   
        nums = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        if (mp.containsKey(val)) {
            return false;
        }
        mp.put(val, nums.size());
        nums.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if (mp.containsKey(val)) {
            int id = mp.get(val);
            nums.set(id, nums.get(nums.size()-1));
            mp.put(nums.get(id), id);
            mp.remove(val);
            nums.remove(nums.size()-1);
            return true;
        }

        return false;
    }
    
    public int getRandom() {
        int n = mp.size();
        int id = rand.nextInt(n);

        return nums.get(id);
        
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */