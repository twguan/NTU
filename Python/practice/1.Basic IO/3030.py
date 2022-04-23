from cmath import sqrt
import math

n = int(input())
adj = math.sqrt(n)*10
print("Original: %.2f" % n)
print("Adjusted: %.2f(+%0.f)" % (adj, adj-n))