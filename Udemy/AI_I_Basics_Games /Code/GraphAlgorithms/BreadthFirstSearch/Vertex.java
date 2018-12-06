package BreadthFirstSearch;

import java.util.ArrayList;
import java.util.List;

public class Vertex {

	private int data;
	private boolean visited;
	private List<Vertex> neighbourList;
	
	public Vertex(int data){
		this.data=data;
		this.neighbourList = new ArrayList<>();
	}

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public boolean isVisited() {
		return visited;
	}

	public void setVisited(boolean visited) {
		this.visited = visited;
	}

	public List<Vertex> getNeighbourList() {
		return neighbourList;
	}

	public void addNeighbour(Vertex neighbour) {
		this.neighbourList.add(neighbour);
	}
	
	@Override
	public String toString() {
		return ""+this.data;
	}
}
