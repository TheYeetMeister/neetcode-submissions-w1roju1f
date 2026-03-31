import torch
from typing import List, Tuple

class Solution:
    def batch_loader(self, raw_dataset: str, context_length: int, batch_size: int) -> Tuple[List[List[str]]]:
        # You must start by generating batch_size different random indices in the appropriate range
        # using a single call to torch.randint()
        torch.manual_seed(0)

        tokens: List[str] = raw_dataset.split()
        numOfTokens: int = len(tokens)
        permutationStart: int = numOfTokens - context_length

        X = []
        Y = []
        for _ in range(batch_size):
            startPick: int = int(torch.randint(0, permutationStart, (1, )))
            endPick: int = startPick + context_length

            X.append(tokens[startPick: endPick ])
            Y.append(tokens[startPick + 1: endPick + 1])

        return (X, Y)
