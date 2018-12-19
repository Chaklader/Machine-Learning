package AND;

public class App {

	public static void main(String[] args) {

		double[] weights = { 0 , 0 };
		int[][] trainingData = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };
		int[] trainingTargets = { 0, 0, 0, 1 };
		
		AndProblem problem = new AndProblem(trainingData, trainingTargets, weights);
		problem.trainNetwork();
		
	}
}
