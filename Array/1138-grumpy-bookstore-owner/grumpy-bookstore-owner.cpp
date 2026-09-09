class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0;
        int n = customers.size();

        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        int additional = 0;
        int max_additional = 0;

        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 1) {
                additional += customers[i];
            }

            if(i >= minutes && grumpy[i - minutes] == 1) {
                additional -= customers[i - minutes];
            }

            max_additional = max(max_additional, additional);
        }

        return satisfied + max_additional;
    }
};