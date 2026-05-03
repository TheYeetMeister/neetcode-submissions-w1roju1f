class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n = len(hand)

        if n % groupSize != 0:
            return False

        cnt = Counter(hand)

        minHeap = []

        for card, count in cnt.items():
            heapq.heappush(minHeap, card)

        while minHeap:
            chosenCard = []
            card = heapq.heappop(minHeap)
            chosenCard.append(card)
            cnt[card] -= 1

            for i in range(groupSize - 1):
                if not minHeap or minHeap[0] - 1 != card:
                    return False

                card = heapq.heappop(minHeap)
                chosenCard.append(card)
                cnt[card] -= 1

            for chCard in chosenCard:
                if cnt[chCard] > 0:
                    heapq.heappush(minHeap, chCard)
        
        return True
