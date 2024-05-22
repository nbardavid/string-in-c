/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:02:42 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/22 16:26:41 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/c_string.h"
#include <stdlib.h>
#include <string.h>

void str_append(string *str, string *str2){
	if (!str_empty(str2)){
		if (str->capacity >= str->size + str2->size + 1){
			memcpy(str->data + str->size, str2->data, str2->size + 1);
		}
		else{
			str->data = realloc(str->data, str_length(str) + str_length(str2) + 1);
			if (!str->data) return;
			memcpy(str->data + str->size, str2->data, str2->size + 1);
			str->size += str2->size;
			str->capacity += str2->capacity - 1;
		}
	}
}
