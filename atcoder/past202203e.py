import datetime

D = datetime.date.fromisoformat(input().replace('/', '-'))
while len({c for c in D.isoformat()}) > 3:
    D += datetime.timedelta(days=1)
print(D.isoformat().replace('-', '/'))
