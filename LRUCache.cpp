#include <bits/stdc++.h>
#include <unordered_map>

// https://leetcode.com/problems/lru-cache/

using namespace std;

template<class T = int, class U = int>
class CacheNode{
    T key;
    T value;
    
    public: CacheNode(T k, T v){
        key=k;
        value=v;
    }
    
    T getKey(){
        return key;
    }
    
    T getValue(){
        return value;
    }
};

template<class T = int, class U = int>
class LRUCache {
    private:
        unordered_map<T, list<CacheNode<>>::iterator> hashmap;      //TODO- map should support generic type.

        list<CacheNode<T,U> >q;
        int capacity;
        
        /**Removes the entry from map and queue.*/
        void deleteNode(list<CacheNode<>>::iterator it){
            hashmap.erase((*it).getKey());
            q.erase(it);
        }
    public:
        LRUCache(int capacity) {
            // TODO if capacity is less than or equal to zero, then throw.
            this->capacity=capacity;
        }
        
        /** Returns value from the cache if present.*/
        int get(T key) {
            int ans=-1;
            if(hashmap.find(key) != hashmap.end()) {
                list<CacheNode<>>::iterator it = hashmap[key];
                ans = (*it).getValue();
                deleteNode(it);
                q.push_front(CacheNode<>(key, ans));
                hashmap[key] = q.begin();
            }
            return ans;
        }
    
        /** Puts value into the cache. If that entry already present then overwrites the previous one.*/
        void put(T key, U value) {
            if(hashmap.find(key) == hashmap.end()) {
                if(capacity == hashmap.size()){
                    //delete the least recently used entry.
                    deleteNode(--q.end());
                }
            }
            else{
                deleteNode(hashmap[key]);
            }
            q.push_front(CacheNode<>(key, value));
            hashmap[key]=q.begin();
        }
        
        /** If present removes entry from the cache.*/
        void remove(T key) {
            if(hashmap.find(key) !=hashmap.end()){
                deleteNode(hashmap[key]);
            }
        }
};

// TODO Improve on testing.
int main(){
    LRUCache<int,int> *obj = new LRUCache<int,int>(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<< obj->get(1) <<endl;
    obj->put(3,3);
    cout<< obj->get(2) <<endl;
    obj->put(4,4);
    cout<< obj->get(1)<<endl;       //-1
    cout<< obj->get(3)<<endl;       //-1
    cout<<obj->get(4)<<endl;       //4

    /*
        Inputs
        ["LRUCache","put","put","get","put","get","put","get","get","get"]
        [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
        
        Expected Outputs
        [null,null,null,1,null,-1,null,-1,3,4]
    */
    return 0;
}
