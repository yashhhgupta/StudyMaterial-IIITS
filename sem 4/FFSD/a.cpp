class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    
    long totalWays(int unpicked, int undelivered) {
        if (unpicked == 0 && undelivered == 0) {
            // We have completed all orders.
            return 1;
        }
        
        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) {
            // We can't pick or deliver more than N items
            // Number of deliveries can't exceed number of pickups 
            // as we can only deliver after a pickup.
            return 0;
        }
        
        if (memo[unpicked][undelivered]) {
            // Return cached value, if already present. 
            return memo[unpicked][undelivered];
        }
        
        long ans = 0;
        
        // Count all choices of picking up an order.
        ans += unpicked * totalWays(unpicked - 1, undelivered);
        // Handle integer overflow.
        ans %= MOD;
        
        // Count all choices of delivering a picked order.
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
        // Handle integer overflow.
        ans %= MOD;
        
        return memo[unpicked][undelivered] = ans;
    }
    
public:
    int countOrders(int n) {
        memo = vector<vector<int>> (n + 1, vector<int>(n + 1, 0));
        return totalWays(n, n);
    }
};