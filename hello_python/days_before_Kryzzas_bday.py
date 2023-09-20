import datetime as dt
from os import system
from time import sleep

Kryzzas_bday = dt.datetime(2023, 8, 10)
for count in range(1, 10):
    todays_datetime = dt.datetime.now()
    countdown = Kryzzas_bday - todays_datetime
    print(f"\r{countdown} left "
          f"before Kryzza's birthday.", end="", flush=True)
    sleep(1)  # 1 second delay
