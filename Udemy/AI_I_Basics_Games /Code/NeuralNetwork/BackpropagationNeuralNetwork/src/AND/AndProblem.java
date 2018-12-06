package AND;

public class AndProblem {

	private int[][] trainingData;
	private int[] trainingTargets;
	private double[] weights;
	private double error = 1;
	
	public AndProblem(int[][] trainingData, int[] trainingTargets, double[] weights){
		this.trainingData = trainingData;
		this.trainingTargets = trainingTargets;
		this.weights = weights;
	}
	
	public void trainNetwork(){
		
		while( error != 0 ){
			
			for(int rowIndex=0;rowIndex<Constants.NUM_OF_DATA;++rowIndex){
				
				double weightedSum = 0;
				weightedSum = getWeightedSum(rowIndex, weightedSum);
				
				int outputValue = activationFunction(weightedSum);
				
				error = this.trainingTargets[rowIndex] - outputValue;
				
				// update the weights
				for(int j=0;j<this.weights.length;++j){
					this.weights[j] += Constants.LEARNING_RATE * error * trainingData[rowIndex][j];
				}	
			}	
			
			System.out.println("Edge weights are: " + weights[0]+" - " + weights[1]);
		}
		
		System.out.println("Final edge weights are: " + weights[0]+"-"+weights[1]);
	}

	private int activationFunction(double weightedSum) {
		
		if( weightedSum >= Constants.THREASHOLD ){
			return 1;
		}
		
		return 0;
	}

	private double getWeightedSum(int index, double weightedSum) {
		
		for(int j=0;j<Constants.NUM_OF_FEATURES;++j){
			weightedSum = weightedSum + trainingData[index][j] * weights[j];
		}
		
		return weightedSum;
	}
}
