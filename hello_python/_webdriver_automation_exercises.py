from selenium import webdriver
from selenium.webdriver.common.by import By
from time import sleep as delay_by_seconds
from pprint import pprint

def main():
    driver = webdriver.Chrome()
    driver.maximize_window()
    driver.get("https://google.com")
    all_li = driver.find_elements(By.TAG_NAME, 'a')
    print(len(all_li))
    pprint(all_li)
    delay_countdown(5)
    driver.quit()


def delay_countdown(secs=3):
    for count in range(secs, 0, -1):
        print(f"Closing in {count} {'seconds' if count>1 else 'second'}.")
        delay_by_seconds(1)


run_program = 'y'
while run_program.lower() != 'q':
    # _________write program flow from here____________________________
    main()
    # ---------end the program by pressing 'q'-------------------------
    run_program = input("\nPress 'q' to exit program or other keys to continue: ")
