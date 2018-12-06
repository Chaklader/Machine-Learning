
public enum Player {
	
	COMPUTER("X"), USER("O"), NONE("-");
	
	private Player(String text){
		this.text = text;
	}

	private final String text;
	
	public String toString(){
		return text;
	}
}
