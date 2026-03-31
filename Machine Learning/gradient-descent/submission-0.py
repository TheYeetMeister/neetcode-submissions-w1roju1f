class Solution:
    def getDerivative(self, x: int):
        return 2 * x;

    def get_minimizer(self, iterations: int, learning_rate: float, init: int) -> float:
        for _ in range(iterations):
            step: float = learning_rate * self.getDerivative(init) * -1

            init += step;

        return round(init, 5)