# 最小最大全距

<!-- \begin{figure}[h]
\centering
\includegraphics[width=2in]{TODO.jpg}
\caption{TODO: 圖片說明}
\end{figure} -->

給定一個長度為 $n$ 的數列 $a$ 以及一個小於 $n$ 的正整數 $k$。
你需要將這個數列的每個元素都分到 $1$ 到 $k$ 組中的其中一組，並且要讓這 $k$ 中最大的全距盡可能的小。

\clearpage

## 輸入
輸入第一行有兩個正整數 $n,k$ 。
輸入第二行有 $n$ 個正整數，代表 $a_1, a_2 ... a_n$ 。

## 輸出
輸出一行，包含一個整數，代表這 $k$ 組中最小可能的最大全距。

## 輸入限制
- $1 \leq k \leq n \leq 10^6$
- $1 \leq a_i \leq 10^9, \forall 1 \leq i \leq n$


## 子任務
\subtasks

\clearpage

## 範例輸入
```
6 2
8 7 1 5 10 9
```

## 範例輸出
```
4
```
