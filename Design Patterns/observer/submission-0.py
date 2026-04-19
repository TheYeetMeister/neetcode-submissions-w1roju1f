class Observer(ABC):
    @abstractmethod
    def notify(self, itemName: str) -> None:
        pass

class Customer(Observer):
    def __init__(self, name: str) -> None:
        self.name = name
        self.notifications = 0

    def notify(self, itemName: str) -> None:
        self.notifications += 1

    def countNotifications(self) -> int:
        return self.notifications

class OnlineStoreItem:
    def __init__(self, itemName: str, stock: int) -> None:
        self.itemName = itemName
        self.stock = stock
        self.subList = set()

    def subscribe(self, observer: Observer) -> None:
        self.subList.add(observer)

    def unsubscribe(self, observer: Observer) -> None:
        self.subList.remove(observer)

    def updateStock(self, newStock: int) -> None:
        if self.stock == 0 and newStock > 0:
            for observer in self.subList:
                observer.notify(self.itemName)
        
        self.stock = newStock
        
