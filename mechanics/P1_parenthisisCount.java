import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class P1_parenthisisCount {

	static char chArray[] = new char[50];
	static int top = -1;
	private static FileInputStream fin;

	public static void main(String[] args) throws FileNotFoundException, IOException {

		fin = new FileInputStream("parenthisis.txt");
		int nextChar;
		boolean flag = true;

		while ((nextChar = fin.read()) != -1 && flag) {
			if ((char) nextChar == '{' || (char) nextChar == '[' || (char) nextChar == '(') {
				push((char) nextChar);
			}

			if ((char) nextChar == ']' || (char) nextChar == ')' || (char) nextChar == '}') {

				if (top >= 0) {
					if ((char) nextChar == '}') {
						if (pop() != '{')
							flag = false;
					}

					if ((char) nextChar == ']') {
						if (pop() != '[')
							flag = false;
					}

					if ((char) nextChar == ')') {
						if (pop() != '(')
							flag = false;
					}

				} else {
					flag = false;
				}
			}
		}

		if (flag && top == -1)
			System.out.println("Success");
		else
			System.out.println("Fail");
	}

	static void push(char inChar) {
		chArray[++top] = inChar;
	}

	static char pop() {
		return chArray[top--];
	}
}
