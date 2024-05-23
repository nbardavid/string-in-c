/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:32:48 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/23 16:41:42 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct {
	char *data;
	size_t size;
	size_t capacity;
} string;

// ************************************************
// *                   capacity                   *
// ************************************************

int str_length(const string *str);
void str_resize(string *str, size_t size);
int str_capacity(const string *str);
void str_reserve(string *str, size_t reserve);
void str_clear(string *str);
int str_empty(string *str);
void str_shrink_to_fit(string *str);

void str_append(string *str, string *str2);

void str_assign_right_size(string *str, size_t len);
