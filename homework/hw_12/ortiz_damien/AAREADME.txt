Linux:
real    0m0.791s
user    0m0.696s
sys     0m0.138s

C++:
real    0m0.133s
user    0m0.042s
sys     0m0.089s

Python:
real    0m0.381s
user    0m0.254s
sys     0m0.120s

Above is an example using the /data/courses/ece_1111/resources/data/text/data_v00.txt file.

All three versions of our word frequency programs do not have the same time of completion.

C++ was the fastest as everything was read line by line, compiled at once, and run as a single process.

Python was the second fastest as had a larger overhead than C++ but still ran in a single script.

Linux was the slowest because it had the most overhead involved. When we used the sort command every single line had to be read and reordered twice.
This meant that data was reread and rewritten multiple times. 

If you look at the weirdBreakFile, you can see how each program handles breaks between words that are not simply whitespaces.
All three programs seperated hello and world into different words and counted properly.

If you look at mixedCap, we can see how these files handle mixed capitalization. All three files will convert words to lowercase before comparison,
so the sort is capital insensitive and the results are all the same.
