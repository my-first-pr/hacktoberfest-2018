import java.util.ArrayList;
import java.util.Scanner;

public class getBoardPath {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
        System.out.println("Enter Current Position:");
        int n1= scn.nextInt();
        System.out.println("Enter Destination Position:");
        int n2= scn.nextInt();
		System.out.println(GetBoardPath(n1, n2));

	}

	public static ArrayList<String> GetBoardPath(int curr, int end) {
// Returns all snake & ladder board paths from curr to end
		if (curr == end) {
			ArrayList<String> basePositive = new ArrayList<>();
			basePositive.add("\n");
			return basePositive;
		}
		if (curr > end) {
			ArrayList<String> baseNegative = new ArrayList<>();
			return baseNegative;
		}
		ArrayList<String> MyResult = new ArrayList<>();
		for (int dice = 1; dice <= 6; dice++) {
			ArrayList<String> RecResult = GetBoardPath(curr + dice, end);
			for (String RecResultString : RecResult) {
				MyResult.add(dice + RecResultString);
			}
		}
		return MyResult;
	}

}