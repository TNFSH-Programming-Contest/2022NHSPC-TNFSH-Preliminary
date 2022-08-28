#

<!-- \begin{figure}[h]
\centering
\includegraphics[width=2in]{TODO.jpg}
\caption{TODO: 圖片說明}
\end{figure} -->


給定一張 $n$ 點 $m$ 邊的連通無向圖，並且邊 $i$ 有邊權 $w_i$。

保證不存在自環和重邊。

給定點 $s$ 和點 $t$。

$q$ 次詢問 $x$，請回答拔除邊 $x$ 後，$s$ 到 $t$ 的最短路是否會改變（各詢問皆獨立）？

\clearpage

## 輸入

第一行有四個整數 $n$、$m$、$s$、$t$，表示該圖有 $n$ 點 $m$ 邊和點 $s$、點 $t$。

接下來 $m$ 行，每行依序描述邊 $1, 2, \dots, m$。每行有三個整數 $u_i, v_i, w_i$，表示點 $u_i$ 到 $v_i$ 中有邊權為 $w_i$ 的邊。

接下來一行，有一整數 $q$，表示有 $q$ 次詢問。

接下來 $q$ 行，每行包含一個數字 $x$，請回答拔除邊 $x$ 後，$s$ 到 $t$ 的最短路是否會改變。

## 輸出

輸出 $q$ 行，若拔除邊 $x$ 後，$s$ 到 $t$ 的最短路會改變輸出 "`yes`"，否則輸出 "`no`"。

## 輸入限制
 - $1 \le n \leq 2 \times 10^5$
 - $1 \le q \le m \le 10^6$
 - $1 \le s, t, u_i, v_i \le n$
 - $s \ne t$
 - $1 \le x \le m$
 - $1 \le w_i \le 10^9$

## 子任務
\subtasks

\clearpage

## 範例輸入1
```
4 5 1 4
1 3 1
1 2 2
3 2 1
3 4 3
2 4 1
5
1
2
3
4
5
```

## 範例輸出1
```
no
no
no
no
yes
```

## 範例輸入2
```
5 5 2 5
1 2 1
2 3 1
3 4 1
4 5 1
5 1 20
5
1
2
3
4
5
```

## 範例輸出2
```
no
yes
yes
yes
no
```

