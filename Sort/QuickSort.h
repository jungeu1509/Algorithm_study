#ifndef QUICK_SORT_H
#define QUICK_SORT_H

class QuickSort{
public:
    void Sort(int *data, int max_index);
    void run(int *data, int start, int end);
    int partition(int *data, int start, int end);
private:
};

#endif /* QUICK_SORT_H */
