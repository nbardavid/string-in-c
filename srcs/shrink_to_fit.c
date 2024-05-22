/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrink_to_fit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:21:11 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/22 11:28:26 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/c_string.h"
#include <stdlib.h>

void str_shrink_to_fit(string *str){
	if (str->capacity != str->size + 1){
		char *temp_str = realloc(str->data, str->size + 1);
		if (temp_str){
			str->data = temp_str;
			str->capacity = str->size + 1;
		}
	}
}
