class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        if '0' not in binary: 
            return binary
        k, n = binary.count('1', binary.find('0')), len(binary)
        return '1' * (n - k - 1) + '0' + '1' * k