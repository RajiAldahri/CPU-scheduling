# CPU Scheduling Algorithms Simulator

## Overview

This C program simulates and compares the performance of three CPU scheduling algorithms: First Come First Serve (FCFS), Shortest Job First (SJF), and Priority. The user is prompted to input the number of processes, CPU burst times, and priorities. The program calculates and displays the waiting times for each process under each algorithm, along with the average waiting time for each. The conclusion section determines which algorithm is the most efficient based on the average waiting times.

## Code Breakdown

### 1. Memory Allocation
The program dynamically allocates memory for arrays to store burst times (`bt` and `bt1`), process IDs (`p`), waiting times (`wt`), priorities (`pr`), and arrival times (`at`).

### 2. Input
User input is obtained for the number of processes, CPU burst times, and priorities using the `scanf_s` function.

### 3. FCFS Algorithm
- Calculates waiting times and average waiting time for the FCFS algorithm.
- Displays waiting times for each process.

### 4. SJF Algorithm
- Sorts processes based on burst times in ascending order.
- Calculates waiting times and average waiting time for the SJF algorithm.
- Displays waiting times for each process.

### 5. Priority Algorithm
- Sorts processes based on priorities in ascending order.
- Calculates waiting times and average waiting time for the Priority algorithm.
- Displays waiting times for each process.

### 6. Conclusion
Compares the average waiting times for FCFS, SJF, and Priority algorithms and concludes which one is the most efficient.

### 7. Memory Deallocation
Releases the dynamically allocated memory before exiting the program.

### 8. Improvement
It's worth noting that the SJF and Priority algorithms use the same array (`p`) for storing process IDs, which might lead to confusion. It might be clearer to use separate arrays for process IDs in these cases.

### 9. Potential Issue
The program assumes that the user enters valid inputs for burst times and priorities. There is no input validation to check if the entered values are non-negative or within a reasonable range. Adding input validation could enhance the robustness of the program.

## Key Features

- **Dynamic Memory Allocation:** Efficiently manages process details using dynamic memory allocation.
- **User-Friendly Input:** Utilizes `scanf_s` for safer and user-friendly input.
- **Algorithm Simulation:** Implements FCFS, SJF, and Priority scheduling algorithms.
- **Performance Metrics:** Calculates and displays waiting times and average waiting times.
- **Conclusion Section:** Determines the most efficient scheduling algorithm.

## Note

- The program is designed for educational purposes to illustrate the workings of basic CPU scheduling algorithms.
- Consideration for input validation and clarity of process IDs in SJF and Priority sections.

## How to Use

1. **Clone the Repository:**
 
   ```bash
   git clone https://github.com/RajiAldahri/CPU-scheduling.git
   
2. **Compile and Run:**

- Compile the C program using an appropriate compiler.
- Run the executable and follow the on-screen prompts to input process details.

3. **View Results:**

- Examine waiting times and average waiting times for FCFS, SJF, and Priority algorithms.
- Read the conclusion to determine the most efficient scheduling algorithm.

## Contribution
Contributions and suggestions for improvements are welcome. Please open an issue or submit a pull request.
