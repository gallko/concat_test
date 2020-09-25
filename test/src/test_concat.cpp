#include <gtest/gtest.h>

#include "concat.h"

TEST(concat, all_empty_vector) {
    int v1[]{};
    int v2[]{};
    int result[]{0,0,0};
    int expectation[]{0,0,0};
    test_concat::concat_vectors(v1, 0, v2, 0, result);
    EXPECT_EQ(0, memcmp(result, expectation, 3));
}

TEST(concat, one_empty_vector) {
    int v1[]{5,6,7,9};
    int v2[]{};
    int result[4];
    int expectation[]{5,6,7,9};
    test_concat::concat_vectors(v1, 4, v2, 0, result);
    EXPECT_EQ(0, memcmp(result, expectation, 3));

    test_concat::concat_vectors(v2, 0, v1, 4, result);
    EXPECT_EQ(0, memcmp(result, expectation, 3));
}


TEST(concat, non_empty_vectors) {
    int v1[]{5,6,7,9};
    int v2[]{2,6,9,1,225,9,63};
    int result[11];

    int expectation1[]{5,6,7,9,2,6,9,1,225,9,63};
    int expectation2[]{2,6,9,1,225,9,63,5,6,7,9};

    test_concat::concat_vectors(v1, 4, v2, 7, result);
    EXPECT_EQ(0, memcmp(result, expectation1, 11));

    test_concat::concat_vectors(v2, 7, v1, 4, result);
    EXPECT_EQ(0, memcmp(result, expectation2, 11));
}