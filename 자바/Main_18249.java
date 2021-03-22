import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main_18249 {

	static int answer;
	static int T,N;
	static int dp[];
	static StringBuilder sb;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		T=Integer.parseInt(br.readLine());
		dp=new int[191230];
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=191229;i++) {
			dp[i] = (dp[i-1]+dp[i-2])%1000000007;
		}

		for(int tc=0;tc<T;tc++) {
			N=Integer.parseInt(br.readLine());
			sb.append(dp[N]+"\n");
			
		}
		System.out.println(sb);
	}
	
//	private static int dp(int n) {
//		if(n==1) return 1;
//		if(n==2) return 2;
//		
//		else return dp(n-1)%1000000007+dp(n-2)%1000000007;
//		
//	}
	

}
