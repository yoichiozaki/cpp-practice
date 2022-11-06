class Solution:
    def mostPopularCreator(self, creators: List[str], ids: List[str], views: List[int]) -> List[List[str]]:
        totalview = defaultdict(int)
        videos = defaultdict(list)
        for creator, id, view in zip(creators, ids, views):
            totalview[creator] += view
            videos[creator].append((-view, id))
        m = max(totalview.values())
        return [[creator, min(video)[1]] for creator, video in videos.items() if totalview[creator] == m]