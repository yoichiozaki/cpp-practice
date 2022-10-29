# これまでの予定の一つとでも時間帯が重なればダブルブッキング: O(N)
# 明らかに無駄がある
class MyCalendar:

    def __init__(self):
        self.books = []
        

    def book(self, start: int, end: int) -> bool:
        if len(self.books) == 0:
            self.books.append([start, end])
            return True
        double_booking = any(max(start, book[0]) < min(end, book[1]) for book in self.books)
        if double_booking:
            return False
        self.books.append([start, end])
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)

# 予定を昇順に持っておく。入りそうな位置の前後で重ならないかを確認する。
import bisect
class MyCalendar:

    def __init__(self):
        self.books = []
        

    def book(self, start: int, end: int) -> bool:
        if len(self.books) == 0:
            self.books.append([start, end])
            return True
        idx = bisect.bisect_right(self.books, [start, end])
        if (0 < idx and start < self.books[idx - 1][1]) or (idx < len(self.books) and self.books[idx][0] < end):
            return False
        self.books.append([start, end])
        self.books.sort()
        return True
            


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)