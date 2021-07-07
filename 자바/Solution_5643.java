package ssafyalgo_s0412;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution_5643 {

	static int T, N, M, answer;
	static boolean[] visit;
	static StringTokenizer st;
	static ArrayList<Integer>[] info1;
	static ArrayList<Integer>[] info2;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			M = Integer.parseInt(br.readLine());
			answer=0;
			info1 = new ArrayList[N + 1];
			info2 = new ArrayList[N + 1];
			for (int i = 1; i <= N; i++) {
				info1[i] = new ArrayList<>();
				info2[i] = new ArrayList<>();
			}

			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int small = Integer.parseInt(st.nextToken());
				int big = Integer.parseInt(st.nextToken());
				
				info1[small].add(big);
				info2[big].add(small);
				
			}
			
			for(int i=1;i<=N;i++) {
				if(bfs(i)) answer++;
			}

			sb.append("#" + tc + " " + answer + "\n");
		}
		System.out.println(sb);
	}

	private static boolean bfs(int start) {
		visit = new boolean[N + 1];
		Queue<Integer> q = new LinkedList<>();
		visit[start] = true;
		q.add(start);
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int i=0;i<info1[cur].size();i++) {
				int next = info1[cur].get(i);
				if(visit[next]) continue;
				visit[next]=true;
				q.add(next);
			}
		}
		
		q.add(start);
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int i=0;i<info2[cur].size();i++) {
				int next = info2[cur].get(i);
				if(visit[next]) continue;
				visit[next]=true;
				q.add(next);
			}
		}
		
		for(int i=1;i<=N;i++) {
			if(!visit[i]) return false;
		}
		
		return true;
	}

}
