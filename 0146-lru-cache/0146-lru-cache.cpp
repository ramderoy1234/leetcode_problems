class LRUCache {
public:
    int capacity;
    list<int> dll; // stores keys in order (most recent at front)
    unordered_map<int, pair<list<int>::iterator, int>> mp; // key -> {iterator in dll, value}

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void makeRecentlyUsed(int key) {
        // remove old position
        dll.erase(mp[key].first);
        // insert at front
        dll.push_front(key);
        // update iterator in map
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        makeRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value; // update value
            makeRecentlyUsed(key);
        }
        else {
            if (dll.size() == capacity) {
                int delKey = dll.back();
                dll.pop_back();
                mp.erase(delKey);
            }
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
        }
    }
};
