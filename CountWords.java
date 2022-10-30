package string;

public class CountWords {
	
	public static void countstring(String s) {
		int count = 1;
		for( int i=0; i<s.length(); i++) {
			if( s.charAt(i) == ' ' ) {
				count++;
			}
			
		}

		if( s.charAt(0) == ' ' ) {
			count--;
		}
		
		if(s.charAt(s.length()-1) == ' ' ) {
			count--;
		}
		
		System.out.println(count);
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String str = "My name is Dharmendra";
		countstring(str);

	}

}
