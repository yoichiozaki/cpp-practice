import math
import cmath

N = int(input())
x0, y0 = map(float, input().split())
xN2, yN2 = map(float, input().split())

p0 = complex(x0, y0)
pN2 = complex(xN2, yN2)
o = (p0+pN2)/2
r = cmath.rect(1, 2*math.pi/N)
a = (p0-o)*r+o

print("%.10f %.10f" % (a.real, a.imag))
