from typing import List
from collections import defaultdict


class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        if not votes:
            return ""
        if len(votes) == 1:
            return votes[0]
        t_count = len(votes[0])
        score = defaultdict(lambda: [0] * t_count)
        ans = []
        for vote in votes:
            for rk, t in enumerate(vote):
                score[t][rk] += 1
        return "".join(
            [
                k
                for k, _ in sorted(
                    score.items(), key=lambda x: (x[1], -ord(x[0])), reverse=True
                )
            ]
        )
        # 复杂度就是那么高，重点在于 python 和 cpp 的 sort 都能对变长数组自动根据值相同继续比下一位做排序
        # 对于 C 和 rust 就要自己写 cmp 对比方法


if __name__ == "__main__":
    s = Solution()
    print(s.rankTeams(["ABC", "ACB", "ABC", "ACB", "ACB"]))
    print(s.rankTeams(["WXYZ", "XYZW"]))
    print(s.rankTeams(["ZMNAGUEDSJYLBOPHRQICWFXTVK"]))
    print(
        s.rankTeams(
            [
                "FVSHJIEMNGYPTQOURLWCZKAX",
                "AITFQORCEHPVJMXGKSLNZWUY",
                "OTERVXFZUMHNIYSCQAWGPKJL",
                "VMSERIJYLZNWCPQTOKFUHAXG",
                "VNHOZWKQCEFYPSGLAMXJIUTR",
                "ANPHQIJMXCWOSKTYGULFVERZ",
                "RFYUXJEWCKQOMGATHZVILNSP",
                "SCPYUMQJTVEXKRNLIOWGHAFZ",
                "VIKTSJCEYQGLOMPZWAHFXURN",
                "SVJICLXKHQZTFWNPYRGMEUAO",
                "JRCTHYKIGSXPOZLUQAVNEWFM",
                "NGMSWJITREHFZVQCUKXYAPOL",
                "WUXJOQKGNSYLHEZAFIPMRCVT",
                "PKYQIOLXFCRGHZNAMJVUTWES",
                "FERSGNMJVZXWAYLIKCPUQHTO",
                "HPLRIUQMTSGYJVAXWNOCZEKF",
                "JUVWPTEGCOFYSKXNRMHQALIZ",
                "MWPIAZCNSLEYRTHFKQXUOVGJ",
                "EZXLUNFVCMORSIWKTYHJAQPG",
                "HRQNLTKJFIEGMCSXAZPYOVUW",
                "LOHXVYGWRIJMCPSQENUAKTZF",
                "XKUTWPRGHOAQFLVYMJSNEIZC",
                "WTCRQMVKPHOSLGAXZUEFYNJI",
            ]
        )
    )
    # VWFHSJARNPEMOXLTUKICZGYQ
    print(s.rankTeams([]))
