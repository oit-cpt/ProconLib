# ProconLib
プロコンライブラリ

[![CircleCI](https://circleci.com/gh/oit-cpt/ProconLib.svg?style=svg)](https://circleci.com/gh/oit-cpt/ProconLib)

# Library List
## データ構造
- [x] UnionFind
- [ ] SegmentTree
- [ ] BIT(Binary-Indexed-Tree)
- [ ] Treap

## グラフ
- [x] BellmanFord
- [x] Prim
- [ ] Dijkstra
- [ ] Kruskal
- [ ] Dinic
- [ ] BipartiteMatching
- [ ] 橋の検出
- [ ] 強連結成分分解

## 木
- [ ] 直径(TreeDiameter)
- [ ] Heavy Light Decomposition
- [ ] Lowest Common Ancestor

## 数学
- [ ] 逆元の計算
- [ ] あるmodでの nCr, nPr, nHr の計算

## 幾何

## 文字列
- [ ] ローリングハッシュ
- [ ] Trie木
- [ ] suffix array
- [ ] Aho–Corasick

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
