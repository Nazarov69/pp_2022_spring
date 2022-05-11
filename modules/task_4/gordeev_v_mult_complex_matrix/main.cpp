// Copyright 2022 Gordeev Viktor

#include <gtest/gtest.h>
#include "../../../modules/task_4/gordeev_v_mult_complex_matrix/mult_complex_matrix.h"

TEST(Gordeev_Mult_Matrix, Constructor_With_No_Throw) {
    EXPECT_NO_THROW(MultMatrix mtx(5, 5));
}

TEST(Gordeev_Mult_Matrix, Cant_Get_Wrong_Matrix_Element) {
    MultMatrix mtx(1, 3);
    EXPECT_ANY_THROW(mtx.getElement(4, 4));
}

TEST(Gordeev_Mult_Matrix, Can_Get_Matrix_Element) {
    MultMatrix mtx(10, 10);
    EXPECT_NO_THROW(mtx.getElement(4, 4));
}

TEST(Gordeev_Mult_Matrix, Can_Mult_Matrix_Works_Correct) {
    MultMatrix mtx1(3, 5);
    MultMatrix mtx2(5, 6);
    EXPECT_NO_THROW(mtx1.multMatrixSequential(mtx2));
}

TEST(Gordeev_Mult_Matrix, Cant_Mult_Wrong_Size_Matrix) {
    MultMatrix mtx1(2, 9);
    MultMatrix mtx2(4, 5);
    EXPECT_ANY_THROW(mtx1.multMatrixSequential(mtx2));
}

TEST(Gordeev_Mult_Matrix, Res_Mult_Correct_Size) {
    MultMatrix mtx1(4, 10);
    MultMatrix mtx2(10, 10);
    MultMatrix res = mtx1.multMatrixSequential(mtx2);
    EXPECT_EQ(res.getLength(), mtx1.getLength());
    EXPECT_EQ(res.getHeight(), mtx2.getHeight());
}

TEST(Gordeev_Thread_Mult_Matrix, Res_Parallel_Equal_To_Sequential) {
    MultMatrix mtx1(4, 6);
    MultMatrix mtx2(6, 8);
    MultMatrix res1 = mtx1.multMatrixSequential(mtx2);
    MultMatrix res2 = mtx1.multMatrixParallel(mtx2);
    ASSERT_TRUE(res1.equal(res2));
}

// TEST(Gordeev_Thread_Mult_Matrix, Time_Test){
//    MultMatrix mtx1(100, 200);
//    MultMatrix mtx2(200, 300);
//
//    auto startSequential = std::chrono::high_resolution_clock::now();
//    MultMatrix res1 = mtx1.multMatrixSequential(mtx2);
//    auto endSequential = std::chrono::high_resolution_clock::now();
//
//    auto startParallel = std::chrono::high_resolution_clock::now();
//    MultMatrix res2 = mtx1.multMatrixParallel(mtx2);
//    auto endParallel = std::chrono::high_resolution_clock::now();
//
//    auto sequentialTime = std::chrono::duration_cast
//            <std::chrono::nanoseconds>(endSequential - startSequential);
//    auto parallelTime = std::chrono::duration_cast
//            <std::chrono::nanoseconds>(endParallel - startParallel);
//    std::cout << "Effectiveness: " <<
//    static_cast<double>(sequentialTime.count())
//                                  / parallelTime.count() << '\n';
//    ASSERT_NO_THROW();
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
