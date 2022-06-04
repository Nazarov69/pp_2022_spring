// Copyright 2022 Zotov Maxim
#include <gtest/gtest.h>
#include <omp.h>
#include <vector>
#include "../../../3rdparty/unapproved/unapproved.h"
#include "./sort_with_batcher_merge_std.h"

TEST(zotov_parralel_radix_sort, Parralel_Radix_Sort_1) {
    std::vector<int> vec = { 6, 5, -4, 3, -2, 1, -8 };
    std::vector<int> sort_vec = { -8, -4, -2, 1, 3, 5, 6 };
    int number_threads = 2;
    parallelRadixSort(&vec, vec.size(), number_threads);
    ASSERT_EQ(sort_vec, vec);
}

TEST(zotov_parralel_radix_sort, Parralel_Radix_Sort_2) {
    int size = 100;
    std::vector<int> vec = getRandomVector(size);
    std::vector<int> seq_vec = vec;
    int number_threads = 2;
    radixSort(&seq_vec, seq_vec.size(), 0);
    parallelRadixSort(&vec, vec.size(), number_threads);
    ASSERT_EQ(seq_vec, vec);
}

TEST(zotov_parralel_radix_sort, Parralel_Radix_Sort_3) {
    int size = 100;
    std::vector<int> vec = getRandomVector(size);
    std::vector<int> seq_vec = vec;
    int number_threads = 4;
    radixSort(&seq_vec, seq_vec.size(), 0);
    parallelRadixSort(&vec, vec.size(), number_threads);
    ASSERT_EQ(seq_vec, vec);
}

TEST(zotov_parralel_radix_sort, Parralel_Radix_Sort_4) {
    int size = 1000;
    std::vector<int> vec = getRandomVector(size);
    std::vector<int> seq_vec = vec;
    int number_threads = 3;
    radixSort(&seq_vec, seq_vec.size(), 0);
    parallelRadixSort(&vec, vec.size(), number_threads);
    ASSERT_EQ(seq_vec, vec);
}

TEST(zotov_parralel_radix_sort, Parralel_Radix_Sort_5) {
    int size = 1000;
    std::vector<int> vec = getRandomVector(size);
    std::vector<int> seq_vec = vec;
    int number_threads = 5;
    radixSort(&seq_vec, seq_vec.size(), 0);
    parallelRadixSort(&vec, vec.size(), number_threads);
    ASSERT_EQ(seq_vec, vec);
}

TEST(zotov_parralel_radix_sort, Parralel_Radix_Sort_6) {
    int size = 10000;
    std::vector<int> vec = getRandomVector(size);
    std::vector<int> seq_vec = vec;
    int number_threads = 2;
    radixSort(&seq_vec, seq_vec.size(), 0);
    parallelRadixSort(&vec, vec.size(), number_threads);
    ASSERT_EQ(seq_vec, vec);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
