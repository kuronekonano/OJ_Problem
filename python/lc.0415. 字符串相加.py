class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        def get_num(string):
            num = 0
            for i in string:
                num = num * 10 + (ord(i) - ord('0'))
            return num
        def get_str(num):
            if num == 0:
                return "0"
            string = ""
            while num:
                string += str(num % 10)
                num //=10
            return string[::-1]
        return get_str(get_num(num1) + get_num(num2))