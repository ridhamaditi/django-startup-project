import java.util.Scanner;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;

public class P2_wordCount {
	public static void main(String[] args) throws IOException {

		LineNumberReader countLine = new LineNumberReader(new FileReader("wordCount.txt"));
		while (countLine.skip(Long.MAX_VALUE) > 0) {
		}

		File file = new File("wordCount.txt");
		Scanner sc = new Scanner(file);

		String programString = "";
		String letter = "";

		String nextword;

		int vovelCount = 0;

		while (sc.hasNextLine()) {
			nextword= sc.next();

			letter = letter + nextword;
			programString = programString + nextword+ " ";
		}

		String[] splitwords = programString.split(" ");
		String[] splitLetters = letter.split("");

		for (int i = 0; i < splitLetters.length; i++) {
			if (splitLetters[i].matches("[aeiouAEIOU]"))
				vovelCount++;
		}

		System.out.println(programString);
		System.out.println();

		System.out.println("Vovels are 		: " + vovelCount);
		System.out.println("Consonants are 		: " + (splitLetters.length - vovelCount));
		System.out.println("Letters are 		: " + splitLetters.length);
		System.out.println("word are 		: " + splitwords.length);
		System.out.println("Lines are 		: " + (countLine.getLineNumber() + 1));

		countLine.close();
		sc.close();
	}
}