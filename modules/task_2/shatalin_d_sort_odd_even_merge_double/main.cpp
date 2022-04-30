// Copyright 2022 Shatalin Dmitrii
#include <gtest/gtest.h>
#include <omp.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../modules/task_2/shatalin_d_sort_odd_even_merge_double/sort.h"

TEST(Radix_Sort_Odd_Even_Merge, Simple_Test) {
    omp_set_num_threads(8);
    std::vector<double> a = { 0., 10., 1., 11., 2., 12., 3., 13., -499.921,
                            -478.018, -270.971, -318.089, -180.188, -253.165, 269.783, 85.646 };
    std::vector<double> a1 = a;
    a = radixSortOddEvenMergeDoubleParallel(a);
    std::sort(a1.begin(), a1.end());
    EXPECT_EQ(a, a1);
}

TEST(Radix_Sort_Odd_Even_Merge, Can_Sort_Small_Positive_Vector) {
    std::vector<double> vec1 = getRandomVector(20, 0, 500);
    std::vector<double> vec2 = vec1;
    vec1 = radixSortOddEvenMergeDoubleParallel(vec1);
    std::sort(vec2.begin(), vec2.end());
    EXPECT_EQ(vec1, vec2);
}

TEST(Radix_Sort_Odd_Even_Merge, Can_Sort_Small_Negative_Vector) {
    std::vector<double> vec1 = getRandomVector(8, -500, 0);
    std::vector<double> vec2 = vec1;
    vec1 = radixSortOddEvenMergeDoubleParallel(vec1);
    std::sort(vec2.begin(), vec2.end());
    EXPECT_EQ(vec1, vec2);
}

TEST(Radix_Sort_Odd_Even_Merge, Can_Sort_Large_Vector) {
    std::vector<double> vec1 = getRandomVector(1000, -500, 500);
    std::vector<double> vec2 = vec1;
    vec1 = radixSortOddEvenMergeDoubleParallel(vec1);
    std::sort(vec2.begin(), vec2.end());
    EXPECT_EQ(vec1, vec2);
}

TEST(Radix_Sort_Odd_Even_Merge, Can_Sort_Vector_With_One_Elem) {
    std::vector<double> vec1 = getRandomVector(1, -500000, 500000);
    std::vector<double> vec2 = vec1;
    vec1 = radixSortOddEvenMergeDoubleParallel(vec1);
    EXPECT_EQ(vec1, vec2);
}

TEST(Radix_Sort_Odd_Even_Merge, Can_Sort_Vector_With_Large_Numbers) {
    std::vector<double> vec1 = getRandomVector(1000, -500000, 500000);
    std::vector<double> vec2 = vec1;
    vec1 = radixSortOddEvenMergeDoubleParallel(vec1);
    std::sort(vec2.begin(), vec2.end());
    EXPECT_EQ(vec1, vec2);
}

//TEST(Gauss_Filter, Eff_Test) {
//    std::vector<double> vec1 = getRandomVector(5000000, -500000, 500000);
//    std::vector<double> vec2 = vec1;
//    clock_t start, end;
//    start = clock();
//    vec1 = radixSortOddEvenMergeDoubleParallel(vec1);
//    end = clock();
//    double seconds = (static_cast<double>(end - start)) / CLOCKS_PER_SEC;
//    std::cout << "seq " << seconds << std::endl;
//    start = clock();
//    vec2 = radixSortOddEvenMergeDoubles(vec2);
//    end = clock();
//    seconds = (static_cast<double>(end - start)) / CLOCKS_PER_SEC;
//    std::cout << "par " << seconds << std::endl;
//    ASSERT_EQ(1,1);
//}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
