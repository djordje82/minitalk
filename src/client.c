/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:29:17 by dodordev          #+#    #+#             */
/*   Updated: 2024/02/27 17:08:54 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*Sure, here's the pseudocode for the highlighted code:

1. Declare a static integer `g_control` and initialize it to 0.

2. Define a function `waitforanswer`:
   - Declare an integer `i` and initialize it to 0.
   - While `g_control` equals 0:
     - If `i` equals 50, call `exit_on_error` with the message "Timeout!\n".
     - Pause the execution for a short period.
     - Increment `i`.
   - Reset `g_control` to 0.

3. Define a function `send_char_to_server` that takes an unsigned char `c` and a process ID `server_pid`:
   - Declare an unsigned char `bit` and initialize it to `0b10000000`.
   - While `bit` is not 0:
     - If `bit` AND `c` is true:
       - If sending `SIGUSR1` to `server_pid` fails, call `exit_on_error` with an appropriate error message.
     - Otherwise:
       - If sending `SIGUSR2` to `server_pid` fails, call `exit_on_error` with an appropriate error message.
     - Call `waitforanswer`.
     - Shift `bit` one bit to the right.

4. Define a function `sig_handler` that takes an integer `signum`:
   - Set `g_control` to 1.
   - If `signum` equals 12, write "confirmation received!\n" to the standard output.

5. Define a function `str_to_c` that takes a process ID `pid` and a string `str`:
   - Declare an integer `i` and initialize it to 0.
   - While `str[i]` is not the null character:
     - Call `send_char_to_server` with `str[i]` and `pid`.
     - Increment `i`.
   - Call `send_char_to_server` with 0 and `pid`.
   - Return 1.

6. Define the `main` function that takes `argc` and `argv`:
   - If `argc` is not 3, or `argv[1]` is not a valid process ID, or `argv[2]` is null, return 0.
   - Convert `argv[1]` to a process ID and store it in `pid`.
   - Set `sig_handler` as the handler for `SIGUSR1` and `SIGUSR2`.
   - If `str_to_c` with `pid` and `argv[2]` returns false, return 0.*/