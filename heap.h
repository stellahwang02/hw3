#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  size_t m;
  PComparator comparator;
  std::vector<T> data;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), comparator(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    // Implement the push operation here
    data.push_back(item);
    
    // Perform heapify-up to maintain heap property
    size_t currInd = size() - 1;
    size_t parentInd = (currInd - 1) / m;

    while (currInd > 0 && comparator(data[currInd], data[parentInd])) {
        std::swap(data[currInd], data[parentInd]);
        currInd = parentInd;
        parentInd = (currInd - 1) / m;
    }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("top on the empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("pop on the empty heap");
  }
  // Swap the root with the last element
  std::swap(data.front(), data.back());
  data.pop_back();

  // Perform heapify-down to maintain heap property
  size_t currInd = 0;

  while (true) {
        size_t smallestChildInd = currInd * m + 1;
        if (smallestChildInd >= size()) {
            break;
        }

        for (size_t i = 1; i < m && (currInd * m + 1 + i) < size(); ++i) {
            if (comparator(data[currInd * m + 1 + i], data[smallestChildInd])) {
                smallestChildInd = currInd * m + 1 + i;
            }
        }

        if (comparator(data[smallestChildInd], data[currInd])) {
            std::swap(data[currInd], data[smallestChildInd]);
            currInd = smallestChildInd;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    // Implement the empty check here
    return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    // Implement the size retrieval here
    return data.size();
}


#endif

