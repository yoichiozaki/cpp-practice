class TimeMap:

    def __init__(self):
        self.table = dict()
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.table:
            self.table[key] = [(timestamp, value)]
        else:
            idx = bisect_left(self.table[key], (timestamp, ""))
            if idx == len(self.table[key]):
                self.table[key].append((timestamp, value))
            elif self.table[key][idx][0] == timestamp:
                self.table[key][idx] = (timestamp, value)
            else:
                self.table[key] = self.table[key][:idx] + [(timestamp, value)] + self.table[key][idx:]
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.table:
            return ""
        else:
            idx = bisect_left(self.table[key], (timestamp, ""))
            if idx == len(self.table[key]):
                return self.table[key][idx-1][1]
            elif self.table[key][idx][0] == timestamp:
                return self.table[key][idx][1]
            else:
                if idx == 0:
                    return ""
                else:
                    return self.table[key][idx-1][1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

# 二分探索を使うという方向性はあっていそう。ただ実装が長い気がする。