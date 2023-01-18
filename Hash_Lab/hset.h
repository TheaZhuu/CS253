#ifndef HSET_H_INCLUDED
#define HSET_H_INCLUDED

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "hasher.h"
#include "hset_iter.h"

//--------- Exercise 1 -------------
template <typename T, int t_size =5, typename H = Hasher>   
class hset {
  private:
    static constexpr unsigned table_size= t_size;
    std::vector<std::list<T>> table;

  public:
    using iterator = hset_iter<T>;
    using value_type = T;
    using size_type = size_t;

    hset() : table(table_size) { }
    hset(const hset &) = default;
    hset& operator=(const hset &) = default;
    ~hset() = default;

    void insert(const T &datum) {
	auto hashval = H()(datum) % table.size();
	auto &lr = table[hashval];
	if (find(lr.begin(), lr.end(), datum) == lr.end())
	    lr.push_back(datum);
    }

    // Walk down the hash table, adding up all the sizes.
    size_type size() const {
	size_type total = 0;
	for (const auto &row : table)
	    total += row.size();
	return total;
    }

// ------------Exercise 2 ------------
    bool empty()const{
        for (auto &row : table){
            if(row.begin() != row.end()){
                return false;
            }
            return true;
        }

    }

    iterator begin() const {
	return iterator(&table, 0);
    }

    iterator end() const {
	return iterator(&table,t_size);
    }

    void dump() const {
	for (size_t i=0; i<table.size(); i++) {	    // loop over the vector
	    std::cout << "table[" << i << "]";
	    for (const auto &v : table[i])	    // loop over one list
		std::cout << ' ' << v;
	    std::cout << '\n';
	}
    }
};

#endif /* HSET_H_INCLUDED */
