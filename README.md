# Philosophers with Threads and Mutexes

This project is a C implementation of the classic dining philosophers problem using threads and mutexes. To avoid conflicts over shared resources (forks), the program utilizes mutexes for synchronization.

## Overview

In this project, we model the dining philosophers problem, where multiple philosophers sit at a round table, and there is a bowl of spaghetti in the middle. Each philosopher alternates between eating, thinking, and sleeping. They must use two adjacent forks to eat. The simulation continues until a philosopher dies of starvation or all philosophers have eaten a specified number of times.

The primary goal of this project is to demonstrate multi-threading concepts, such as creating and managing threads, using mutexes to protect shared resources, and avoiding potential data races.

## How to Run

To run the "philo" program, simply execute the compiled binary in your terminal with appropriate command-line arguments.

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## Command-line Arguments
The program accepts the following command-line arguments:

1. ```number_of_philosophers```: The number of philosophers sitting at the table (and also the number of forks).
2. ```time_to_die```: The time (in milliseconds) after which a philosopher dies if they haven't started eating since the last meal or the beginning of the simulation.
3. ```time_to_eat```: The time (in milliseconds) it takes for a philosopher to eat. They must hold two forks during this time.
4. ```time_to_sleep```: The time (in milliseconds) a philosopher spends sleeping.
5. ```number_of_times_each_philosopher_must_eat``` (optional): If specified, the simulation stops when all philosophers have eaten this many times. If not provided, the simulation stops when a philosopher dies.

## Requirements
- C compiler (GCC or Clang)
- POSIX Threads (pthread library, usually preinstalled)
- GNU Make (usually preinstalled)

## Building the Program
To compile the program, navigate to the "philo" directory and run the ```make``` command.

This will generate the executable philo inside of the philo folder.

## Usage Example
Here's an example of how to run the "Philo" program with 5 philosophers, 800 milliseconds time to die, 200 milliseconds time to eat, and 200 milliseconds time to sleep:

```bash
./philo 5 800 200 200
```
