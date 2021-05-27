#ifndef MERGE_SORT_H
#define MERGE_SORT_H

class MergeSort{
public:
    void Sort(int *data, int max_index);
    void run(int *data, int start, int end);
    void merge(int *data, int start, int mid, int end);
    int get_size();
    void set_size(int number);
private:
    int max_size;
};

#endif /* MERGE_SORT_H */
