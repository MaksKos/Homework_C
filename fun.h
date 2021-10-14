#pragma once
#include <stdio.h>
#include <stdlib.h>

#define CHAR_SIZE 16


typedef struct Participants
{
    size_t id;
    char *name;
    char *position;
    size_t importance;
    char *company;
    size_t coinside;

} Participants;


Participants *create_element();
Participants **get_result(Participants *data, const Participants *elemnt_info, const size_t *size, size_t *num);
int delete_element(Participants *element);
int get_information(Participants *element_info);
int print_result(const size_t *num, Participants *const *arr_elemnts);
int delete_arr(Participants **arr,const size_t *num);
