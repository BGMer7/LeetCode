class Solution {
    int inf = 100000007;

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[][] memory = new int[n][k + 2];
        int res = dfs(flights, k + 1, dst, src, memory);
        if (res >= inf) {
            return -1;
        }
        return res;
    }

    public int dfs(int[][] flights, int k, int dst, int src, int memory[][]) {
        if (k < 0) {
            return inf;
        }

        if (dst == src) {
            return 0;
        }

        if (memory[src][k] != 0) {
            return memory[src][k];
        }

        int min = inf;

        for (int[] flight : flights) {
            if (flight[0] == src) {
                min = Math.min(min, dfs(flights, k - 1, dst, flight[1], memory) + flight[2]);
                // System.out.println(min);
            }
        }
        memory[src][k] = min;
        return min;
    }
}