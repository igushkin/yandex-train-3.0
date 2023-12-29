import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if (n == 0) {
            System.out.println(0);
            return;
        }
        if (n == 1) {
            System.out.println(2);
            return;
        }
        if (n == 2) {
            System.out.println(4);
            return;
        }

        var dp = new int[n][3];

        dp[2][0] = 4;
        dp[2][1] = 2;
        dp[2][2] = 1;

        for(int i = 3; i < n; i++){
            dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
            dp[i][1] = dp[i-1][0];
            dp[i][2] = dp[i-1][1];
        }

        System.out.println(dp[n-1][0] + dp[n-1][1] + dp[n-1][2]);
    }
}