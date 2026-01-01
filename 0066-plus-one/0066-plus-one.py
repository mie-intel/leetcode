class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        x = 0
        for i in range(len(digits)):
            x = (x * 10) + digits[i]
        x += 1
        p = []
        while x > 0:
            p.append(x % 10)
            x = x // 10
        return p[::-1]