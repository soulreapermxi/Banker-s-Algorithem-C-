# Banker-s-Algorithem-C-
Implementation of the Baker’s Algorithm to check whether a system is in safe state or not. 

This implementation is able to determine whether a resource request from a process
can be safely granted or not.

Initial state of the system including the following properties must be taken as user inputs.
• Number of processors 𝑛.
• Number of resource types 𝑚.

there are taken from text files (Sample input_1,)
• Available: A vector of length 𝑚 indicates the number of available resources of each
type.
• Max: An 𝑛 × 𝑚 matrix defines the maximum demand of each process.
• Allocation: An 𝑛 × 𝑚 matrix defines the number of resources of each type currently
allocated to each process.
Using these user inputs, your program should be able to initialize and update following
data matrices.
• Need: An 𝑛 × 𝑚 matrix indicates the remaining resource need of each process.
• Work and Finish: Vectors of length 𝑚 and 𝑛, respectively. Initially Work = Available
and Finish[𝑖] = false for 𝑖 = 0, 1, . . . , 𝑛 – 1.
Using this information,  program should check whether the system is in safe mode
or not. If it is in the safe mode, then  program s ask for a process number and
its resource Request and check whether that request can be granted or not.


Refer the Section 7.5.3 of Operating System Concepts book for more details of the Banker’s
Algorithm.

https://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/
