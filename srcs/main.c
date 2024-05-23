/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:32:31 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/23 16:54:33 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void str_assign(string *str, const char *content){
	size_t len = strlen(content);
	str_assign_right_size(str, len);
	memcpy(str->data, content, len + 1);
	str->size = len;
}

void str_assign_right_size(string *str, size_t len){
	while(str->capacity < len + 1){
		str->data = realloc (str->data, str->capacity << 2);
		str->capacity = str->capacity << 1;

	}
}

void str_insert(string *str, const char *str2, size_t i){
	size_t len = strlen(str2);
	str_assign_right_size(str, len + str->size);
	memmove(str->data + i + len, str->data + i, str -> size - i + 1);
	memcpy(str->data + i, str2, len);
	str->size += len;
}

void str_erase(string *str, size_t pos, size_t len){
	memmove(str->data + pos, str->data + pos + len, str->size - pos - len + 1);
	str->size -= len;
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
    str_assign(&str, "HELLO WORLD!");
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
	// str_info(&end);
	
	str_insert(&app, "UUUU", 5);
	str_info(&app);
	str_erase(&app, 5, 4);
	str_info(&app);

	str_destroy(&str);
	str_destroy(&app);
	str_destroy(&end);
    return 0;
}
