/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:33:32 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/24 15:44:35 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/c_string.h"
#include <stdlib.h>

void str_push_back(string *str, size_t c){
	str_assign_right_size(str, str->size + 1);
	str->data[str->size] = c;
	str->size++;
}
