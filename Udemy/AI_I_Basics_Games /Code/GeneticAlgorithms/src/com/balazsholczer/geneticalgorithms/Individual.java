package com.balazsholczer.geneticalgorithms;
import java.util.Random;


public class Individual {

	private int[] genes;
	private int fitness = 0;
	private Random randomGenerator;
	
	public Individual() {
		this.genes = new int[Constants.GENE_LENGTH];
		this.randomGenerator = new Random();
	}

	public void generateIndividual() {
		for (int i = 0; i < Constants.GENE_LENGTH; ++i) {
			int gene = randomGenerator.nextInt(10);			
			genes[i] = gene;
		}
	}

	public int getFitness() {

		if (this.fitness == 0) {

			for (int i = 0; i < Constants.GENE_LENGTH; ++i) {
				if ( getGene(i) == Constants.SOLUTION_SEQUENCE[i] ) {
					this.fitness++;
				}
			}
		}

		return fitness;
	}

	public int getGene(int index) {
		return this.genes[index];
	}

	public void setGene(int index, int value) {
		this.genes[index] = value;
		this.fitness = 0;
	}

	@Override
	public String toString() {

		String geneString = "";

		for (int i = 0; i < Constants.GENE_LENGTH; i++) {
			geneString += getGene(i);
		}

		return geneString;
	}
}
