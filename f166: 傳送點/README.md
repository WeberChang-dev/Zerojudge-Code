是個有點tricky的BFS<br>
可能是因為傳送的原因 先走過該點不代表到該點的操作次數最少<br>
所以要定義steps[]為每個點的操作次數 S(prev) = next<br>
要steps[prev] + 1 < steps[next]才能走<br>
老實說如果我有考那次APCS 賽後judge根本看不出來@@<br>
