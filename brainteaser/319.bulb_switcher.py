class Solution:
    def bulbSwitch(self, n: int) -> int:

        # 目前有想到可以用 factor decomposition
        # Observe factor decomposition
        # Observe the problem
        # the bubble would be toggled for x times where x is the number of divisors
        # what matters is not x itself, but whether x is an odd or an even number
        # Observe that a number should ideally have pair-wise divisors
        # eg. 2 = 1 x 2 (1,2)
        # eg. 3 = 1 x 3 (1,3)
        # eg. 6 = 1 x 6, 2 x 3 (1,2,3,6)
        # eg. 15 = 1 x 15, 3 x 5 (1,3,5,15)
        # eg. 18 = 1 x 18, 2 x 9, 3 x 6 (1,2,3,6,9,18)
        # but some numbers do not, those numbers are:
        # eg. 1: 1
        # eg. 4: 1, 2, 4
        # eg. 9: 1, 3, 9
        # -> lemma: Perfect square numbers have odd number of divisors, therefore they would be toggled for odd number of times. Assuming all are turned off at the beginning, after n-round toggling, only those bulbs (1-indexed) with perfect-sqr indexed would be turned on at last.
        # The question is equivalent to
        # "find the number of perfect squares <= n"

        import math
        return math.floor(math.sqrt(n))
