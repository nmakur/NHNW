I wrote this code as part of a project to simulate food distribution algorithms.

Given some food donors, each with certain quantities of different types of food, and some food banks, each with certain demand for different types of food, along with costs of travel from each donor to each bank (such that total demand = total supply, for simplicity), what is the cheapest way to deliver all the food so that needs are met?

There are 5 deterministic algorithms implemented:
1. A brute force algorithm that runs extremely slowly in practice, but can be proven to produce the cheapest output.
2. A greedy algorithm (TakeCheap) that picks the cheapest routes and sends all possible food along them in that order
3. A reverse-greedy algorithm (AvoidExpensive) that attempts to discard the most expensive routes as long as it is feasible without making food delivery impossible
4. A second-level greedy algorithm (TakeExpensiveDelta) that prioritizes routes where the next-cheapest route is much more expensive
5. A second-level reverse-greedy algorithm (AvoidCheapDelta) that prioritizes avoiding routes where the next-cheapest route is not much more expensive
There are also 2 probabilistic tweaks on the greedy algorithm, that greedily send all possible food along edges as randomly selected according to either a linear (doLinear) or exponentially-scaled (doSoftmax) probability distribution.
