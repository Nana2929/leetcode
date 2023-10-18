# https://leetcode.com/problems/pascals-triangle-ii/
# see images/pascal.png
from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # by this: https://zhuanlan.zhihu.com/p/257895125
        # we know that given rowIndex, we should return C(rowIndex, 0) , ... , C(rowIndex, rowIndex) (Combinatorics)
        from math import comb

        halfIndex = int(rowIndex / 2)
        ans = [1 for _ in range(rowIndex + 1)]
        for i in range(halfIndex + 1):
            ans[i] = comb(rowIndex, i)
        if rowIndex % 2 == 0:
            ans[halfIndex + 1 :] = reversed(ans[:halfIndex])
        else:
            ans[halfIndex + 1 :] = reversed(ans[: halfIndex + 1])
        return ans


# Each row of Pascal's Triangle can be represented using the sequence of combinations:
# C(r,0),C(r,1),C(r,2),…,C(r,r)C(r, 0), C(r, 1), C(r, 2), \ldots, C(r, r)C(r,0),C(r,1),C(r,2),…,C(r,r)
# formula: https://www.nagwa.com/en/explainers/458103573928/
# C(n, k-1) * (n-k+1) / k = C(n, k)
