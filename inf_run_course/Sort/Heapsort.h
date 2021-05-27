#ifndef HEAP_SORT_H
#define HEAP_SORT_H

class HeapSort{
public:
    void Sort(int *data, int max_index);
    void Build_Max_Heap(int *data, int max_index);
    void Max_Heapify(int*data, int node);
    int get_size();
    void set_size(int number);
private:
    int max_size;
};

#endif /* HEAP_SORT_H */
