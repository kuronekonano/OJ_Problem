class TrieNode:
    def __init__(self):
        self.end = False
        self.child = [None] * 26
    
    def insert(self, word):
        cur = self
        for i in word:
            code = ord(i) - ord("a")
            if cur.child[code] is None:
                cur.child[code] = TrieNode()
            cur = cur.child[code]
        cur.end = True

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        self.root.insert(word)
        
    def search(self, word: str) -> bool:
        def dfs(idx, cur: TrieNode):
            if idx == len(word):
                return cur.end
            if word[idx] != ".":
                code = ord(word[idx]) - ord("a")
                if cur.child[code]:
                    return dfs(idx + 1, cur.child[code])
            else:
                for node in cur.child:
                    if not node:
                        continue
                    ans = dfs(idx + 1, node)
                    if ans:
                        return ans
            return False
        return dfs(0, self.root)


# 输入：
# ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
# [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
# 输出：
# [null,null,null,null,false,true,true,true]


if __name__ == "__main__":
    s = WordDictionary()
    s.addWord("bad")
    s.addWord("dad")
    s.addWord("mad")
    print("======")
    print(s.search("pad"))
    print(s.search("bad"))
    print(s.search(".ad"))
    print(s.search("b.."))
