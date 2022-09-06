# FRANXX 配對

\begin{figure}[h]
\centering
\includegraphics[width=2in]{img.jpg}
\caption{廣第一次與02一起操縱FRANXX，出自動畫《Darling in the FRANXX》}
\end{figure}

在遙遠的未來，人類在尋找新能源時發現了「熔岩燃料」，但開採「熔岩燃料」會吸引「叫龍」的攻擊。為對抗叫龍，科學家集團 APE 發明了戰鬥機甲 FRANXX，並將男孩和女孩訓練成「操縱者」，兩人配成一對共同駕駛 FRANXX 與叫龍作戰。

隨著技術的進步，APE 開發了一套將駕駛員駕駛 FRANXX 的各種能力綜合起來並量化的評分系統，名稱為「能力值」。而 FRANXX 也不限於一男一女共同駕駛了，任意性別配對皆可以駕駛，只需要符合「兩位駕駛員的能力值總和需為偶數」這個條件就能讓這兩位駕駛員一起駕駛 FRANXX。

現在有 $2n$ 位操縱者，其中第 $i$ 位操縱者的能力值為 $a_i$，APE 想委託你幫他們計算這群操縱者們是否可以兩兩組成一隊，共駕駛 $n$ 個 FRANXX 去對抗叫龍。你能幫他們完成這個任務嗎 ?

\clearpage

## 輸入
輸入第一行有一個正整數 $n$ ，代表總共有 $2n$ 位操縱者。\
輸入第二行有 $2n$ 個正整數，代表每個人的能力值，也就是 $a_i$ 。

## 輸出
輸出一行 "Yes" 如果他們能成功兩兩配成一對，反之則為 "No" (不需輸出雙引號) 。

## 輸入限制
- $1 \leq n \leq 10^5$
- $1 \leq a_i \leq 5 \times 10^6$

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
