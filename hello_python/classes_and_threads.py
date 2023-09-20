import time
from threading import Thread


class Worker(Thread):
    def run(self):
        for x in range(0, 11):
            print(self.name, x)
            time.sleep(1)


class Waiter(Thread):
    def run(self):
        for x in range(100, 103):
            print(self.name, x)
            time.sleep(5)


print("\nStarting Worker Thread")
Worker().start()
print("\nStarting Waiter Thread")
Waiter().start()
print("\nDone")