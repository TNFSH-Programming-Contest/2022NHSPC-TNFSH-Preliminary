#

<!-- \begin{figure}[h]
\centering
\includegraphics[width=2in]{TODO.jpg}
\caption{TODO: 圖片說明}
\end{figure} -->

$n*m$的地圖$k$個障礙物
$q$次查詢兩個點是否在同一個連通塊

\clearpage

## 輸入
第一行有三個整數 $n$，$m$，$k$。
接下來有$k$行，每行兩個整數$a,b$，代表障礙物的位置。
下一行有個整數$q$。
然後有$q$行，每行四個整數$a,b,c,d$，代表要查詢的兩個點的位置

## 輸出
輸出$q$行yes或no。

## 輸入限制
$2 \le n,m \le 10^9$
$2 \le k,q \le 10^5$
保證每次詢問的兩個點不會卡在牆壁裡

## 子任務
\subtasks

\clearpage

## 範例輸入
```
4 4 5
1 3
2 1
2 4
3 2
4 3
3
1 1 4 4
3 1 2 2
4 2 3 1

```

## 範例輸出
```
yes
no
yes

```
