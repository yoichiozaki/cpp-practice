# トリプルブッキングになるのは時間帯。ダブルブッキングするイベント数を数えるやり方だと、別々の時間帯のダブルブッキングをトリプルブッキングとしてカウントしてしまう
class MyCalendarTwo:

    def __init__(self):
        self.calendar = []
        self.already_double_booked = []

    def book(self, start: int, end: int) -> bool:
        if len(self.calendar) == 0:
            self.calendar.append([start, end])
            return True
        
        for event in self.already_double_booked:
            if max(start, event[0]) < min(end, event[1]):
                return False # Adding [start, end] makes triple booking.
            
        for event in self.calendar:
            if max(start, event[0]) < min(end, event[1]):
                self.already_double_booked.append([max(start, event[0]), min(end, event[1])])
        self.calendar.append([start, end])
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)