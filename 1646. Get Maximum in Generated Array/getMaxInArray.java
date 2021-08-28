import java.util.Arrays;

class getMaxinArray {
    public int getMaximumGenerated(int n) {
        if (n < 1)
            return 0;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else
                dp[i] = dp[i / 2] + dp[i / 2 + 1];
        }
        // for(int i=0; i<=n; ++i) {
        // System.out.println(dp[i]);
        // }
        return Arrays.stream(dp).max().getAsInt();
    }
}

