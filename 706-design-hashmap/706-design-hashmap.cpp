class MyHashMap {
public:
//     Apporach 1: when we make a vector of given range
//     vector<int>n;
//     int size;
//     MyHashMap() {
//         size=1e6+1;
//         n.resize(size);
//         fill(n.begin(),n.end(),-1);
//     }
    
//     void put(int key, int value) {
//         n[key]=value;
//     }
    
//     int get(int key) {
//         return n[key];
//     }
    
//     void remove(int key) {
//         n[key]=-1;
//     }
// };
//     Approach 2 : if 
     vector<list<pair<int,int>>>n;
    int size;
    MyHashMap() {
        // size=1e6+1;
        size=1000;
        n.resize(size);
    }
    int hash(int key){
        return key%size;
    }
    list <pair<int,int>> :: iterator search(int key){
        int i=hash(key);
        list <pair<int,int>> :: iterator it = n[i].begin();
        while(it != n[i].end()){
            if (it->first == key)
                return it;
                it++;
        }
        return it;
    }
    void put(int key, int value) {
        int i=hash(key);
        remove(key);
        n[i].push_back({key,value});
    }
    
    int get(int key) {
        int i=hash(key);
        list <pair<int,int>> :: iterator it = search(key);
        if(it == n[i].end()) return -1;
        else return (it->second);
    }
    
    void remove(int key) {
        int i=hash(key);
         list <pair<int,int>> :: iterator it = search(key);
        if(it != n[i].end()) n[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */