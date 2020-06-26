class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // start 9:49 - fail 10:17
        // tortoise and hare solution digest 10:20 - 10:41
        // implement solution 10:41 - 11:10
        size_t tort{0}, hare{0};
        // size_t intersect{0}, cycleStart{0};
        // Tort will meet hare at intersection
        do
        {
            // Tortoise one step
            tort = static_cast<size_t>(nums[tort]);
            
            // Hare two steps
            hare = static_cast<size_t>(nums[hare]);
            hare = static_cast<size_t>(nums[hare]);
        } while (tort != hare);
        // Hare is at intersection
        // intersect = hare;
        
        // Put tortoise to start
        tort = 0;
        // Tort will meet hare at cycle start
        while (tort != hare)
        {
            tort = static_cast<size_t>(nums[tort]);
            hare = static_cast<size_t>(nums[hare]);
        }
        // cycleStart = tort;
        return static_cast<int>(tort);
    }
};
