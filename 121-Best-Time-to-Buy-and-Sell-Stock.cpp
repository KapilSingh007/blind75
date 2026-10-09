int maxProfit(vector<int>& prices) {

        int n = prices.size(), res = 0 , buy = prices[0];

        for (int i = 1; i < n; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }

            if (prices[i] > buy) {
                res = max(res, prices[i] - buy);
            }
        }

        return res > 0 ? res : 0;
    }