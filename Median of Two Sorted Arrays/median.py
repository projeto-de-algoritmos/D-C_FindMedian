class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Combina os dois arrays em um array ordenado
        merged = sorted(nums1 + nums2)
        
        # Encontra o comprimento do array combinado
        total_length = len(merged)
        
        # Verifica se o comprimento total é par ou ímpar
        if total_length % 2 == 0:
            # Se for par, retorna a média dos dois elementos do meio
            meio1 = merged[total_length // 2 - 1]
            meio2 = merged[total_length // 2]
            return (meio1 + meio2) / 2
        else:
            # Se for ímpar, retorna o elemento do meio
            return merged[total_length // 2]
