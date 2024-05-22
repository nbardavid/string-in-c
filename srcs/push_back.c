/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:33:32 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/22 16:22:25 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/c_string.h"
#include <stdlib.h>

void str_push_back(string *str, char c){
	if (str->capacity > str->size + 1){
		str->data[str->size] = c;
	}
	else {
		str->data = realloc(str->data, str->capacity + 1);
		if (!str->data) return;
		str->data[str->size] = c;
		str->size++;
		str->capacity++;
	}
}
