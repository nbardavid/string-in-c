/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:32:48 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/24 15:42:47 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_STRING_H
# define C_STRING_H

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

// ************************************************
// *                 modifiers                    *
// ************************************************

void str_append(string *str, string *str2);
void str_erase(string *str, size_t pos, size_t len);
void str_insert(string *str, const char *str2, size_t i);
void str_pop_back(string *str);
void str_pop_front(string *str);
void str_push_back(string *str, size_t c);

// ************************************************
// *           string operations                  *
// ************************************************

char *str_data(const string *str);
size_t str_find(const string *str, const char *to_find);
size_t str_find_first_of(const string *str, size_t c);
size_t str_find_last_of(const string *str, size_t c);
size_t str_rfind(const string *str, const char *to_find);

// ************************************************
// *                    utils                     *
// ************************************************

void str_assign_right_size(string *str, size_t len);
string string_init_str(char *str);

#define STRING_L(value) string_init_str(value);

#endif // C_STRING_H
