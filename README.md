# get_next_line
A function that returns a line read from a file descriptor.

<pre>
<code>
int get_next_line(const int fd, char **line);
</code>
</pre>

The first parameter is the file descriptor that will be used to read.

The second parameter is the address of a pointer to a character that will be used
to save the line read from the file descriptor.

The return value can be 1, 0 or -1 depending on whether a line has been read,
when the reading has been completed, or if an error has happened respectively.
