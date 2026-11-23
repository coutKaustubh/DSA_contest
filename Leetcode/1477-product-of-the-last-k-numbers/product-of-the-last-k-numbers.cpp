class ProductOfNumbers {
public:
    vector<int>stream;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        int n = stream.size();
        if(k>n)return 0;
        int pr=1;
        for(int i=n-1;i>=n-k;i--)pr*=stream[i];
        return pr;

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */