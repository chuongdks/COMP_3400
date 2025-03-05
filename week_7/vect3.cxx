template<typename T>
class Vector {
allocator<T> alloc; // standard-library allocator of space for Ts
T* elem; // pointer to first element
T* space; // pointer to first unused (and uninitialized) slot
T* last; // pointer to last slot
public:
// ...
int size() const { return space−elem; } // number of elements
int capacity() const { return last−elem; } // number of slots available for elements
// ...
void reserve(int newsz); // increase capacity() to newsz
// ...
void push_back(const T& t); // copy t into Vector
void push_back(T&& t); // move t into Vector
};
