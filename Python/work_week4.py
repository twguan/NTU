import requests
from bs4 import BeautifulSoup

#import LineNotifyAPI as Line

url = 'https://time.com/'

r = requests.get(url)
soup = BeautifulSoup(r.text, 'html.parser')
titles = soup.find_all(class_='title no-eyebrow')

s="Today's News\n"
for line in titles:
    s += line.text.strip() + '\n'

#Line.lineNotify(msg = s)