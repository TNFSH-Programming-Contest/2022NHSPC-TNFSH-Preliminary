#

<!-- \begin{figure}[h]
\centering
\includegraphics[width=2in]{TODO.jpg}
\caption{TODO: 圖片說明}
\end{figure} -->

有 $2n$ 個人，第 $i$ 個人會有 $a_i$ 顆糖果。
現在他們想要兩兩組成一組，共 $n$ 組，
並且將同一組人的糖果重新分配，使得兩人糖果的數量相同。

你能夠告訴他們是否能達成目標嗎 ?

\clearpage

## 輸入
輸入第一行有一個正整數 $n$ ，代表總共有 $2n$ 個人。
輸入第二行有 $2n$ 個正整數，代表每個人擁有的糖果數量，也就是 $a_i$ 。

## 輸出
輸出一行 "Yes" 如果他們能達成目標，反之則為 "No" (不需輸出雙引號) 。

## 輸入限制
- $n \leq 10^5$
- $a_i \leq 5 \times 10^6, \forall 1 \leq i \leq 2n$

## 子任務
\subtasks

\clearpage

## 範例輸入 1
\testfile{0-01.in}

## 範例輸出 1
\testfile{0-01.out}

## 範例輸入 2
\testfile{0-02.in}

## 範例輸出 2
\testfile{0-02.out}
