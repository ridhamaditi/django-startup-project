import java.util.Scanner;

public class P5_removeLeftRecursion {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter Grammer [ A->Ax/b ] : ");

		String enteredGrammer = sc.nextLine();
		String[] splittedGrammer = enteredGrammer.split("->");
		String[] splittedRHSGrammer = splittedGrammer[1].split("/");

		String[] beta = new String[10];
		int j = 0;
		String[] alpha = new String[10];
		int k = 0;

		for (int i = 0; i < splittedRHSGrammer.length; i++) {
			if (splittedGrammer[0].charAt(0) == splittedRHSGrammer[i].charAt(0)) {
				alpha[k] = splittedRHSGrammer[i].substring(1);
				k++;
			} else {
				beta[j] = splittedRHSGrammer[i];
				j++;
			}
		}

		System.out.println("\nAns:");
		System.out.print(splittedGrammer[0].charAt(0) + "->" + beta[0] + splittedGrammer[0].charAt(0) + "'");
		for (int i = 1; i < j; i++) {
			System.out.print("/" + beta[i] + splittedGrammer[0].charAt(0) + "'");
		}

		System.out.print("\n" + splittedGrammer[0].charAt(0) + "'->" + alpha[0] + splittedGrammer[0].charAt(0) + "'");
		for (int i = 1; i < k; i++) {
			System.out.print("/" + alpha[i] + splittedGrammer[0].charAt(0) + "'");
		}

		System.out.print("/^\n\n");
	}
	// A->Am/An/x/y/z
}