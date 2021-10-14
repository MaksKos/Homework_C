#include <gtest/gtest.h>

extern "C" {
    #include "fun.h"
}

TEST (fun_test, assert_NULL){
    size_t num = 1;
    EXPECT_EQ(delete_element(NULL), -1);
    EXPECT_EQ(get_information(NULL), -1);
    EXPECT_EQ(print_result(&num, NULL), -1);
    EXPECT_EQ(delete_arr(NULL, &num), -1);
}

TEST (pointer_test, assert_pointer){
    size_t num = 5;
    Participants *element = create_element();
    Participants **result = (Participants**) calloc(num, sizeof(Participants*));
    for(size_t i = 0; i < num; i++){
        result[i] = create_element();
    }
    EXPECT_EQ(delete_element(element), 0);
    EXPECT_EQ(delete_arr(result, &num), 0);
    
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

