class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        A = 0
        C = 0
        if k % 2 == 0:
            return -1
        while C < 50000:
            A = (A * 10) + 1
            C += 1
            if A % k == 0:
                return C
        return -1
        