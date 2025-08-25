class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        ans = 1
        max_d = -1
        for i in damage:
            if i > max_d:
                max_d = i
            if armor !=0 and i >= armor:
                ans += i - armor
                armor = 0
            else:
                ans += i
        if armor != 0:
            ans -= max_d
        return ans
            