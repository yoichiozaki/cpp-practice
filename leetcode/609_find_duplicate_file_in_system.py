class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        map = defaultdict(list)
        for line in paths:
            data = line.split()
            root = data[0]
            for file in data[1:]:
                name, _, content = file.partition('(')
                map[content[:-1]].append(root + '/' + name)
        return [ele for ele in map.values() if len(ele) > 1]
