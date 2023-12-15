#include "../array-lib/array.h"
#include "testing_tools.h"


void test_array() {
    pprint("Array1D tests started");
    Array1D arr1({1., 2., 3.});
    Array1D arr2({-2., 0., 1.});

    Array1D arr3 = arr1 + arr2;
    IS_TRUE(arr3 == Array1D({-1., 2., 4.}));

    Array1D arr4 = arr1 + 1.;
    IS_TRUE(arr4 == Array1D({2., 3., 4.}));

    Array1D arr5 = arr1;
    IS_TRUE(arr5 == Array1D({1., 2., 3.}));

    Array1D arr6 = arr4 - arr3;
    IS_TRUE(arr6 == Array1D({3., 1., 0.}));

    Array1D arr7 = arr1 - 1.;
    IS_TRUE(arr7 == Array1D({0., 1., 2.}));

    Array1D arr8 = arr1 * arr2;
    IS_TRUE(arr8 == Array1D({-2., 0., 3.}));

    Array1D arr9 = arr1 * 2.;
    IS_TRUE(arr9 == Array1D({2., 4., 6.}));

    double dot_product = arr1.dot(arr2);
    IS_TRUE(dot_product == 1.);

    Array1D arr10 = Array1D({1., 2., 3., 4.});
    THROWS(arr10.dot(arr1));

    pprint("Array1D tests finished");
}


// void test_matrix() {
//     Matrix mat1 = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
//     Array2D arr1(mat1);
//     arr1.print();
//     Array2D arr2 = arr1;
//     arr2.print();
//     Array2D arr3 = arr1 + arr2;
//     arr3.print();
//     Array2D arr4 = arr1 + 1.;
//     arr4.print();
//     Array2D arr5 = arr3 - arr4;
//     arr5.print();
//     Array2D arr6 = arr1 - 1.;
//     arr6.print();
//     Array2D arr7 = arr1 * arr2;
//     arr7.print();
//     Array2D arr8 = arr1 * 2.;
//     arr8.print();
//     Array2D matrix_prod = arr1.dot(arr6);
//     matrix_prod.print();
// }


// void test_matrix_vector() {
//     Matrix mat1 = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
//     Array2D arr1(mat1);
//     arr1.print();
//     Array1D arr2({2., -2., 1.});
//     arr2.print();
//     Array1D arr3 = arr1.dot(arr2);
//     arr3.print();
// }