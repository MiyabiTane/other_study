from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
import time
import argparse
from datetime import datetime

def get_driver():
 
    chrome_options = webdriver.ChromeOptions()
    chrome_options.add_argument('--incognito')
    chrome_options.add_experimental_option("excludeSwitches", ['enable-automation'])
 
    driver = webdriver.Chrome(ChromeDriverManager().install(), options=chrome_options)
    driver.set_page_load_timeout(600)
    driver.implicitly_wait(2)
    driver.set_script_timeout(600)
    return driver
 
def is_bussy(driver):
    bussyMessage = driver.find_elements_by_class_name("textalign")
    if len(bussyMessage) > 0 and bussyMessage[0].text.find('アクセスが集中') != -1:
        return True
    else:
        return False

def check_date(driver, ymd, park):
    url = 'https://www.tokyodisneyresort.jp/ticket/index/' + ymd[:6] + '?park=' + park + 'ticket'
    while True:
        driver.get(url)
        # print(driver.page_source)
        avairables = driver.find_elements_by_class_name('js-modal-open-calendar2')
        for avairable in avairables:
            text = avairable.get_attribute('innerHTML')
            # ava_day = avairable.find_elements_by_class_name("day")
            if '"day">' + str(ymd[6:8]) + '<' in text:
                print("=================")
                print("== チケットに空きがあります ==")
                print("=================")
                return True
            else:
                time.sleep(0.5)

# ３秒ごとに予約画面へアクセス
def access_page(driver, ymd, park):
    if check_date(driver, ymd, park):
        url = 'https://reserve.tokyodisneyresort.jp/ticket/search/?outside=1&route=1&useDays=1&useDateFrom=' + ymd + '&parkTicketSalesForm=1'
        while True:
            driver.get(url)
            try:
                driver.find_element_by_class_name('new-ui-theme')
                break
            except:
                time.sleep(0.5)
        print('アクセス完了！！')
 

if __name__ == '__main__':
    driver = get_driver()
    parser = argparse.ArgumentParser()
    parser.add_argument("--year", required="True")
    parser.add_argument("--month", required="True")
    parser.add_argument("--day", required="True")
    parser.add_argument("--park", choices=["tdl", "tds"], default="tdl")
    args = parser.parse_args()
    year = str(args.year)
    month = '0' + str(args.month) if len(str(args.month)) == 1 else str(args.month)
    day = '0' + str(args.day) if len(str(args.day)) == 1 else str(args.day)
    ymd = str(year) + str(month) + str(day)
    access_page(driver, ymd, args.park)
