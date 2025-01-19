/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:58:41 by cgross-s          #+#    #+#             */
/*   Updated: 2025/01/12 20:03:43 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

/**
 * The function reads data from a file descriptor and appends it to a stash 
 * until a newline character is found or the end of the file is reached.
 * 
 * @param fd The parameter "fd" in the function "read_and_stash" represents the 
 * file descriptor of thefile that is being read from.
 * 
 * @param stash The `stash` parameter is a character pointer that represents a 
 * string where we want to store the data read from the file descriptor `fd`.
 * 
 * @return the updated value of the "stash" variable.
 */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
 * The function "extract_line" takes a string as input and returns a new string 
 * containing the characters up to the first newline character, including the 
 * newline character if it exists.
 * 
 * @param stash The `stash` parameter is a pointer to a string that contains 
 * multiple lines of text.
 * 
 * @return a pointer to a string that represents a line  extracted from the 
 * input string "stash".
 */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
 * The function "clean_stash" removes the first line from a string and returns 
 * the modified string.
 * 
 * @param stash The parameter "stash" is a pointer to a string that needs to be
 * cleaned.
 * 
 * @return a pointer to a new string that is a cleaned version of the input 
 * string "stash".
 */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


/**
 * The function "get_next_line" reads a line from a file descriptor and returns 
 * it as a string.
 * 
 * @param fd The parameter "fd" stands for file descriptor. It is an integer 
 * value that represents an open file in the operating system. In this context, 
 * it is used to specify the file from which the function should read the next 
 * line.
 * 
 * @return a string, which represents the next line read from the file 
 * descriptor specified by `fd`.
 */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//main

/*
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
*/