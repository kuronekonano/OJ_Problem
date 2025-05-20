class Solution:
    KEY_M = {1: "I", 5: "V", 10: "X", 50: "L", 100: "C", 500: "D", 1000: "M"}

    def intToRoman(self, num: int) -> str:

        def roman(one, five, ten, value):
            if value < 4:
                return value * one
            if value == 4:
                return one + five
            if value == 5:
                return five
            if 5 < value < 9:
                return five + one * (value - 5)
            if value == 9:
                return one + ten

        ans = []
        ans.append(roman("M", "", "", num // 1000))
        num = num % 1000
        ans.append(roman("C", "D", "M", num // 100))
        num = num % 100
        ans.append(roman("X", "L", "C", num // 10))
        num = num % 10
        ans.append(roman("I", "V", "X", num))
        return "".join(ans)


if __name__ == "__main__":
    s = Solution()
    print(s.intToRoman(3749))
    print(s.intToRoman(58))
    print(s.intToRoman(1994))
