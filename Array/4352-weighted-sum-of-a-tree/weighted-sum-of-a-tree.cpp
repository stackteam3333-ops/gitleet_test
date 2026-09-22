class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = nums.size();

        // 1. Build tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        // 2. Find depth of every node
        vector<int> depth(n);

        queue<int> q;

        q.push(0);
        depth[0] = 1;

        int height = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            height = max(height, depth[node]);

            for (int child : tree[node]) {

                depth[child] = depth[node] + 1;

                q.push(child);
            }
        }

        // 3. Calculate weighted sum
        long long answer = 0;

        for (int i = 0; i < n; i++) {

            long long weight =
                1LL * nums[i] * (height - depth[i] + 1);

            answer += weight;
        }

        return answer;
    }
};