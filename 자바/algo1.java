import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class algo1 {

	static final String[] book = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	static StringTokenizer st;
	
	static class Pair{
		String word1;
		String word2;
		int num;
		public Pair(String word1,String word2,int num) {
			this.word1=word1;
			this.word2=word2;
			this.num=num;
		}
	} //두자리수 제한이므로 10의자리와 1의자리 글자를 받을 수 있는 클래스 생성
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken()); //시작 숫자
		int end = Integer.parseInt(st.nextToken()); //끝 숫자
		solve(start,end); 
	}

	private static void solve(int start, int end) {
		ArrayList<Pair> info = new ArrayList<>(); //숫자와 그에 해당되는 단어를 가지고 있는 Pair를 템플릿으로 하는 리스트
		
		for(int i=start;i<=end;i++) {
			if(i<10) {
				info.add(new Pair(book[i],"a",i)); //정수가 한자리면 10의 자리에 단어를 넣고 사전적으로 가장 빠른 a를 두번째에 넣는다.
			}
			else {
				int dec = i/10;
				int one = i-(dec*10);
				info.add(new Pair(book[dec], book[one], i));
			}
		}
		
		Collections.sort(info, new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				if(o1.word1.compareTo(o2.word1)<0) return -1;
				else if(o1.word1.compareTo(o2.word1)>0) return 1;
				else {
					if(o1.word2.compareTo(o2.word2)<0) return -1;
					else return 1;
				}
			}
		}); //사전순으로 10의자리 비교 후 같으면 1의자리 비교
		
		int index=0; int count=0;
		for(int i=start;i<=end;i++) {
			System.out.print(info.get(index++).num+" ");
			count++;
			if(count==10) {
				System.out.println();
				count=0;
			}
		} //정렬된 어레이리스트 출력
		
	}

}
