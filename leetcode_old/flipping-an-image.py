class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        flipped = []
        for row in image:
            flipped.append(list(map(lambda x: 0 if x == 1 else 1, row[::-1])))
        return flipped
