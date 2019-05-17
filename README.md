# fillit

Hopefully this passes. It is an iterative version. There is only one possible optimization that I can think of,
each piece can point to the last piece of the same type that has been placed. I partially have this optimization with the
g_place_prunning array that records the last piece of type[n]. But it can only record the last one and cannot backtrack
two prior. I may have thought of a way to do this however by creating an array to store pointers and when one is placed
place the pointer there.
