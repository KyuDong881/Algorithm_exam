import java.util.*;
import java.io.*;

public class Main_17299 {

	private static int N;
	private static int[] A, nA, F, answer;
	
	private static class Pair {
		int idx;
		int val;
		public Pair(int idx,int val) {
			this.idx = idx;
			this.val = val;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(br.readLine());
		A = new int[N];
		nA = new int[N];
		answer = new int[N];
		F=new int[1000001];
		Arrays.fill(answer, -1);

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
			F[A[i]]++;
		}
		for(int i=0;i<N;i++) nA[i] = F[A[i]];
		
		Stack<Pair> stack = new Stack<>();
		stack.add(new Pair(0,nA[0]));
		for(int i=1;i<N;i++) {
			int cur = nA[i];
			while(!stack.isEmpty()&&cur>stack.peek().val) answer[stack.pop().idx]=A[i];
			stack.add(new Pair(i,cur));
		}
		for(int val:answer) sb.append(val).append(" ");
		System.out.println(sb);
	}

}
