# Tree And Tents

<!-- \begin{figure}[h]
\centering
\includegraphics[width=2in]{TODO.jpg}
\caption{TODO: 圖片說明}
\end{figure} -->

在一個棋盤上，有一些樹。你必須放置一些帳篷，使得每行／每列的帳篷數量符合該行／列的要求。

放置帳篷有些條件：

1. 帳篷必須和樹相鄰
2. 帳篷不得相鄰。

請構造出一個放置帳篷的方法。

\clearpage

## 輸入

第一行有兩個整數 $n$，$m$。

接下來一行有 $n$ 個整數 $r_1, r_2, \dots, r_n$ ，以空白分隔，$r_i$ 代表第 $i$ 橫列需要幾頂帳篷。

接下來一行有 $m$ 個整數 $c_1, c_2, \dots, c_m$，以空白分隔，$c_i$ 代表第 $i$ 直行需要幾頂帳篷。

接下來有 $n$ 行，每行有 $m$ 個字元，描述 $n \times m$ 的棋盤。\text{T} 代表樹，\text{.} 代表空地。

## 輸出

輸出 $n$ 行，每行 $m$ 個字元，代表放置帳篷後的棋盤。以 \text{T} 代表樹，\text{.} 代表空地，\text{A} 代表帳篷。

若無解請輸出 \text{QwQ}。

## 輸入限制
 - $1 \le n,m \leq 8$
 - $1 \le r_i \le m$
 - $1 \le c_i \le n$


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
