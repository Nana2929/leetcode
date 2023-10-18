'''
You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).
https://leetcode.com/problems/parallel-courses-iii/description/?envType=daily-question&envId=2023-10-18


Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
Output: 8
Explanation: The figure above represents the given graph and the time required to complete each course.
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.


Idea: Topological sort
概念就是先找到一群 indegree = 0 的點為開頭，然後逐步刪掉這些點，並且把他們的鄰居的 indegree - 1，如果發現有新的 indegree = 0 的點，就把他們加入開頭的群組中，重複這個步驟直到所有的點都被刪掉。
'''
from typing import List
from collections import defaultdict, deque
class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:

        # 2023/10/18 Daily Challenge
        # By reading the topological sort algorithm, I am able to get 70% of the code right
        # But I did not update the time during the topological ordering procedure
        # the # bars note the lines that I did not write in my first attempt.


        topo = []
        indeg = [0 for _ in range(n+1)]
        adjs = defaultdict(list)
        ####################
        maxtime = [0 for _ in range(n+1)]
        ####################
        for (i,j) in relations:
            indeg[j] +=1
            adjs[i].append(j)

        heads = []
        for i in range(1, n+1):
            if indeg[i] == 0:
                heads.append(i)
                ###############################
                # HERE, update the time also!!
                maxtime[i] = time[i-1]
                ###############################

        q = deque(heads)
        # 0 as the starting point
        topo.append(heads)
        while q:
            course = q.popleft()
            next_courses = adjs[course]
            temp = []
            for nc in next_courses:
                indeg[nc] -= 1
                ###############################
                # HERE, update the time also!!
                weight = time[nc-1]
                maxtime[nc] = max(maxtime[nc], maxtime[course] + weight)
                ###############################
                if indeg[nc] == 0:
                    temp.append(nc)
                    q.append(nc)
            if temp:
                topo.append(temp)
        return max(maxtime)
