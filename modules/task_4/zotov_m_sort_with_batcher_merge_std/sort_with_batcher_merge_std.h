// Copyright 2022 Zotov Maxim
#ifndef MODULES_TASK_4_ZOTOV_M_SORT_WITH_BATCHER_MERGE_STD_SORT_WITH_BATCHER_MERGE_STD_H_
#define MODULES_TASK_4_ZOTOV_M_SORT_WITH_BATCHER_MERGE_STD_SORT_WITH_BATCHER_MERGE_STD_H_

#include <vector>

int getMaxDigit(std::vector<int> data);
std::vector<int> getRandomVector(int size);
void radixSort(std::vector<int>* main_data, int size, int offset);
void parallelRadixSort(std::vector<int>* data, int size, int ThreadNum);

#endif  // MODULES_TASK_4_ZOTOV_M_SORT_WITH_BATCHER_MERGE_STD_SORT_WITH_BATCHER_MERGE_STD_H_
