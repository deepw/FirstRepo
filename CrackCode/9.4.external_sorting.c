/*
 * 9.4 If you have a 2 GB file with one string per line, which sorting algorithm would you use to sort the file and why?
 */

Use External Sorting

Memory is 11MB. 
Basically split the big file into small parts. Lets say 1000MB into 10 chunks of 10MB each. 
Now sort each of the 10 MB chunks at at time. 
Now create 10 buffers of 1MB each. And write to a new buffer of 1 MB. Keep refilling the other 10 buffers from respective sorted files. 


