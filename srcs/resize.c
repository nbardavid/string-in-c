/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:21:23 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/22 11:28:44 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/c_string.h"
#include <stdlib.h>
#include <string.h> 

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
