## ディズニー行くぞぉ！

### 実行方法

初回のみ
```
$ pipenv sync
```

毎回
```
$ pipenv run python main.py --year <XXXX> --month <XX> --day <XX> --park <tds or tdl>
例：pipenv run python main.py --year 2022 --month 01 --day 05 --park tds
```

チケットが取れるまでリロードします
取れたらチケットを選ぶ画面に遷移して止まります