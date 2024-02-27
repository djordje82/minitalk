/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:28:47 by dodordev          #+#    #+#             */
/*   Updated: 2024/02/27 16:55:25 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



/*Sure, here's the pseudocode for the highlighted code:

1. Define a function `sig_print` that takes three parameters: an integer `signum`, a pointer to `siginfo_t` named `info`, and a void pointer `ucontent`.

2. Inside `sig_print`, declare two static variables: an integer `i` and a character `bit`.

3. If `signum` is 0, reset `i` and `bit` to 0 and return from the function.

4. If `signum` is 12, increment `i`.

5. If `signum` is 10, add to `bit` the value of 1 shifted left by (7 - `i`), then increment `i`.

6. If `i` equals 8, check if `bit` is 0. If it is, call `print_char` with parameters '\n', 0, and `info->si_pid`, then return. If `bit` is not 0, call `print_char` with parameters `bit`, 1, and `info->si_pid`, then return.

7. Send a `SIGUSR1` signal to the process with ID `info->si_pid`.

8. Define a function `sig_init` that sets up signal handling.

9. Inside `sig_init`, declare a `struct sigaction` named `server_sig`.

10. Initialize `server_sig.sa_mask` to an empty set using `sigemptyset`.

11. Add `SIGUSR1` and `SIGUSR2` to `server_sig.sa_mask` using `sigaddset`.

12. Set `server_sig.sa_sigaction` to the address of the function `sig_print`.

13. Set `server_sig.sa_flags` to `SA_SIGINFO`.

14. Change the action taken by the process on receipt of `SIGUSR1` and `SIGUSR2` to `server_sig` using `sigaction`. If `sigaction` fails, call `exit_on_error` with an appropriate error message.

15. Define the `main` function.

16. Inside `main`, call `sig_init`.

17. Call `print_header` with the process ID as a parameter.

18. Call `sig_print` with parameters 0, NULL, and NULL.

19. Enter an infinite loop where the process is paused.

20. Return 0 from `main`.*/