class Solution {
public:
    int hIndex(vector<int>& ct) {
        sort(ct.begin(), ct.end());

        int n = ct.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (ct[mid] >= n - mid) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return n-l;
    }
};