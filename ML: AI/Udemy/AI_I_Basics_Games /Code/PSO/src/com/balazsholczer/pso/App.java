package com.balazsholczer.pso;

public class App {

	public static void main(String[] args) {
		
		ParticleSwarm algorithm = new ParticleSwarm();
		algorithm.solve();
		algorithm.showSolution();
	}
}
