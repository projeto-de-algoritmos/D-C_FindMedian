from typing import List

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        def merge_sort(enum):
            if len(enum) <= 1:
                return enum

            mid = len(enum) // 2
            left = merge_sort(enum[:mid])
            right = merge_sort(enum[mid:])
            merged = []
            i, j = 0, 0
            while i < len(left) or j < len(right):
                if j == len(right) or (i < len(left) and left[i][1] <= right[j][1]):
                    merged.append(left[i])
                    counts[left[i][0]] += j
                    i += 1
                else:
                    merged.append(right[j])
                    j += 1
            return merged

        counts = [0] * len(nums)
        merge_sort(list(enumerate(nums)))
        return counts
