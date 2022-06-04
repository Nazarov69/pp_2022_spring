// Copyright 2022 Shatalin Dmitrii
#ifndef MODULES_TASK_1_SHATALIN_D_SORT_ODD_EVEN_MERGE_DOUBLE_SORT_H_
#define MODULES_TASK_1_SHATALIN_D_SORT_ODD_EVEN_MERGE_DOUBLE_SORT_H_

#include <vector>

std::vector<double> countingSort(std::vector<double> array, int numByte);
std::vector<double> radixSortOddEvenMergeDouble(const std::vector<double>& array);
std::vector<double> getRandomVector(int size, double lower_bound, double upper_bound, int seed = -1);

#endif  // MODULES_TASK_1_SHATALIN_D_SORT_ODD_EVEN_MERGE_DOUBLE_SORT_H_
