class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        int idx1 = n/2;
        int idx2 = n/2 - 1;
        int ele1,ele2;
        int c=0;
        int i=0,j=0;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(c == idx1) ele1 = nums1[i];
                if(c == idx2) ele2 = nums1[i];
                c++;
                i++;
            }
            else{
                if(c == idx1) ele1 = nums2[j];
                if(c == idx2) ele2 = nums2[j];
                c++;
                j++;
            }
        }

        while(i < n1){
            if(c == idx1) ele1 = nums1[i];
            if(c == idx2) ele2 = nums1[i];
            c++;
            i++;
        }

        while(j < n2){
            if(c == idx1) ele1 = nums2[j];
            if(c == idx2) ele2 = nums2[j];
            c++;
            j++;
        }

        if(n&1)return (double)ele1;
        else return (double)(ele1+ele2)/2;
    }
};