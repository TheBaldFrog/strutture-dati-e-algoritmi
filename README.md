## La mia implementazione della Standard Template Library (STL)

### [Catch2](https://github.com/catchorg/Catch2) popular unit testing framework for C++
### [vcpkg](https://github.com/microsoft/vcpkg) C++ dependency manager by microsoft

### Strutture dati
- [Dynamic array - non template](data_structures/dynamic_array)
- [Dynamic array - template](data_structures/dynamic_array_template)
- [Doubly linked list](data_structures/doubly_linked_list)
- [Stack](data_structures/stack)
- [Stack Doubly Linked List](data_structures/stack_dll)
- [Queue using two stacks](data_structures/queue_using_stacks)
- [MinMax Heap](data_structures/heap_minmax)

### Algoritmi
- [Bubble Sort](sorting_algorithms/bubble_sort.cpp)
- [Insertion Sort](sorting_algorithms/insertion_sort.cpp)
- [Selection Sort](sorting_algorithms/selection_sort.cpp)
- [Merge Sort](sorting_algorithms/merge_sort.cpp)
- [Quick Sort](sorting_algorithms/quick_sort.cpp)
- [Binary Search](sorting_algorithms/binary_search.cpp)
- [Heap Sort](https://github.com/TheBaldFrog/strutture-dati-e-algoritmi/blob/main/data_structures/heap_minmax/heap_minmax.h?plain=1#L119)

### Other
- [Locality of reference](sorting_algorithms/locality_of_reference.cpp)

## Build
### Adding vcpkg as a submodule
1. git submodule add -f https://github.com/microsoft/vcpkg.git
2. git submodule update --init --recursive 

### Build Windows
1. cmake -S . -B build -DCMAKE_BUILD_TYPE:STRING=Release
2. cmake --build build --config Release

### Build Linux
1. cmake -S . -B build/ -DCMAKE_BUILD_TYPE:STRING=Release -G Ninja
2. cmake --build build/
