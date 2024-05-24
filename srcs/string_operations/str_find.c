/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:44:46 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/24 15:32:29 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/c_string.h"
#include <string.h>

size_t str_find(const string *str, const char *to_find){
	size_t len = strlen(to_find);
	size_t i = 0; size_t j = 0; while(i < str->size - len){
		while(str->data[i] == to_find[j] && i < str->size - len){
			if (to_find[j + 1] == '\0')
				return i - j;
			j++; i++;
		}
		i++; j = 0;
	}
	return str->size;
}
