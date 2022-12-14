//
// Created by lyaho on 05.12.2022.
//

#ifndef CP6_TABLE_H
#define CP6_TABLE_H
#include <iostream>
#include <deque>
#include <list>
#include <iterator>

template<class TKey, class TValue>
class HashTable{
protected:
    size_t size_;
    size_t added;
    std::deque<std::list<std::pair<TKey, TValue>>> table;
public:
    explicit HashTable(size_t sz = 29);
    ~HashTable();
    void Insert(const TKey& key_val, TValue el_value);
    TValue Search(const TKey& key) const;
    void Output() const;
    void Delete(TValue element);
    size_t hash_function(const TKey & key) const;
    TValue operator[](const TKey& key); //table[key]
};

//Hash function which can be overloaded for any type
size_t hash(const std::string& key, size_t table_size, size_t base){
    long long sum = 0;
    long long h = 1;
    for (char c: key){
        sum += (int)(c - 'a' + 1)*h;
        h *= (long long)base;
    }
    return sum % table_size;
}

template<class TKey, class TValue>
HashTable<TKey, TValue>::HashTable(size_t sz) {
    size_ = sz;
    added = 0;
    table.resize(sz);
    for (size_t idx = 0; idx < size_; idx++){
        table[idx] = std::list<std::pair<TKey, TValue>>();
    }
}


template<class TKey, class TValue>
HashTable<TKey, TValue>::~HashTable() {
    for (auto list: table){
        if (!list.empty()){
            list.clear();
        }
    }
}

template<class TKey, class TValue>
size_t HashTable<TKey, TValue>::hash_function(const TKey &key) const {
    return hash(key, size_, size_ + 1);
}

template<class TKey, class TValue>
void HashTable<TKey, TValue>::Insert(const TKey &key_val, TValue el_value) {
    size_t idx = this->hash_function(key_val);
    for (auto pairs: table[idx]){
        if (pairs.first == key_val){
            return;
        }
    }
    std::pair<TKey, TValue> p(key_val, el_value);
    table[idx].push_back(p);
}

template<class TKey, class TValue>
TValue HashTable<TKey, TValue>::Search(const TKey &key) const {
    size_t idx = this->hash_function(key);
    for (auto pairs: table[idx]){
        if (pairs.first == key){
            return pairs.second;
        }
    }
    throw;
}

template<class TKey, class TValue>
void HashTable<TKey, TValue>:: Output() const{
    for (size_t idx = 0; idx < size_; idx++){
        for (auto pairs: table[idx]){
            std::cout << pairs.first << " " << pairs.second << std::endl;
        }
    }
};

template<class TKey, class TValue>
void HashTable<TKey, TValue>::Delete(TValue element){
    for (size_t idx = 0; idx < size_; idx++){
        auto iter = table[idx].begin();
        for (; iter != table[idx].end(); iter++) {
            if ((*iter).second == element){
                iter = table[idx].erase(iter);
            }
        }
        if (table[idx].back().second == element){
            table[idx].pop_back();
        }
    }
}


template<class TKey, class TValue> TValue HashTable<TKey, TValue>::operator[](const TKey& key){
    size_t idx = this->hash_function(key);
    for (auto pair: table[idx]){
        if (pair.first == key){
            return pair.second;
        }
    }
    throw;
}

#endif //CP6_TABLE_H
