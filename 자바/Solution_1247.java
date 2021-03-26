import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1247 {

	static int T,N,answer;
	static Pair[] arr;
	static StringTokenizer st;
	
	static class Pair {
		Integer y;
		Integer x;
		
		public Pair(Integer y , Integer x) {
			this.y=y;
			this.x=x;
		}
		
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T=Integer.parseInt(br.readLine());
		
		for(int tc=1;tc<=T;tc++) {
			N=Integer.parseInt(br.readLine());
			answer=1000000;
			
			arr = new Pair[N+2];
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<N+2;i++) {
				int y,x;
				y=Integer.parseInt(st.nextToken());
				x=Integer.parseInt(st.nextToken());
				arr[i] = new Pair(y, x);
			}
			backtracking(0,0,0,arr[0]);
			System.out.printf("#%d ",tc);
			System.out.println(answer);
		}

	}


	private static void backtracking(int cnt, int flag, int dist, Pair last) {
		
		if(dist>answer) {
			return;
		}
		
		if(cnt==N) {

			int tmp = Math.abs(last.y-arr[1].y)+Math.abs(last.x-arr[1].x);
			answer = Math.min(answer, dist+tmp);
			return;
		}
		
		for(int i=2;i<N+2;i++) {
			if((flag&1<<i)!=0) continue;
			int tmp;
			tmp = Math.abs(last.y-arr[i].y)+Math.abs(last.x-arr[i].x);
			backtracking(cnt+1, flag|1<<i, dist+tmp, arr[i]);
		}
		
	}

}
