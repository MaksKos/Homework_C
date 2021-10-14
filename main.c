#include "fun.h"
#define SIZE 4

int main()
{
    size_t size = SIZE;
    size_t num;
    Participants test_data[SIZE] ={
        {1, "Mike", "programmist", 55, "Mail", 0},
        {2, "Alex", "client", 85, "System", 0},
        {3, "Yana", "intern", 10, "Mail", 0},
        {4, "Klim", "intern", 4, "Mail", 0}
    };

    Participants *information = create_element();
    if(information == NULL){
        return -1;
    }

    if(get_information(information) != 0){
        delete_element(information);
        return -1;
    }

    Participants **result = get_result(test_data, information, &size, &num);

    if( result == NULL){
        delete_element(information);
        free(result);
        return -1;
    }

    delete_element(information);

    if(print_result(&num, result) != 0){
        printf("Error\n");
        delete_arr(result, &num);
        return -1;
    };

    delete_arr(result, &num);
    return 0;
}

