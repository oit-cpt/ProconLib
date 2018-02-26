# ProconLib
プロコンライブラリ

[![CircleCI](https://circleci.com/gh/oit-cpt/ProconLib.svg?style=svg)](https://circleci.com/gh/oit-cpt/ProconLib)

# テストの実行
## cpplint
```bash
make lint
```

## 単体テスト
```bash
make build
make test
```

# コードの自動整形
```bash
make format ファイル名
```

`make lint` に引っかかった時はこれを実行すればエラーはかなり減るはず
