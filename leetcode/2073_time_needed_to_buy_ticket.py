class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        return sum(min(ticket, tickets[k] if i <= k else tickets[k] - 1) for i, ticket in enumerate(tickets))