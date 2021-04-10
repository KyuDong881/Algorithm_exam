import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class kakao3 {

	public static void main(String[] args) {
		
		int n=6;
		int[] pass = {1,1,1,1,1,1};
		int[][] train = {{1,2},{1,3},{1,4},{3,5},{3,6}};
		solution(6,pass,train);
		
	}

	static ArrayList<Integer>[] info;
	static boolean[] visit;
	static int[] passenger;
	static int[] answer;
	static class Node {
		int cur;
		int saram;
		public Node(int cur, int saram) {
			this.saram = saram;
			this.cur = cur;
		}
	}
	
    public static int[] solution(int n, int[] passenger, int[][] train) {
        info = new ArrayList[n+1];
        visit = new boolean[n+1];
        
        for(int i=1;i<=n;i++) {
        	info[i]=new ArrayList<>();
        }
        
        for(int i=0;i<n-1;i++) {
        	int start=train[i][0];
        	int dest =train[i][1];
        	info[start].add(dest);
        	info[dest].add(start);
        }
        answer = new int[2];
        answer[1] = Integer.MIN_VALUE;
        bfs(passenger);
        System.out.println(answer[0]+","+answer[1]);
        
        return answer;
    }

	private static void bfs(int[] passenger) {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(1, passenger[0]));
        
        while(!q.isEmpty()) {
        	int cur = q.peek().cur;
        	int saram = q.peek().saram;
        	System.out.println(cur+","+saram);
        	q.poll();
        	boolean flag=true;
        	for(int i=0;i<info[cur].size();i++) {
        		int next = info[cur].get(i);
        		if(visit[next]) continue;
        		visit[next]=true;
        		flag=false;
        		q.add(new Node(next, saram+passenger[next-1]));
        	}
        	if(flag) {
            	if(answer[1]<saram) {
            		answer[0]=cur;
            		answer[1]=saram;
            	} else if(answer[1]==saram) {
            		answer[0]=Math.max(cur, answer[0]);
            	}
        	}
        }
        
	}
	
}
