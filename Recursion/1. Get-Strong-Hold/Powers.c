public class Powers {

	public static void main(String[] args) {
		
		double x = 4;
		int n = 8;
		double res = Pow(x,n);
		System.out.println("ANS: " + res);

	}
	
	public static double Pow(double x, int n) {
		double ans = 1.0;
		int N = n;
		
		if(N<0) {
			N *= -1;
		}
		
		while(N>0) {
			if(N%2 == 0) {
				x *= x;
				N /= 2;
			}else {
				ans *= x;
				N -= 1;
			}
		}
		
		if(N < 0) {
			ans = 1/ans;
		}
		
		return ans;
	}

}

