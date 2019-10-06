<h1><a href="https://leetcode.com/problems/lru-cache/">LRU Cache implementation </a></h1>

<h1>Licensing</h1>
This is licensed under the Apache 2.0 license - see https://www.apache.org/licenses/LICENSE-2.0

A basic implementation of LRU cache using genric templates. <a href="https://en.wikipedia.org/wiki/Cache_replacement_policies#Least_recently_used_(LRU)"> For details</a>

It supports following operations:
- <b>get(key)</b> - Get value for a key.
- <b>put(key, value)</b> - Adds the value into the Cache and if cache is full (reached maximum capacity) it deletes least recently used data.
- <b>remove(key)</b> - Removes the data from the cache.


<h1>Getting started</h1>
Code is written in c++ 11 version. Following is a way to run this code in unix environment using GNU compiler.

g++ -std=c++11 -o LRUCache.out LRUCache.cpp

./LRUCache.out

NOTE- There are some TODOs in the current implementation.