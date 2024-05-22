/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:32:31 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/22 12:20:05 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "../include/c_string.h"

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

    /* Testing str_shrink_to_fit */
	str_shrink_to_fit(&str);
	str_info(&str);

    /* Testing str_clear */
	str_clear(&str);
	str_info(&str);

    /* Testing str_append */
	string app;
	string end;
	str_init(&app, "Hello");
	str_init(&end, " world!");
	str_append(&app, &end);
	str_info(&app);
	str_info(&end);

	str_destroy(&str);
	str_destroy(&app);
	str_destroy(&end);
    return 0;
}
