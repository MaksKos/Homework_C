#include <string.h>
#include "fun.h"

Participants* create_element(){

    Participants *new_struct = calloc(1, sizeof(Participants));
    if(new_struct == NULL){
        return NULL;
    }

    new_struct->name = calloc(CHAR_SIZE, sizeof(char));
    if (new_struct->name == NULL){
        delete_element(new_struct);
        return NULL;
    }

    new_struct->company = calloc(CHAR_SIZE, sizeof(char));
    if (new_struct->company == NULL){
        delete_element(new_struct);
        return NULL;
    }

    new_struct->position = calloc(CHAR_SIZE, sizeof(char));
    if (new_struct->position == NULL){
        delete_element(new_struct);
        return NULL;
    }

    return new_struct;
}

int delete_element(Participants *element){
    if (element == NULL) {
        return -1;
    }
    if (element->company != NULL){
        free(element->company);
    }
    if (element->name != NULL){
        free(element->name);
    }
    if (element->position != NULL){
        free(element->position);
    }
    free(element);
    return 0;

}

int get_information(Participants *element_info)
{
    if (element_info == NULL){
        return -1;
    }

    char id[CHAR_SIZE];
    printf("Enter id:\n");
    scanf("%15s", id);
    element_info->id = strtoul(id, NULL, 10);

    printf("Enter name:\n");
    scanf("%15s", element_info->name);

    printf("Enter position:\n");
    scanf("%15s", element_info->position);

    printf("Enter company:\n");
    scanf("%15s", element_info->company);

    char importance[CHAR_SIZE];
    printf("Enter importance in percent:\n");
    scanf("%15s", importance);
    element_info->importance = strtoul(importance, NULL, 10);

    return 0;
}

int print_result(const size_t *num,Participants *const *arr_elemnts){
    if(arr_elemnts == NULL){
        return -1;
    }
    if((*num) < 1){
        return -1;
    }
    for(size_t i=0; i < (*num); i++){
        printf("\nInformation about participant_%zu:\nID: %zu\nName: %s\nCompany: %s\nPosition: %s\nImportance: %zu\nCoinsidered: %zu/5\n", 
                i, arr_elemnts[i]->id,  arr_elemnts[i]->name, arr_elemnts[i]->company, arr_elemnts[i]->position, 
                arr_elemnts[i]->importance, arr_elemnts[i]->coinside);
    }
    printf("\n");
    return 0;
}

Participants **get_result(Participants *data, const Participants *elemnt_info, const size_t *size,  size_t *num){

    if(*size < 1 || size == NULL){
        return NULL;
    }
    if(data == NULL || elemnt_info == NULL){
        return NULL;
    }
    size_t count = 0;    

    for (size_t i=0; i<(*size); i++){

        if(data[i].id == elemnt_info->id)
            data[i].coinside++;

        if(strcmp(data[i].name, elemnt_info->name) == 0)
            data[i].coinside++;

        if(strcmp(data[i].position, elemnt_info->position) == 0)
            data[i].coinside++;

        if(strcmp(data[i].company, elemnt_info->company) == 0)
            data[i].coinside++;   

        if(data[i].importance == elemnt_info->importance)
            data[i].coinside++;

        if(data[i].coinside > 0){
            count++;
        } 
    }

    if(count == 0){
        printf("not found\n");
        return NULL;
    }
    *num = count;

    Participants **result = calloc(count, sizeof(Participants*));
    if (result == NULL){
        return NULL;
    }

    for(size_t i = 0; i < count; i++){
        result[i] = create_element();
        if (result[i] == NULL){
            fprintf(stderr,"error_create");
            return NULL;
        }
    }
    for(size_t i = 0; i < (*size); i++){
        if(data[i].coinside > 0){
            count--;
            result[count]->id = data[i].id;
            if(strcpy(result[count]->name, data[i].name) == NULL){
                return NULL;
            }
            if(strcpy(result[count]->company, data[i].company) == NULL){
                return NULL;
            }   
            if(strcpy(result[count]->position, data[i].position) == NULL){
                return NULL;
            }
            result[count]->importance = data[i].importance;
            result[count]->coinside = data[i].coinside;
        }
    }
    return result;
    
}

int delete_arr(Participants **arr,const size_t *num){
    if (arr == NULL || num == NULL){
        return -1;
    }
    for (size_t i = 0; i < (*num); i++){
        if(delete_element(arr[i]) != 0 ){
            fprintf(stderr, "error_delete\n");
            return -1;
        }
    }
    free(arr);
    return 0;
}
