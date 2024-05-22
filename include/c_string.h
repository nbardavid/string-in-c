/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:32:48 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/22 12:18:00 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct {
	char *data;
	int size;
	int capacity;
} string;

// ************************************************
// *                   capacity                   *
// ************************************************

int str_length(const string *str);
void str_resize(string *str, int size);
int str_capacity(const string *str);
void str_reserve(string *str, int reserve);
void str_clear(string *str);
int str_empty(string *str);
void str_shrink_to_fit(string *str);

void str_append(string *str, string *str2);
