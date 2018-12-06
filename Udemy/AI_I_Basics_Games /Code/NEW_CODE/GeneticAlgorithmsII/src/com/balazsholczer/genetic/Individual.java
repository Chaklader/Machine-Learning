package com.balazsholczer.genetic;

import java.util.Random;

public class Individual {

	private int[] genes;
	private int fitness;
	private Random randomGenerator;
	
	public Individual() {
		this.genes = new int[Constants.CHROMOSOME_LENGTH];
		this.randomGenerator = new Random();
	}
	
	public void generateIndividual() {
		for(int i=0;i<Constants.CHROMOSOME_LENGTH;++i) {
			int gene = randomGenerator.nextInt(2);
			genes[i] = gene;
		}
	}
	
	public double f(double x) {
		return ((x-2)*(x-2))+3;
	}
	
	public double genesToDouble() {
		
		int base = 1;
		double geneInDouble = 0;
		
		for(int i=0;i<Constants.GENE_LENGTH;++i) {
			if( this.genes[i] == 1 )
				geneInDouble += base;
		
			base = base * 2;
		}
		
		// 2 pow 10 (gene_length) = 1024 -> this is how we transform it into the interval we are interested in
		// we have [0,10] interval so we divide by 10 to make the transformation
		geneInDouble = geneInDouble / 102.4f;
		
		return geneInDouble;
	}
	
	public double getFitness() {
		double geneInDouble = genesToDouble();
		return f(geneInDouble);
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
		String s = "";
		
		for(int i=0;i<Constants.CHROMOSOME_LENGTH;++i)
			s+=getGene(i);
	
		return s;
	}
}
