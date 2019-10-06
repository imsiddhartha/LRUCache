LRU Cache implementation (https://leetcode.com/problems/lru-cache/)

A basic implementation of LRU cache using genric templates.

It supports following operations:
- get(key) - Get value for a key.
- put(key, value) - Adds the value into the Cache and if cache is full (reached maximum capacity) it deletes least recently used data.
- remove(key) - Removes the data from the cache.

Code is written in c++ 11 version. Following is a way to run this code in unix environment using GNU compiler.

g++ -std=c++11 -o LRUCache.out LRUCache.cpp
./LRUCache.out

NOTE- There are some TODOs in the current implementation.