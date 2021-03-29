import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class algo2 {

	static int n,m;
	static StringTokenizer st;
	static int[] weight,target;
	static char answer;
	static boolean[] dp;
	static StringBuilder sb;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(br.readLine());
		weight = new int[n];
		dp=new boolean[40001];
		sb=new StringBuilder();
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			weight[i]=Integer.parseInt(st.nextToken());
			dp[weight[i]]=true;

		} // 추 무게 정보 입력
		m=Integer.parseInt(br.readLine());
		target = new int[m];
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++) {
			target[i]=Integer.parseInt(st.nextToken());
		}
		
		for(int i=0;i<n;i++) {
			int value = weight[i];
			for(int j=1;j<40001;j++) {
				if(j>15001) break;
				if(dp[j]) {
					dp[Math.abs(j+value)]=true;
					dp[Math.abs(j-value)]=true;
				}
			}
		}
		for(int i=0;i<m;i++) {
			if(dp[target[i]]) sb.append("Y ");
			else sb.append("N" );
		}
		
		System.out.println(sb.toString());
	}


}
