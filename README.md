# minitalk
42 Berlin | Level 2: minitalk

This is an introductory project to UNIX. The goal is to create a small data exchange program that uses UNIX signals.

Mandatory Part:

You must create a communication program in the form of a client and a server.
• The server must be started first. After its launch, it has to print its PID.
• The client takes two parameters:
	◦ The server PID.
	◦ The string to send.
• The client must send the string passed as a parameter to the server.
  Once the string has been received, the server must print it.
• The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
• Your server should be able to receive strings from several clients in a row without
needing to restart.
• The communication between your client and your server has to be done only using
UNIX signals.
• You can only use these two signals: SIGUSR1 and SIGUSR2.

Bonus Part:

• The server acknowledges every message received by sending back a signal to the
client.
• Unicode characters support!

Resources:
# About signals

https://www.geeksforgeeks.org/fork-system-call/

https://www.geeksforgeeks.org/wait-system-call-c/

https://www.geeksforgeeks.org/signals-c-language/

https://www.geeksforgeeks.org/signals-c-set-2/?ref=gcse

https://www.geeksforgeeks.org/write-a-c-program-that-doesnt-terminate-when-ctrlc-is-pressed/?ref=gcse

# Other students

https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24

https://42-cursus.gitbook.io/guide/rank-02/minitalk

# Difference between signal and sigaction

https://itecnote.com/tecnote/the-difference-between-sigaction-and-signal/

# How to write advanced signal handlers in Unix

https://www.oracle.com/technical-resources/articles/it-infrastructure/dev-signal-handlers-studio.html
