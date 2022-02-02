class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        H = len(image)
        W = len(image[0])
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        original_color = image[sr][sc]
        suspended = [(sr, sc)]
        while len(suspended) != 0:
            h, w = suspended.pop(0)
            image[h][w] = newColor
            for dh, dw in dirs:
                nh = h + dh
                nw = w + dw
                if 0 <= nh < H and 0 <= nw < W and image[nh][nw] == original_color and image[nh][nw] != newColor:
                    suspended.append((nh, nw))
        return image
