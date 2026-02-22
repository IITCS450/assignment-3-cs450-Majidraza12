# Lottery Scheduling Results

## Setup

The lottery scheduler was tested using three CPU-bound child processes with different ticket counts. Each child process called `settickets()` to assign its own number of tickets before performing a CPU-intensive loop. The processes ran concurrently for a fixed duration measured using the `uptime()` system call.

The ticket distribution used in the experiment was:

- Process A: 10 tickets  
- Process B: 20 tickets  
- Process C: 40 tickets  

This setup was chosen to verify that CPU time is allocated in proportion to the number of tickets assigned to each process.

## Workload

Each process executed a tight CPU-bound loop that incremented a counter until a fixed runtime threshold was reached. This ensured that all processes continuously competed for CPU time, allowing the scheduler to distribute time slices based on lottery selection.

The runtime was increased to reduce variance and observe convergence toward expected CPU shares.

## Observed Results

Example output from a long run:
PID 6 tickets=40 count=1127246
PID 4 tickets=10 count=304800
PID 5 tickets=20 count=587920


The expected proportional CPU shares were:

- 10 tickets → 1 unit  
- 20 tickets → 2 units  
- 40 tickets → 4 units  

Using the 10-ticket process as a baseline:

- Expected for 20 tickets ≈ 609600  
- Observed for 20 tickets = 587920  

- Expected for 40 tickets ≈ 1,219,200  
- Observed for 40 tickets = 1,127,246  

The observed values closely matched the expected proportions.

## Discussion and Variance

As lottery scheduling is a probabilistic method, the results of individual runs may not be completely accurate in comparison to what is expected; however, as time continues to elapse, the total amount of CPU time allocated will come closer and closer to what was expected. The randomness of the scheduling process will become less random because of the law of large numbers: given enough time and an increasing number of scheduling decisions, the average of the allocated CPU time will begin to approach the theoretical allocation that was to be expected.

Shorter runs showed larger deviations due to randomness, while longer runs produced results much closer to expected values.

## Conclusion

The experiment confirms that the lottery scheduler correctly distributes CPU time in proportion to ticket counts. The results demonstrate both fairness and convergence over time, validating the correctness of the implementation.