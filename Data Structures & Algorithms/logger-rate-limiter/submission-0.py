class Logger:
    def __init__(self):
        self._logger = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self._logger or self._logger[message] <= timestamp - 10:
            self._logger[message] = timestamp
            return True
        return False

        


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
