class MyHashSet {
public:
   // Approach 1: if size is upto 10^7 
//     vector <int> n;
//     int size;
//     MyHashSet() {
//         size=1e6+1;//as the index is to made of 10^6
//         n.resize(size);
//     }
    
//     void add(int key) {
//         n[key]=1;
//     }
    
//     void remove(int key) {
//         n[key]=0;
//     }
    
//     bool contains(int key) {
//         return n[key];
//     }
// };
    
    
//     Approach 2 : if size >10^7
    vector <list<int>> n;
    int size;
    MyHashSet() {
        size=1e6+1;//as the index is to made of 10^6
        n.resize(size);
    }
    int hash(int key){
        return key%size;
    }
    list<int>::iterator search(int key){
        int i=hash(key);
        return find(n[i].begin(),n[i].end(),key);
    }
    void add(int key) {
        if (contains(key))return;
        int i=hash(key);
        n[i].push_back(key);
    }
    
    void remove(int key) {
        if (!contains(key))return;
        int i=hash(key);
        n[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if (search(key) !=n[i].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */