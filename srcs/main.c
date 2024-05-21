/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:32:31 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/21 20:04:35 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "../include/temp.h"

void str_init(string *str, const char *content){
    int len = strlen(content);
    if (len == 0){
        str->data = NULL;
        str->size = 0;
        str->capacity = 0;
    } else {
        str->data = malloc(len + 1);
        memcpy(str->data, content, len + 1);
        str->size = len;
        str->capacity = len + 1;
    }
}

void str_destroy(string *str){
    free(str->data);
    str->data = NULL;
    str->size = 0;
    str->capacity = 0;
}

int str_length(const string *str){
    return str->size;
}

void str_resize(string *str, int size) {
    char *temp_str = realloc(str->data, size + 1);
    if (temp_str) {
        str->data = temp_str;
        if (size > str->size) {
            memset(str->data + str->size, ' ', size - str->size);
        }
        str->data[size] = '\0';
        str->size = size;
        str->capacity = size + 1;
    }
}

void str_set(string *str, const char *content){
    int len = content ? strlen(content) : 0;
    char *temp_str = realloc(str->data, len + 1);
    if (temp_str) {
        str->data = temp_str;
        if (content) {
            memcpy(str->data, content, len + 1);
        } else {
            str->data[0] = '\0';
        }
        str->size = len;
        str->capacity = len + 1;
    }
}

int str_capacity(const string *str){
    return str->capacity;
}

void str_reserve(string *str, int reserve){
    if (reserve > str->capacity){
        char *temp_str = realloc(str->data, reserve + 1);
        if (temp_str){
            str->data = temp_str;
            str->capacity = reserve + 1;
        }
    }
}

//to do: fancy infos
void str_info(const string *str){
    printf("===\ncontent: \"%s\"\nsize: %d\ncapacity: %d\n===\n", str->data, str_length(str), str_capacity(str));
}

int main(int argc, char **argv){
    (void)argc;
    (void)argv;
    string str;
    str_init(&str, "Hello world!");
    str_info(&str);

    /* Testing str_resize && str_set */
    str_resize(&str, 8);
    str_info(&str);
    str_set(&str, "HELLO WORLD!");
    str_info(&str);
    str_resize(&str, 25);
    str_info(&str);

    /* Testing str_reserve */
    str_reserve(&str, 100);
    str_info(&str);

    str_destroy(&str);
    return 0;
}
