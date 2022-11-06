class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        clock = 0
        elapsed = 0
        for customer in customers:
            arrival = customer[0]
            preparing = customer[1]
            if clock < arrival:
                clock = arrival
            next_clock = clock + preparing
            elapsed  += next_clock - arrival
            clock = next_clock
        return elapsed / len(customers)