# ProconLib
プロコンライブラリ

[![CircleCI](https://circleci.com/gh/oit-cpt/ProconLib.svg?style=svg)](https://circleci.com/gh/oit-cpt/ProconLib)

# Library List
## データ構造
- [x] UnionFind
- [ ] SegmentTree
- [ ] Trie木
- [ ] BIT(Binary-Indexed-Tree)

## グラフ
- [x] BellmanFord
- [x] Prim
- [ ] Dijkstra
- [ ] Kruskal
- [ ] Dinic
- [ ] BipartiteMatching

## 木
- [ ] 直径(TreeDiameter)

## 数学

## 幾何

## 文字列

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
make format FILE=ファイル名
```

`make lint` に引っかかった時はこれを実行すればエラーはかなり減るはず
