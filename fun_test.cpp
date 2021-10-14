#include <gtest/gtest.h>

extern "C" {
    #include "fun.h"
}

TEST (fun_test, assert_NULL){
   size_t *num = nullptr;
    size_t size = 1;
    Participants *element = create_element();
    EXPECT_FALSE(element == NULL);
    EXPECT_EQ(delete_element(NULL), -1);
    EXPECT_EQ(get_information(NULL), -1);
    EXPECT_EQ(print_result(&size, NULL), -1);
    EXPECT_EQ(delete_arr(NULL, &size), -1);
    EXPECT_EQ(delete_arr(NULL, NULL), -1);

    EXPECT_EQ(get_result(element, NULL, &size, num), nullptr);
    EXPECT_EQ(get_result(NULL, element, &size,  num),nullptr);

    EXPECT_FALSE(delete_element(element) != 0);
}

TEST (pointer_test, assert_pointer){
    size_t num = 5;
    Participants *element = create_element();
    EXPECT_FALSE(element == NULL);
    Participants **result = (Participants**) calloc(num, sizeof(Participants*));
    EXPECT_FALSE(result == NULL);
    for(size_t i = 0; i < num; i++){
        result[i] = create_element();
        EXPECT_FALSE(result[i] == NULL);
    }
    EXPECT_EQ(delete_element(element), 0);
    EXPECT_EQ(delete_arr(result, &num), 0);
    
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

