#include <bits/stdc++.h>
using namespace std;

class BruteLRUCache {
    int cap;
    vector<pair<int, int>> cache;

public:
    BruteLRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        for (int i = 0; i < cache.size(); ++i) {
            if (cache[i].first == key) {
                int val = cache[i].second;
                cache.erase(cache.begin() + i);
                cache.insert(cache.begin(), {key, val});
                return val;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        for (int i = 0; i < cache.size(); ++i) {
            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);
                break;
            }
        }

        if (cache.size() == cap)
            cache.pop_back();

        cache.insert(cache.begin(), {key, value});
    }
};

class LRUCache {
    int cap;
    list<int> dll;  // stores keys
    unordered_map<int, pair<int, list<int>::iterator>> cache; // key -> {value, list iterator}

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        dll.erase(cache[key].second);
        dll.push_front(key);
        cache[key].second = dll.begin();
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            dll.erase(cache[key].second);
        } else if (dll.size() == cap) {
            int last = dll.back();
            dll.pop_back();
            cache.erase(last);
        }
        dll.push_front(key);
        cache[key] = {value, dll.begin()};
    }
};


int main() {
    BruteLRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // 1
    lru.put(3, 3);              // evicts key 2
    cout << lru.get(2) << endl; // -1
    lru.put(4, 4);              // evicts key 1
    cout << lru.get(1) << endl; // -1
    cout << lru.get(3) << endl; // 3
    cout << lru.get(4) << endl; // 4
}
