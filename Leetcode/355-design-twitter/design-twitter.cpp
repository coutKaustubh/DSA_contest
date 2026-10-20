class Twitter {
public:
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int, vector<pair<int,int>>>tweets;
    int timer = 0;
    const int k = 10;
    Twitter(){
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>minheap;
        int n = tweets[userId].size();
        for(int i=0;i<n;i++){
            minheap.push(tweets[userId][i]);
            if(minheap.size() > k)minheap.pop();
        } 
        for(int followee : following[userId]) {
            
            n = tweets[followee].size();
            
            for(int i=0;i<n;i++) {
                
                minheap.push(tweets[followee][i]);
                
                if(minheap.size() > k)
                    minheap.pop();
            }
        }
        
        vector<int> feed;
        
        while(!minheap.empty()) {
            feed.push_back(minheap.top().second);
            minheap.pop();
        }
        
        reverse(feed.begin(), feed.end());
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */