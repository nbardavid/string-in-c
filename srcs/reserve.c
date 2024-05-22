/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:22:07 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/22 11:28:29 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/c_string.h"
#include <stdlib.h>

void str_reserve(string *str, int reserve){
    if (reserve > str->capacity){
        char *temp_str = realloc(str->data, reserve + 1);
        if (temp_str){
            str->data = temp_str;
            str->capacity = reserve + 1;
        }
    }
}
