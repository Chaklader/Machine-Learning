package com.balazsholczer.tsp;

public class SimulatedAnnealing {

	private SingleTour best;
	
	public void simulation() {
		
		double temperature = 10000;
		double coolingRate = 0.003;
		
		SingleTour currentSolution = new SingleTour();
		currentSolution.generateIndividual();
		
		System.out.println("Initial solution distance: " + currentSolution.getDistance());
		
		best = new SingleTour(currentSolution.getTour());
		
		while ( temperature > 1 ) {
			
			SingleTour newSolution = new SingleTour(currentSolution.getTour());
			
			int randomIndex1 = (int) (newSolution.getTourSize() * Math.random());
			City city1 = newSolution.getCity(randomIndex1);
			
			int randomIndex2 = (int) (newSolution.getTourSize() * Math.random());
			City city2 = newSolution.getCity(randomIndex2);
			
			newSolution.setCity(randomIndex2, city1);
			newSolution.setCity(randomIndex1, city2);
			
			double currentEnergy = currentSolution.getDistance();
			double neighbourEnergy = newSolution.getDistance();
			
			if( acceptanceProbability(currentEnergy, neighbourEnergy, temperature) > Math.random() )
				currentSolution = new SingleTour(newSolution.getTour());
			
			if( currentSolution.getDistance() < best.getDistance())
				best = new SingleTour(currentSolution.getTour());
			
			temperature *= 1-coolingRate;
		}
		
	}
	
	public SingleTour getBest() {
		return best;
	}

	private double acceptanceProbability(double currentEnergy, double neighbourEnergy, double temperature) {
		
		if( neighbourEnergy < currentEnergy )
			return 1;
		
		return Math.exp((currentEnergy-neighbourEnergy)/temperature);
		
	}
}
