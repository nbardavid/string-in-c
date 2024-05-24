/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:32:31 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/24 15:24:19 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "../include/c_string.h"

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

//to do: fancy infos
void str_info(const string *str){
    printf("===\ncontent: \"%s\"\nsize: %d\ncapacity: %d\n===\n", str->data, str_length(str), str_capacity(str));
}

string string_init_str(char *str) {
	string ptr;

	ptr.data = strdup(str);
	ptr.size = strlen(ptr.data);
	ptr.capacity = ptr.size + 1;
	return ptr;
}

int main(int argc, char **argv){
    (void)argc;
    (void)argv;
	// string str = STRING_L("Hello world!");

 //    /* Testing str_resize && str_set */
 //    str_resize(&str, 8);
 //    str_info(&str);
 //    str_assign(&str, "HELLO WORLD!");
 //    str_info(&str);
 //    str_resize(&str, 25);
 //    str_info(&str);
	//
 //    /* Testing str_reserve */
 //    str_reserve(&str, 100);
 //    str_info(&str);
	//
 //    /* Testing str_shrink_to_fit */
	// str_shrink_to_fit(&str);
	// str_info(&str);
	//
 //    /* Testing str_clear */
	// str_clear(&str);
	// str_info(&str);

    /* Testing str_append */
	string app = STRING_L("Hello");
	string end = STRING_L(" world!");
	str_append(&app, &end);
	str_info(&app);
	// str_info(&end);
	
	str_insert(&app, "UUUU", 5);
	str_info(&app);
	str_erase(&app, 5, 4);
	str_info(&app);
	
	str_pop_front(&app);
	str_info(&app);
	printf("\"o\": %zu\n", str_find(&app, "o"));
	printf("\"o\": %zu", str_rfind(&app, "o"));

	// str_destroy(&str);
	str_destroy(&app);
	str_destroy(&end);
    return 0;
}
