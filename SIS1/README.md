# epoll() asynchronous system call in Linux kernel

  First run in the terminal :
  # gcc -o epoll_example  epoll_example.c 

  Then run to start it:
  # ./epoll_example 

You will see how it is waiting for an input. First I gave it a small string that fits in the buffer and it works fine and continues iterating over the loop. 
The second input was too long for the read buffer, and is where level triggering helped us out. Events continued to populate until it read all of what was left in the buffer, in edge triggering mode we would have only received 1 notification and the application as-is would not progress until more was written to the file descriptor being watching.
