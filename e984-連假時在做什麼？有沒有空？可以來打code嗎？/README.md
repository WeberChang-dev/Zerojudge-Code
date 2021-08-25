這題挺有趣的<br>
我直接用比較直觀的想法<br>
建string dp[]<br>
先把1~9初始化 再設一個tail紀錄目前右端走到哪<br>
再從左掃 並以int num紀錄dp[i]的個位數<br>
把dp[tail]設為dp[i]+to_string(num-1) 然後tail++(記得排除num==0的情況)<br>
把dp[tail]設為dp[i]+to_string(num) 再tail++(一定可以接)<br>
把dp[tail]設為dp[i]+to_string(num+1) 一樣tail++(記得排除num==9的情況)<br>
簡單來說就是找已經是LunlunNumber的解再接上一位相差不到1的數字 塞在陣列後面<br>
覺得用tail做太麻煩應該可以改用deque 只是記憶體說不定會突破天際<br>
老實說這樣做時間、空間都不怎麼省 就是很直腸子的DP<br>
