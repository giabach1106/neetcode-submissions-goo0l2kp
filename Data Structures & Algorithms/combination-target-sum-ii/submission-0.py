class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res  = []
        candidates.sort()

        def dfs(total, cur, i):
            if total == target:
                res.append(cur.copy())
                return
            if total > target or i >= len(candidates):
                return
            cur.append(candidates[i])
            dfs(total + candidates[i], cur, i + 1);
            cur.pop()
            while i + 1 < len(candidates) and candidates[i] == candidates[i+1]:
                i += 1
            dfs(total, cur, i+1)
        dfs(0, [], 0)
        return res