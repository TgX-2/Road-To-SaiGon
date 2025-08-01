from sympy import isprime
from itertools import count, islice, product
def A002385gen(): # generator of palprimes
    yield from [2, 3, 5, 7, 11]
    for d in count(3, 2):
        for last in "1379":
            for p in product("0123456789", repeat=d//2-1):
                left = "".join(p)
                for mid in [[""], "0123456789"][d&1]:
                    t = int(last + left + mid + left[::-1] + last)
                    if isprime(t):
                        yield t
print(list(islice(A002385gen(), 100000)))