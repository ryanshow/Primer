
public class Primer {
	public static void main(String[] args) {
		int numprimes = 1000;

		if (args.length >= 1) {
			numprimes = Integer.parseInt(args[0]);
		}

		int primelist[] = new int[numprimes];
		
		primelist[0] = 2;

		int x = 1, c = 1;

		while (c < numprimes) {
			x += 2;
			
			boolean isPrime = true;
			double root = Math.sqrt(x);
			int iter = 0;
			while (primelist[iter] <= root) {
				if (x%primelist[iter] == 0) {
					isPrime = false;
					break;
				}
				iter++;
			}

			if (isPrime) {
				primelist[c] = x;
				c++;
			}
		}

		for (int prime : primelist) {
			System.out.print(prime + ", ");
		}
		System.out.println();
	}
}
