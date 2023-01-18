#ifndef HSET_ITER_H_INCLUDED
#define HSET_ITER_H_INCLUDED

#include <list>
#include <vector>
#include <iterator>	// for next()

// Each hset_iter contains a reference to its associated hash,
// and an size_t indicating progress within the hash.

//------------- Exercise 4 --------------
template <typename T>
class hset_iter {
    using table_t = typename std::vector<std::list<T>>;
    const table_t *parent;  // pointer to the hash table we’re iterating over
    // size_t num;		    // how far along we are.  0=first item
    size_t vector_index;
    size_t list_index;

  public:
    hset_iter(const table_t *table, size_t num) : parent(table),vector_index(num),list_index(0) { // Exercise 4
        // vector_index = num;
        // list_index = 0;
    }


    bool operator==(const hset_iter &rhs) const { // Exercise 4
        // hset_iter h;

        return (vector_index == rhs.vector_index)&&( list_index == rhs.list_index);
    }

    bool operator!=(const hset_iter &rhs) const {
	return !(*this == rhs);
    }

    // Return a pointer to the num'th element,
    // where num==0 is the first element.

    T operator*() const {  // Exercise 4
        return *next((*parent)[vector_index].begin(), list_index);
    }


//     Pre-increment (usually returns a reference to the iterator)
    void operator++() {
        
        if(((*parent)[vector_index].size()==0)&&(vector_index <(parent)->size())){
            ++vector_index;
        }
        if(list_index < (*parent)[vector_index].size()){
            ++list_index;
        }
        if((vector_index <(parent)->size())){

            ++vector_index;
            list_index=0;
        }
    }
        



};

#endif /* HSET_ITER_H_INCLUDED */

























            // while(s.empty()){
            //     vector_index++;
            